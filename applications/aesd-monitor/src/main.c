#include <pthread.h>
#include <stdio.h>

#include "rest_api.h"
#include "network.h"
#include "alerts.h"
#include "logger.h"
#include "monitor_thread.h"
#include "server.h"

int main(void)
{
    pthread_t monitor_thread;
    pthread_t rest_thread;
    printf("aesd-monitor starting\n");

    char ip[64];
    char status[32];

    get_ip_address(
       "wlan0",
       ip,
       sizeof(ip));

    get_interface_status(
       "wlan0",
       status,
       sizeof(status));

/*
 * Network Monitoring Validation
 *
 * Uncomment during testing to verify:
 *
 * - Interface Status
 * - IP Address Detection
 * - RX Statistics
 * - TX Statistics
 */
//    printf("WLAN0 Status: %s\n", status);

//    printf("WLAN0 IP: %s\n", ip);

//    printf("RX Bytes: %llu\n", get_rx_bytes("wlan0"));

//    printf("TX Bytes: %llu\n", get_tx_bytes("wlan0"));

    pthread_create(
    &monitor_thread,
    NULL,
    monitoring_thread,
    NULL);

    pthread_create(
    &rest_thread,
    NULL,
    rest_api_thread,
    NULL);

    //log_metrics();

    //check_alerts();

    return server_run(9000);
}
