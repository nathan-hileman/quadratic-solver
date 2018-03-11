CC = gcc
CCFLAGS = -Wall -pedantic -std=c99 

test_read_line: read_line.c ../cunit.o
	$(CC) $(CCFLAGS) -c read_line.c;
	$(CC) $(CCFLAGS) -o test_read_line read_line.o ../cunit.o;
	mv read_line.o ../test-runs;
	mv ../cunit.o ../test-runs;
	mv test_read_line ../test-runs

run:
	../test-runs/test_read_line

clean:
	rm -rf ../test-runs/read_line.o;
	rm -rf ../test-runs/test_read_line;
	rm -rf ../test-runs/cunit.o;
	