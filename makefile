CC = gcc
CCFLAGS = -Wall -pedantic -std=c99

program:
	cd src; make build;

deploy:
	tar -cvf quad_solver.tar src/quad_solver;

clean:
	cd src; make clean;