#include "server.h"
#include "monitor.h"

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int server_run(int port)
{
    int server_fd;
    int client_fd;
    struct sockaddr_in server_addr;

    char buffer[BUFFER_SIZE];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0)
    {
        perror("socket");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));

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

    if (listen(server_fd, 5) < 0)
    {
        perror("listen");
        close(server_fd);
        return -1;
    }

    printf("Listening on port %d\n", port);

    while (1)
    {
        client_fd = accept(server_fd, NULL, NULL);

        if (client_fd < 0)
        {
            perror("accept");
            continue;
        }

        memset(buffer, 0, sizeof(buffer));

        recv(client_fd, buffer, sizeof(buffer) - 1, 0);

	if (strncmp(buffer, "INFO", 4) == 0)
	{
	    char hostname[64];
	    char response[128];

	    gethostname(hostname, sizeof(hostname));

	    snprintf(
	        response,
	        sizeof(response),
	        "HOSTNAME=%s\nVERSION=0.1\n",
	        hostname);

	    send(client_fd,
	         response,
	         strlen(response),
	         0);
	}
	else if (strncmp(buffer, "STATUS", 6) == 0)
	{
    	    char response[256];

    	    snprintf(
            response,
            sizeof(response),
            "UPTIME=%d\nMEMAVAILABLE=%ld kB\n",
            get_uptime_seconds(),
            get_mem_available_kb());

        send(
            client_fd,
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

        close(client_fd);
    }

    close(server_fd);

    return 0;
}
