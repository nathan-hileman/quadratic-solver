CC = gcc

CCFLAGS = -Wall -pedantic -std=c99

all: executable

debug: CCFLAGS += -DDEBUG -g
debug: executable

executable:
	$(CC) $(CCFLAGS) test.c -o t
