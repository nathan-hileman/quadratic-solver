CC = gcc

CCFLAGS = -Wall -pedantic -std=c99 -lm

all: validate_line

debug: CCFLAGS += DDEBUG -g
debug: validate_line

validate_line.o: validate_line.c
	$(CC) $(CCFLAGS) -c validate_line.c

clean:
	rm -rf validate_line.o