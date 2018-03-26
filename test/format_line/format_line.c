/* Command Line Quadratic Solver
   TEAM: Ali Itani, Nathan Hleman, Xavier Gray
   Kapenga Inc., LICENSE: GPL 2.0      */
#include "format_line.h"

/* Takes arguments from main and formats a string to be passed to outline
 * out_args: see format_line.h for details
 */
int format_line(struct out_args *args) {

	int ret = 0;
	
	 // allocate space for the output string
	args->output_string = malloc(500);
	

	// check to see if the solution rounds to 0
	if (args->root_1 <= -0)
	{
		args->root_1 = 0;
	}
	if (args->root_1 <= -0)
	{
		args->root_2 = 0;
	}
	// if the solution is complex, prepare a string stating that for the user
	if (args->solution == 0) {
		
		// if sprintf fails, change the return value to 1
		ret = ((sprintf(args->output_string, "\nThere is no solution for the coefficients:\n\ta = %f, b = %f, and c = %f", 
			args->a, args->b, args->c)) < 0 ? 1 : 0);
	} 

	// Single Double Root Solution
	else if (args->solution == 1) {
	
		// if sprintf fails, change the return value to 1
		ret = ((sprintf(args->output_string, "\nThere are two real solutions for coefficients:\n\ta = %f, b = %f, and c = %f\nSolutions:\n\troot 1 = %.7f\n\troot 2 = %.7f",
				args->a, args->b, args->c, args->root_1, args->root_2)) < 0 ? 1 : 0);
	}	

	// Single Double Root Solution
	else if (args->solution == 2) {

		// if sprintf fails, change the return value to 1
		ret = ((sprintf(args->output_string, "\nThere is a real double root solution for coefficients:\n\ta = %.7f, b = %.7f, and c = %.7f\nSolution:\n\troot 1 = %.7f\n\troot 2 = %.7f",
			args->a, args->b, args->c, args->root_1, args->root_2)) < 0 ? 1 : 0);
	}

	else {
		//log_output("\tERROR: format_line was passed a solution that is not between 0 and 2");
		
		ret = 1; // solution should only be between 0 and 2
	}

	// Failed to generate output
	if (ret == 1) {
		//log_output("\tERROR: Failed to generate output_string\n");
	}

	return ret;
}

/**
 * Test case environment
 **/
int main(void) {
	
	struct out_args args;
	args.root_1 = 4;
	args.root_2 = 18;
	args.a = 1;
	args.b = 2;
	args.c = 3;
	args.solution = 0;
	cunit_init();

	/* TEST 1: Complex solution */
    cunit_print("\nTEST 1: Complex solution");

	int ret = format_line(&args);
    cunit_print("\n\tResults: ");
    assert_eq("\n\tCUNIT ERROR: Reason...", ret, 0);

    /* TEST 2: Double Solution */
    cunit_print("\nTEST 2: Double Solution");

	args.solution = 1;
    ret = format_line(&args);
	cunit_print("\n\tResults: ");
    assert_eq("\n\tCUNIT ERROR: Reason...", ret, 0);

 	/* TEST 3: Single Double Root Solution */
    cunit_print("\nTEST 3: Single Double Root Solution");
	args.solution = 2;
	ret = format_line(&args);
    cunit_print("\n\tResults: ");
    assert_eq("\n\tCUNIT ERROR: Reason...", ret, 0);

    /* TEST 4: Unknown solution */
    cunit_print("\nTEST 4: Unknown solution");
    args.solution = 4;
	ret = format_line(&args);
    cunit_print("\n\tResults: ");
    assert_eq("\n\tCUNIT ERROR: Reason...", ret, 1);

    /* TEST 5: Incomplete args */
    cunit_print("\nTEST 5: Incomplete args");
    struct out_args args2;
    ret = format_line(&args2);
    cunit_print("\n\tResults: ");
    assert_eq("\n\tCUNIT ERROR: Reason...", ret, 0);

	return 0;
}