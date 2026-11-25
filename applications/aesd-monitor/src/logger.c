#include "logger.h"
#include "monitor.h"

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
        "UPTIME=%d\n",
        timestamp,
        hostname,
        get_cpu_usage(),
        get_memory_usage_percent(),
        get_disk_usage_percent(),
        get_load_average(),
        get_uptime_seconds());

    fclose(fp);

    return 0;
}
