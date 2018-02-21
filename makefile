CC = gcc
CCFLAGS = -Wall -pedantic -std=c99

program:
	cd src; make quad_solver;

deploy:
	tar -cvf quad_solver.tar src/quad_solver;

clean:
	-rm -rf quad_solver
	cd src; make clean