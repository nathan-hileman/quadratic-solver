CC = gcc

CCFLAGS = -Wall -pedantic -std=c99 -lm

all: validate_line

debug: CCFLAGS += DDEBUG -g
debug: validate_line

validate_line:
	$(CC) $(CCFLAGS) validate_line_test.c -o validate_line_test