CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: server

server: src/server.c
	$(CC) $(CFLAGS) -o server src/server.c

clean:
	rm -f server
