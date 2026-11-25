#include "monitor_thread.h"

#include "alerts.h"
#include "logger.h"

#include <pthread.h>
#include <unistd.h>

void *monitoring_thread(void *arg)
{
    (void)arg;

    while (1)
    {
        log_metrics();

        check_alerts();

        sleep(60);
    }

    return NULL;
}
