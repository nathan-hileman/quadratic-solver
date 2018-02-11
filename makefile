CC = gcc
CCFLAGS = -Wall -pedantic -std=c99

deploy:
	cd src; make quad_solver;

clean:
	-rm quad_solver
	cd src; make clean