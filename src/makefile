CC = gcc
CCFLAGS = -Wall -pedantic -std=c99

quad_solver: quad_solver.c log_output/log_output.o read_line/read_line.o validate/validate_line.o
	$(CC) $(CCFLAGS) -c quad_solver.c;
	$(CC) $(CCFLAGS) -o quad_solver quad_solver.o read_line/read_line.o log_output/log_output.o validate/validate_line.o

test:
	cd log_output; make log_output.o;
	cd read_line; make read_line.o;
	cd validate_line; make validate_line.o;

clean:
	rm -rf quad_solver *.o core log.txt