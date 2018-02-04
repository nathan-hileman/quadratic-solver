CC = gcc

CFLAGS = -Wall -pedantic -std=c99

all: read_line_test

debug: CCFLAGS += DDEBUG -g
debug: read_line_test

read_line_test:
    $(CC) $(CCFLAGS) read_line_test.c -o t
