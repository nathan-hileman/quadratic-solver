CC = gcc
CCFLAGS = -Wall -pedantic -std=c99

deploy:
	cd src; make quad_solver;

clean:
	-rm -rf quad_solver
	cd src; make clean