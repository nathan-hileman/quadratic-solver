CC = gcc

CCFLAGS = -Wall -pedantic -std=c99 -lm

all: outline

test: test_outline

debug: CCFLAGS += DDEBUG -g
debug: outline

outline:
	$(CC) $(CCFLAGS) outline.c -o outline
test_format_line:
	$(CC) $(CCFLAGS) test_outline.c -o test_outline
clean:
	rm outline; rm outline.o

