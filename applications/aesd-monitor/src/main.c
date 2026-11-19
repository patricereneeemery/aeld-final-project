#include <stdio.h>

#include "server.h"

int main(void)
{
    printf("aesd-monitor starting\n");

    return server_run(9000);
}
