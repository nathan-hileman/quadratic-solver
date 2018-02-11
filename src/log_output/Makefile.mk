CC = gcc
CCFLAGS = -Wall -pedantic -std=c99

debug: CCFLAGS += DDEBUG -g
debug: log_output

log_output.o: log_output.c log_output.h

clean:
    -rm log_output.o
