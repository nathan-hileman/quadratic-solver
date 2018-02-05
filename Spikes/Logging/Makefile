CC = gcc

CFLAGS = -Wall -pedantic -std=c99

all: log_test

debug: CCFLAGS += DDEBUG -g
debug: log_test

log_test:

	$(CC) $(CCFLAGS) logging.c -o t