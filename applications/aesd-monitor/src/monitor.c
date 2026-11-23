#include "monitor.h"

#include <sys/statvfs.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int get_uptime_seconds(void)
{
    FILE *fp;
    double uptime;

    fp = fopen("/proc/uptime", "r");

    if (fp == NULL)
    {
        return -1;
    }

    fscanf(fp, "%lf", &uptime);

    fclose(fp);

    return (int)uptime;
}

long get_mem_available_kb(void)
{
    FILE *fp;

    char label[64];
    long value;

    fp = fopen("/proc/meminfo", "r");

    if (fp == NULL)
    {
        return -1;
    }

    while (fscanf(fp, "%63s %ld", label, &value) == 2)
    {
        if (strcmp(label, "MemAvailable:") == 0)
        {
            fclose(fp);
            return value;
        }

        fscanf(fp, "%*s");
    }

    fclose(fp);

    return -1;
}

double get_cpu_usage(void)
{
    FILE *fp;

    unsigned long user;
    unsigned long nice;
    unsigned long system;
    unsigned long idle;

    unsigned long user2;
    unsigned long nice2;
    unsigned long system2;
    unsigned long idle2;

    unsigned long total1;
    unsigned long total2;

    unsigned long total_delta;
    unsigned long idle_delta;

    fp = fopen("/proc/stat","r");

    if(fp == NULL)
    {
        return -1;
    }

    fscanf(fp,
           "cpu %lu %lu %lu %lu",
           &user,
           &nice,
           &system,
           &idle);

    fclose(fp);

    sleep(1);

    fp = fopen("/proc/stat","r");

    if(fp == NULL)
    {
        return -1;
    }

    fscanf(fp,
           "cpu %lu %lu %lu %lu",
           &user2,
           &nice2,
           &system2,
           &idle2);

    fclose(fp);

    total1 = user + nice + system + idle;
    total2 = user2 + nice2 + system2 + idle2;

    total_delta = total2 - total1;
    idle_delta = idle2 - idle;

    return 100.0 * (total_delta - idle_delta) /
           total_delta;
}
int get_hostname_value(char *hostname,
                       int size)
{
    return gethostname(hostname,size);
}

double get_memory_usage_percent(void)
{
    FILE *fp;

    char label[64];

    long total = 0;
    long available = 0;
    long value;

    fp = fopen("/proc/meminfo","r");

    if(fp == NULL)
    {
        return -1;
    }

    while(fscanf(fp,
                 "%63s %ld",
                 label,
                 &value) == 2)
    {
        if(strcmp(label,
                  "MemTotal:") == 0)
        {
            total = value;
        }

        if(strcmp(label,
                  "MemAvailable:") == 0)
        {
            available = value;
        }

        fscanf(fp,"%*s");
    }

    fclose(fp);

    return ((double)(total - available)
            / total) * 100.0;
}


double get_load_average(void)
{
    double load;

    FILE *fp;

    fp = fopen("/proc/loadavg", "r");

    if (fp == NULL)
    {
        return -1;
    }

    fscanf(fp, "%lf", &load);

    fclose(fp);

    return load;
}

double get_disk_usage_percent(void)
{
    struct statvfs fs;

    unsigned long total;
    unsigned long available;

    if (statvfs("/", &fs) != 0)
    {
        return -1;
    }

    total = fs.f_blocks * fs.f_frsize;

    available = fs.f_bavail * fs.f_frsize;

    return ((double)(total - available) /
            total) * 100.0;
}
