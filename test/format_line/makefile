CC = gcc
CCFLAGS = -Wall -pedantic -std=c99 
LIBS = -lm

test_format_line: format_line.c ../cunit.o
	$(CC) $(CCFLAGS) -c format_line.c ;
	$(CC) $(CCFLAGS) -o test_format_line format_line.o ../cunit.o $(LIBS)
	mv format_line.o ../test-runs;
	mv ../cunit.o ../test-runs;
	mv test_format_line ../test-runs

run:
	../test-runs/test_format_line

clean:
	rm -rf ../test-runs/format_line.o;
	rm -rf ../test-runs/test_format_line;
	rm -rf ../test-runs/cunit.o