#include "server.h"
#include "monitor.h"

#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void *client_handler(void *arg)
{
    int client_fd = *(int *)arg;
    free(arg);

    char buffer[BUFFER_SIZE];

    while (1)
    {
        int bytes_received;

        memset(buffer, 0, sizeof(buffer));

        bytes_received = recv(client_fd,
                              buffer,
                              sizeof(buffer) - 1,
                              0);

        if (bytes_received <= 0)
        {
            break;
        }

        buffer[strcspn(buffer, "\r\n")] = '\0';

	if (strncmp(buffer, "QUIT", 4) == 0)
	{
    	const char *response = "GOODBYE\n";

    	send(client_fd,
            response,
            strlen(response),
            0);

    	   shutdown(client_fd, SHUT_RDWR);

    	   break;
	}
        else if (strncmp(buffer, "INFO", 4) == 0)
        {
            char hostname[64];
            char response[128];

            get_hostname_value(hostname,
                               sizeof(hostname));

            snprintf(response,
                     sizeof(response),
                     "HOSTNAME=%s\n"
                     "VERSION=1.0\n",
                     hostname);

            send(client_fd,
                 response,
                 strlen(response),
                 0);
        }
        else if (strncmp(buffer, "STATUS", 6) == 0)
        {
            char hostname[64];
            char response[512];

            get_hostname_value(hostname,
                               sizeof(hostname));

            snprintf(
                response,
                sizeof(response),
                "HOSTNAME=%s\n"
                "CPU=%.2f\n"
                "MEMORY=%.2f\n"
                "DISK=%.2f\n"
                "LOAD=%.2f\n"
                "UPTIME=%d\n",
                hostname,
                get_cpu_usage(),
                get_memory_usage_percent(),
                get_disk_usage_percent(),
                get_load_average(),
                get_uptime_seconds());

            send(client_fd,
                 response,
                 strlen(response),
                 0);
        }
        else if (strncmp(buffer, "CPU", 3) == 0)
        {
            char response[64];

            snprintf(response,
                     sizeof(response),
                     "CPU=%.2f\n",
                     get_cpu_usage());

            send(client_fd,
                 response,
                 strlen(response),
                 0);
        }
        else if (strncmp(buffer, "MEMORY", 6) == 0)
        {
            char response[64];

            snprintf(response,
                     sizeof(response),
                     "MEMORY=%.2f\n",
                     get_memory_usage_percent());

            send(client_fd,
                 response,
                 strlen(response),
                 0);
        }
        else if (strncmp(buffer, "DISK", 4) == 0)
        {
            char response[64];

            snprintf(response,
                     sizeof(response),
                     "DISK=%.2f\n",
                     get_disk_usage_percent());

            send(client_fd,
                 response,
                 strlen(response),
                 0);
        }
        else if (strncmp(buffer, "LOAD", 4) == 0)
        {
            char response[64];

            snprintf(response,
                     sizeof(response),
                     "LOAD=%.2f\n",
                     get_load_average());

            send(client_fd,
                 response,
                 strlen(response),
                 0);
        }
        else if (strncmp(buffer, "UPTIME", 6) == 0)
        {
            char response[64];

            snprintf(response,
                     sizeof(response),
                     "UPTIME=%d\n",
                     get_uptime_seconds());

            send(client_fd,
                 response,
                 strlen(response),
                 0);
        }
        else if (strncmp(buffer, "HOSTNAME", 8) == 0)
        {
            char hostname[64];
            char response[128];

            get_hostname_value(hostname,
                               sizeof(hostname));

            snprintf(response,
                     sizeof(response),
                     "HOSTNAME=%s\n",
                     hostname);

            send(client_fd,
                 response,
                 strlen(response),
                 0);
        }
        else
        {
            const char *response =
                "ERROR: Unknown command\n";

            send(client_fd,
                 response,
                 strlen(response),
                 0);
        }
    }

    close(client_fd);

    return NULL;
}

int server_run(int port)
{
    int server_fd;

    struct sockaddr_in server_addr;

    server_fd = socket(AF_INET,
                       SOCK_STREAM,
                       0);

    if (server_fd < 0)
    {
        perror("socket");
        return -1;
    }

    memset(&server_addr,
           0,
           sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_fd,
             (struct sockaddr *)&server_addr,
             sizeof(server_addr)) < 0)
    {
        perror("bind");
        close(server_fd);
        return -1;
    }

    if (listen(server_fd, 10) < 0)
    {
        perror("listen");
        close(server_fd);
        return -1;
    }

    printf("Listening on port %d\n",
           port);

    while (1)
    {
        pthread_t thread;

        int *client_fd =
            malloc(sizeof(int));

        *client_fd =
            accept(server_fd,
                   NULL,
                   NULL);

        if (*client_fd < 0)
        {
            perror("accept");

            free(client_fd);

            continue;
        }

        if (pthread_create(
                &thread,
                NULL,
                client_handler,
                client_fd) != 0)
        {
            perror("pthread_create");

            close(*client_fd);

            free(client_fd);

            continue;
        }

        pthread_detach(thread);
    }

    close(server_fd);

    return 0;
}
