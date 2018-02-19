CC = gcc
CCFLAGS = -Wall -pedantic -std=c99

cunit:
	$(CC) $(CCFLAGS) cunit.c -lcunit -o cunit
