CC = gcc
CCFLAGS = -Wall -pedantic -std=c99 
LIBS = -lm

test_validate_line: validate_line.c ../cunit.o
	$(CC) $(CCFLAGS) -c validate_line.c ;
	$(CC) $(CCFLAGS) -o test_validate_line validate_line.o ../cunit.o $(LIBS)
	mv validate_line.o ../test-runs;
	mv ../cunit.o ../test-runs;
	mv test_validate_line ../test-runs

run:
	../test-runs/test_validate_line

clean:
	rm -rf ../test-runs/validate_line.o;
	rm -rf ../test-runs/test_validate_line;
	rm -rf ../test-runs/cunit.o
	