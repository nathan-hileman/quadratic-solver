CC = gcc
CCFLAGS = -Wall -pedantic -std=c99

debug: CCFLAGS += DDEBUG -g
debug: read_line

q_solve.o: q_solve.c q_solve.h
    $(CC) $(CCFLAGS) -c q_solve.c

clean:
	-rm -rf q_solve.o
