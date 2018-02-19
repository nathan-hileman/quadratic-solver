CC = gcc

CFLAGS = -Wall -pedantic -std=c99

all: initial_quad_solve

debug: CCFLAGS += DDEBUG -g
debug: initial_quad_solve

initial_quad_solve:
    $(CC) $(CCFLAGS) initial_quad_solve.c -o t