#ifndef SERVER_H
#define SERVER_H

void *client_handler(void *arg);

int server_run(int port);

#endif
