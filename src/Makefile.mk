CC = gcc
CCFLAGS = -Wall -pedantic -std=c99

quad_solver: quad_solver.c log_output/log_output.o read_line/read_line.o

test:
	cd log_output; make log_output.o;
	cd read_line; make read_line.o;
