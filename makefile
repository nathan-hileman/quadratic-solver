CC = gcc
CCFLAGS = -Wall -pedantic -std=c99

program:
	cd src; make build;

run: 
	cd src; ./quad_solver;

deploy:
	tar -cvf quad_solver.tar src/quad_solver;

test_qsolve:
	cd test; cd q_solve; make test_q_solve; make run; make clean;

test_readline:
	cd test; cd read_line; make test_read_line; make run; make clean;

test_validate:
	cd test: cd validate_line; make test_validate_line; make run; make clean;

clean:
	cd src; make clean;