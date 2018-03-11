CC = gcc
CCFLAGS = -Wall -pedantic -std=c99 
LIBS = -lm

test_q_solve: q_solve.c ../cunit.o
	$(CC) $(CCFLAGS) -c q_solve.c ;
	$(CC) $(CCFLAGS) -o test_q_solve q_solve.o ../cunit.o $(LIBS)
	mv q_solve.o ../test-runs;
	mv ../cunit.o ../test-runs;
	mv test_q_solve ../test-runs

run:
	../test-runs/test_q_solve

clean:
	rm -rf ../test-runs/q_solve.o;
	rm -rf ../test-runs/test_q_solve;
	rm -rf ../test-runs/cunit.o