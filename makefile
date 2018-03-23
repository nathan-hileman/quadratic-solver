CC = gcc
CCFLAGS = -Wall -pedantic -std=c99

# Compiles the program. Stores the object files in /build and executable in /src
program:
	@cd src; make build;

# Runs the executable 
run:
	@cd src; ./quad_solver;

# Gives the user a list of commands for make
help:
	@cat README.md;

# Compresses the executable into a tar ball
deploy:
	@tar -cvf quad_solver.tar src/quad_solver;

# Unit test for q_solve function
test_qsolve:
	@cd test; cd q_solve; make test_q_solve; make run; make clean;

# Unit test for read_line function
test_readline:
	@cd test; cd read_line; make test_read_line; make run; make clean;

# Unit test for validate_line function
test_validate:
	@cd test: cd validate_line; make test_validate_line; make run; make clean;

# Unit test for format_line function
test_formatline:
	@cd test; cd format_line; make test_format_line; make run; make clean;

# Unit tet for outline function
test_outline:
	@cd test; cd outline; make test_outline; make run; make clean;

# Cleans all executables, object files, logs, etc.
clean:
	@cd src; make clean;