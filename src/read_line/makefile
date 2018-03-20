CC = gcc
CCFLAGS = -Wall -pedantic -std=c99

debug: CCFLAGS += DDEBUG -g
debug: read_line

read_line.o: read_line.c read_line.h
	$(CC) $(CCFLAGS) -c read_line.c

clean:
	-rm -rf read_line.o
