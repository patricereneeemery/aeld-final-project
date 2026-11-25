#include <pthread.h>
#include <stdio.h>

#include "alerts.h"
#include "logger.h"
#include "monitor_thread.h"
#include "server.h"

int main(void)
{
    pthread_t monitor_thread;

    printf("aesd-monitor starting\n");

    pthread_create(
    &monitor_thread,
    NULL,
    monitoring_thread,
    NULL);

    //log_metrics();

    //check_alerts();

    return server_run(9000);
}
