CC = gcc

CCFLAGS = -Wall -pedantic -std=c99 -lm

all: validate_line

debug: CCFLAGS += DDEBUG -g
debug: validate_line

validate_line: validate_line.c
	$(CC) $(CCFLAGS) validate_line.c -o validate_line

clean:
	rm validate_line