CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c11

OBJS = $(SRCS:.c=.o)

.PHONY: all test run clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test:
	@$(MAKE) -C test run

run:
	./$(TARGET)

clean:
	$(MAKE) -C test clean
	rm -f $(TARGET) $(OBJS)