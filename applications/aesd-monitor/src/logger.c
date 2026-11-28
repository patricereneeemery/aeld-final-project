#include "logger.h"
#include "monitor.h"
#include "network.h"

#include <stdio.h>
#include <time.h>

#define LOGFILE "aesd-monitor.log"

int log_metrics(void)
{
    FILE *fp;

    time_t current_time;

    struct tm *time_info;

    char timestamp[64];

    char hostname[64];

    char wlan_status[32];
    char wlan_ip[64];

    char eth_status[32];
    char eth_ip[64];

    current_time = time(NULL);

    time_info = localtime(&current_time);

    strftime(timestamp,
             sizeof(timestamp),
             "%Y-%m-%d %H:%M:%S",
             time_info);

    if (get_hostname_value(hostname,
                           sizeof(hostname)) != 0)
    {
        snprintf(hostname,
                 sizeof(hostname),
                 "UNKNOWN");
    }

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

    fp = fopen(LOGFILE, "a");

    if (fp == NULL)
    {
        return -1;
    }

    fprintf(
        fp,
        "%s "
        "HOST=%s "
        "CPU=%.2f "
        "MEMORY=%.2f "
        "DISK=%.2f "
        "LOAD=%.2f "
        "UPTIME=%d "
        "WLAN0_STATUS=%s "
        "WLAN0_IP=%s "
        "WLAN0_RX=%llu "
        "WLAN0_TX=%llu "
        "ETH0_STATUS=%s "
        "ETH0_IP=%s "
        "ETH0_RX=%llu "
        "ETH0_TX=%llu\n",
        timestamp,
        hostname,
        get_cpu_usage(),
        get_memory_usage_percent(),
        get_disk_usage_percent(),
        get_load_average(),
        get_uptime_seconds(),
        wlan_status,
        wlan_ip,
        get_rx_bytes("wlan0"),
        get_tx_bytes("wlan0"),
        eth_status,
        eth_ip,
        get_rx_bytes("eth0"),
        get_tx_bytes("eth0"));

    fclose(fp);

    return 0;
}
