#include "alerts.h"
#include "monitor.h"

#include <stdio.h>
#include <time.h>

#define ALERT_LOGFILE "aesd-alerts.log"

static int cpu_alert_active = 0;
static int memory_alert_active = 0;
static int disk_alert_active = 0;

static void write_alert(const char *message)
{
    FILE *fp;

    time_t current_time;

    struct tm *time_info;

    char timestamp[64];

    fp = fopen(ALERT_LOGFILE, "a");

    if (fp == NULL)
    {
        return;
    }

    current_time = time(NULL);

    time_info = localtime(&current_time);

    strftime(timestamp,
             sizeof(timestamp),
             "%Y-%m-%d %H:%M:%S",
             time_info);

    fprintf(fp,
            "%s ALERT: %s\n",
            timestamp,
            message);

    fclose(fp);
}

int check_alerts(void)
{
    double cpu;
    double memory;
    double disk;

    char message[128];

    cpu = get_cpu_usage();

    memory = get_memory_usage_percent();

    disk = get_disk_usage_percent();

    /* CPU Alert */

    if ((cpu > CPU_THRESHOLD) &&
        (cpu_alert_active == 0))
    {
        snprintf(message,
                 sizeof(message),
                 "CPU threshold exceeded "
                 "(Current=%.2f Threshold=%.2f)",
                 cpu,
                 CPU_THRESHOLD);

        write_alert(message);

        cpu_alert_active = 1;
    }

    if ((cpu <= CPU_THRESHOLD) &&
        (cpu_alert_active == 1))
    {
        snprintf(message,
                 sizeof(message),
                 "CPU utilization returned to normal "
                 "(Current=%.2f Threshold=%.2f)",
                 cpu,
                 CPU_THRESHOLD);

        write_alert(message);

        cpu_alert_active = 0;
    }

    /* Memory Alert */

    if ((memory > MEMORY_THRESHOLD) &&
        (memory_alert_active == 0))
    {
        snprintf(message,
                 sizeof(message),
                 "Memory threshold exceeded "
                 "(Current=%.2f Threshold=%.2f)",
                 memory,
                 MEMORY_THRESHOLD);

        write_alert(message);

        memory_alert_active = 1;
    }

    if ((memory <= MEMORY_THRESHOLD) &&
        (memory_alert_active == 1))
    {
        snprintf(message,
                 sizeof(message),
                 "Memory utilization returned to normal "
                 "(Current=%.2f Threshold=%.2f)",
                 memory,
                 MEMORY_THRESHOLD);

        write_alert(message);

        memory_alert_active = 0;
    }

    /* Disk Alert */

    if ((disk > DISK_THRESHOLD) &&
        (disk_alert_active == 0))
    {
        snprintf(message,
                 sizeof(message),
                 "Disk threshold exceeded "
                 "(Current=%.2f Threshold=%.2f)",
                 disk,
                 DISK_THRESHOLD);

        write_alert(message);

        disk_alert_active = 1;
    }

    if ((disk <= DISK_THRESHOLD) &&
        (disk_alert_active == 1))
    {
        snprintf(message,
                 sizeof(message),
                 "Disk utilization returned to normal "
                 "(Current=%.2f Threshold=%.2f)",
                 disk,
                 DISK_THRESHOLD);

        write_alert(message);

        disk_alert_active = 0;
    }

    return 0;
}

int cpu_alert_is_active(void)
{
    return cpu_alert_active;
}

int memory_alert_is_active(void)
{
    return memory_alert_active;
}

int disk_alert_is_active(void)
{
    return disk_alert_active;
}
