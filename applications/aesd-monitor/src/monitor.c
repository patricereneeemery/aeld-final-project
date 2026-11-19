#include "monitor.h"

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
