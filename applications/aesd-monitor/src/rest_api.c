#include "rest_api.h"
#include "monitor.h"
#include "network.h"

#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define REST_PORT 8080
#define BUFFER_SIZE 4096

static void send_system_response(
    int client_fd)
{
    char hostname[64];

    char response[4096];

    get_hostname_value(
        hostname,
        sizeof(hostname));

    snprintf(
        response,
        sizeof(response),
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: application/json\r\n"
        "\r\n"
        "{"
        "\"system\":{"
        "\"hostname\":\"%s\""
        "},"
        "\"metrics\":{"
        "\"cpu\":%.2f,"
        "\"memory\":%.2f,"
        "\"disk\":%.2f,"
        "\"load\":%.2f,"
        "\"uptime\":%d"
        "}"
        "}",
        hostname,
        get_cpu_usage(),
        get_memory_usage_percent(),
        get_disk_usage_percent(),
        get_load_average(),
        get_uptime_seconds());

    send(
        client_fd,
        response,
        strlen(response),
        0);
}

static void send_network_response(
    int client_fd)
{
    char wlan_status[32];
    char wlan_ip[64];

    char eth_status[32];
    char eth_ip[64];

    char response[4096];

    get_interface_status(
        "wlan0",
        wlan_status,
        sizeof(wlan_status));

    get_ip_address(
        "wlan0",
        wlan_ip,
        sizeof(wlan_ip));

    get_interface_status(
        "eth0",
        eth_status,
        sizeof(eth_status));

    get_ip_address(
        "eth0",
        eth_ip,
        sizeof(eth_ip));

    snprintf(
        response,
        sizeof(response),
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: application/json\r\n"
        "\r\n"
        "{"
        "\"network\":{"
        "\"wlan0\":{"
        "\"status\":\"%s\","
        "\"ip\":\"%s\","
        "\"rx_bytes\":%llu,"
        "\"tx_bytes\":%llu"
        "},"
        "\"eth0\":{"
        "\"status\":\"%s\","
        "\"ip\":\"%s\","
        "\"rx_bytes\":%llu,"
        "\"tx_bytes\":%llu"
        "}"
        "}"
        "}",
        wlan_status,
        wlan_ip,
        get_rx_bytes("wlan0"),
        get_tx_bytes("wlan0"),
        eth_status,
        eth_ip,
        get_rx_bytes("eth0"),
        get_tx_bytes("eth0"));

    send(
        client_fd,
        response,
        strlen(response),
        0);
}

static void send_alerts_response(
    int client_fd)
{
    FILE *fp;

    char line[256];

    char alerts[4096];

    char response[8192];

    int first = 1;

    fp = fopen(
        "aesd-alerts.log",
        "r");

    if (fp == NULL)
    {
        snprintf(
            response,
            sizeof(response),
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: application/json\r\n"
            "\r\n"
            "{"
            "\"alerts\":[]"
            "}");

        send(
            client_fd,
            response,
            strlen(response),
            0);

        return;
    }

    alerts[0] = '\0';

    strcat(
        alerts,
        "{\"alerts\":[");

    while (fgets(
               line,
               sizeof(line),
               fp) != NULL)
    {
        line[strcspn(
                 line,
                 "\n")] = '\0';

        if (!first)
        {
            strcat(
                alerts,
                ",");
        }

        strcat(
            alerts,
            "\"");

        strcat(
            alerts,
            line);

        strcat(
            alerts,
            "\"");

        first = 0;
    }

    strcat(
        alerts,
        "]}");

    fclose(fp);

    snprintf(
        response,
        sizeof(response),
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: application/json\r\n"
        "\r\n"
        "%s",
        alerts);

    send(
        client_fd,
        response,
        strlen(response),
        0);
}

static void send_not_found(
    int client_fd)
{
    const char *response =
        "HTTP/1.1 404 Not Found\r\n"
        "Content-Type: text/plain\r\n"
        "\r\n"
        "Endpoint Not Found\n";

    send(
        client_fd,
        response,
        strlen(response),
        0);
}

static void send_file(
    int client_fd,
    const char *filename,
    const char *content_type)
{
    FILE *fp;

    long size;

    char *buffer;

    char header[256];

    fp = fopen(
        filename,
        "rb");

    if (fp == NULL)
    {
        send_not_found(
            client_fd);

        return;
    }

    fseek(
        fp,
        0,
        SEEK_END);

    size =
        ftell(fp);

    rewind(
        fp);

    buffer =
        malloc(size + 1);

    fread(
        buffer,
        1,
        size,
        fp);

    buffer[size] = '\0';

    fclose(fp);

    snprintf(
        header,
        sizeof(header),
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: %s\r\n"
        "\r\n",
        content_type);

    send(
        client_fd,
        header,
        strlen(header),
        0);

    send(
        client_fd,
        buffer,
        size,
        0);

    free(
        buffer);
}

/* Dispatcher */
static void handle_request(
    int client_fd,
    const char *request)
{
    if (strstr(
            request,
            "GET / ") != NULL)
    {
        send_file(
            client_fd,
            "dashboard/index.html",
            "text/html");
    }
    else if (strstr(
                 request,
                 "GET /index.html") != NULL)
    {
        send_file(
            client_fd,
            "dashboard/index.html",
            "text/html");
    }
    else if (strstr(
                 request,
                 "GET /dashboard.js") != NULL)
    {
        send_file(
            client_fd,
            "dashboard/dashboard.js",
            "application/javascript");
    }
    else if (strstr(
                 request,
                 "GET /style.css") != NULL)
    {
        send_file(
            client_fd,
            "dashboard/style.css",
            "text/css");
    }
    else if (strstr(
                 request,
                 "GET /api/system") != NULL)
    {
        send_system_response(
            client_fd);
    }
    else if (strstr(
                 request,
                 "GET /api/network") != NULL)
    {
        send_network_response(
            client_fd);
    }
    else if (strstr(
                 request,
                 "GET /api/alerts") != NULL)
    {
        send_alerts_response(
            client_fd);
    }
    else
    {
        send_not_found(
            client_fd);
    }
}

void *rest_api_thread(
    void *arg)
{
    int server_fd;

    struct sockaddr_in server_addr;

    char buffer[BUFFER_SIZE];

    (void)arg;

    server_fd =
        socket(
            AF_INET,
            SOCK_STREAM,
            0);

    if (server_fd < 0)
    {
        perror(
            "REST socket");

        return NULL;
    }

    memset(
        &server_addr,
        0,
        sizeof(server_addr));

    server_addr.sin_family =
        AF_INET;

    server_addr.sin_port =
        htons(
            REST_PORT);

    server_addr.sin_addr.s_addr =
        INADDR_ANY;

    if (bind(
            server_fd,
            (struct sockaddr *)&server_addr,
            sizeof(server_addr))
        < 0)
    {
        perror(
            "REST bind");

        close(
            server_fd);

        return NULL;
    }

    if (listen(
            server_fd,
            5)
        < 0)
    {
        perror(
            "REST listen");

        close(
            server_fd);

        return NULL;
    }

    printf(
        "REST API listening on port %d\n",
        REST_PORT);

    while (1)
    {
        int client_fd;

        memset(
            buffer,
            0,
            sizeof(buffer));

        client_fd =
            accept(
                server_fd,
                NULL,
                NULL);

        if (client_fd < 0)
        {
            continue;
        }

        recv(
            client_fd,
            buffer,
            sizeof(buffer) - 1,
            0);

        handle_request(
            client_fd,
            buffer);

        close(
            client_fd);
    }

    return NULL;
}
