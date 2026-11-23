#ifndef MONITOR_H
#define MONITOR_H

int get_uptime_seconds(void);

long get_mem_available_kb(void);

double get_cpu_usage(void);

double get_memory_usage_percent(void);

int get_hostname_value(char *hostname, int size);

double get_load_average(void);

double get_disk_usage_percent(void);


#endif
