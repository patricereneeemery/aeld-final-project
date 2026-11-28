#include "network.h"

#include <arpa/inet.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <stdio.h>
#include <string.h>

int get_ip_address(
    const char *interface,
    char *ip_address,
    size_t size)
{
    struct ifaddrs *ifaddr;
    struct ifaddrs *ifa;

    if (getifaddrs(&ifaddr) == -1)
    {
        return -1;
    }

    for (ifa = ifaddr;
         ifa != NULL;
         ifa = ifa->ifa_next)
    {
        if ((ifa->ifa_addr != NULL) &&
            (ifa->ifa_addr->sa_family == AF_INET) &&
            (strcmp(ifa->ifa_name,
                    interface) == 0))
        {
            struct sockaddr_in *addr =
                (struct sockaddr_in *)
                    ifa->ifa_addr;

            inet_ntop(AF_INET,
                      &addr->sin_addr,
                      ip_address,
                      size);

            freeifaddrs(ifaddr);

            return 0;
        }
    }

    freeifaddrs(ifaddr);

    strncpy(ip_address,
            "N/A",
            size);

    return -1;
}

int get_interface_status(
    const char *interface,
    char *status,
    size_t size)
{
    struct ifaddrs *ifaddr;
    struct ifaddrs *ifa;

    if (getifaddrs(&ifaddr) == -1)
    {
        return -1;
    }

    for (ifa = ifaddr;
         ifa != NULL;
         ifa = ifa->ifa_next)
    {
        if ((ifa->ifa_name != NULL) &&
            (strcmp(ifa->ifa_name,
                    interface) == 0))
        {
            if (ifa->ifa_flags & IFF_UP)
            {
                strncpy(status,
                        "UP",
                        size);
            }
            else
            {
                strncpy(status,
                        "DOWN",
                        size);
            }

            freeifaddrs(ifaddr);

            return 0;
        }
    }

    freeifaddrs(ifaddr);

    strncpy(status,
            "UNKNOWN",
            size);

    return -1;
}

unsigned long long get_rx_bytes(
    const char *interface)
{
    FILE *fp;

    char line[512];

    fp = fopen("/proc/net/dev",
               "r");

    if (fp == NULL)
    {
        return 0;
    }

    while (fgets(line,
                 sizeof(line),
                 fp) != NULL)
    {
        char if_name[32];

        unsigned long long rx_bytes;

        if (sscanf(line,
                   " %31[^:]: %llu",
                   if_name,
                   &rx_bytes) == 2)
        {
            if (strcmp(if_name,
                       interface) == 0)
            {
                fclose(fp);

                return rx_bytes;
            }
        }
    }

    fclose(fp);

    return 0;
}

unsigned long long get_tx_bytes(
    const char *interface)
{
    FILE *fp;

    char line[512];

    fp = fopen("/proc/net/dev",
               "r");

    if (fp == NULL)
    {
        return 0;
    }

    while (fgets(line,
                 sizeof(line),
                 fp) != NULL)
    {
        char if_name[32];

        unsigned long long rx_bytes;
        unsigned long long tx_bytes;

        if (sscanf(
                line,
                " %31[^:]: %llu %*u %*u %*u %*u %*u %*u %*u %llu",
                if_name,
                &rx_bytes,
                &tx_bytes) == 3)
        {
            if (strcmp(if_name,
                       interface) == 0)
            {
                fclose(fp);

                return tx_bytes;
            }
        }
    }

    fclose(fp);

    return 0;
}
