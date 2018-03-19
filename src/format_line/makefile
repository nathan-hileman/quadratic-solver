
CC = gcc

CCFLAGS = -Wall -pedantic -std=c99 -lm

all: format_line

test: test_format_line

debug: CCFLAGS += DDEBUG -g
debug: format_line

format_line:
	$(CC) $(CCFLAGS) format_line.c -o format_line
	
test_format_line: format_line.c test_format_line.c
	$(CC) $(CCFLAGS) test_format_line.c -o test_format_line

clean:
	rm format_line
	rm test_format_line
