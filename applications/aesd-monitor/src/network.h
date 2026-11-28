#ifndef NETWORK_H
#define NETWORK_H

#include <stddef.h>

int get_ip_address(
    const char *interface,
    char *ip_address,
    size_t size);

int get_interface_status(
    const char *interface,
    char *status,
    size_t size);

unsigned long long get_rx_bytes(
    const char *interface);

unsigned long long get_tx_bytes(
    const char *interface);

#endif
