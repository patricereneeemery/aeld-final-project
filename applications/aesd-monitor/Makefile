CC=gcc

CFLAGS=-Wall -Wextra -Werror -g

TARGET=aesd-monitor

SRCS=src/main.c \
     src/server.c \
     src/monitor.c \
     src/gpio.c

OBJS=$(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean
