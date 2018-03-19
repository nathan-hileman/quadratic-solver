CC = gcc
CCFLAGS = -Wall -pedantic -std=c99 
LIBS = -lm

test_outline: outline.c ../cunit.o
	$(CC) $(CCFLAGS) -c outline.c ;
	$(CC) $(CCFLAGS) -o test_outline outline.o ../cunit.o $(LIBS)
	mv outline.o ../test-runs;
	mv ../cunit.o ../test-runs;
	mv test_outline ../test-runs

run:
	../test-runs/test_outline

clean:
	rm -rf ../test-runs/outline.o;
	rm -rf ../test-runs/test_outline;
	rm -rf ../test-runs/cunit.o