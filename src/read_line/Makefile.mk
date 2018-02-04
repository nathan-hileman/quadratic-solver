CC = gcc

CFLAGS = -Wall -pedantic -std=c99

all: read_line

debug: CCFLAGS += DDEBUG -g
debug: read_line

read_line:
    $(CC) $(CCFLAGS) read_line.c -o t