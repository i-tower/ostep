CC = gcc
CFLAGS = -Wall -Wextra -Werror  -Og -ggdb

%: %.c
	$(CC) $(CFLAGS) -o $@ $<