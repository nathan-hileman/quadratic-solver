CC = gcc
CCFLAGS = -Wall -pedantic -std=c99

quad_solver: quad_solver.c log_output/log_output.o read_line/read_line.o validate/validate_line.o q_solve/q_solve.o
	$(CC) $(CCFLAGS) -c quad_solver.c;
	$(CC) $(CCFLAGS) -o quad_solver quad_solver.o read_line/read_line.o log_output/log_output.o validate/validate_line.o q_solve/q_solve.o -lm

build:	quad_solver
	cd log_output; make log_output.o; cp log_output.o ../../build;
	cd read_line; make read_line.o; cp read_line.o ../../build;
	cd validate; make validate_line.o; cp validate_line.o ../../build;
	cd q_solve; make q_solve.o; cp q_solve.o ../../build;

clean:
	rm -rf quad_solver *.o core log.txt
	cd log_output; rm -rf log_output.o; 
	cd read_line; rm -rf read_line.o;
	cd validate; rm -rf validate_line.o;
	cd q_solve; rm -rf q_solve.o;
	cd ../build; rm -rf log_output.o;
	cd ../build; rm -rf read_line.o;
	cd ../build; rm -rf validate_line.o;
	cd ../build; rm -rf q_solve.o;