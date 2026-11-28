#ifndef ALERTS_H
#define ALERTS_H

#define CPU_THRESHOLD      80.0
#define MEMORY_THRESHOLD   90.0
#define DISK_THRESHOLD     95.0

int check_alerts(void);

int cpu_alert_is_active(void);
int memory_alert_is_active(void);
int disk_alert_is_active(void);

#endif
