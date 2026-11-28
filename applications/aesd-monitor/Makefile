CC=gcc

CFLAGS=-Wall -Wextra -Werror -g -pthread

TARGET=aesd-monitor

SRCS=src/main.c \
     src/server.c \
     src/monitor.c \
     src/gpio.c \
     src/logger.c \
     src/alerts.c \
     src/monitor_thread.c \
     src/network.c \
     src/rest_api.c


OBJS=$(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -pthread -o $@ $^

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean
