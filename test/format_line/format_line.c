/* Command Line Quadratic Solver
   TEAM: Ali Itani, Nathan Hleman, Xavier Gray
   Kapenga Inc., LICENSE: GPL 2.0      */
#include "format_line.h"

/* Takes arguments from main and formats a string to be passed to outline
 * out_args: see format_line.h for details
 */
int format_line(struct out_args *args) {
	
	int ret = 0;
	
	args->output_string = malloc(500); // allocate space for the output string
	
	/* if the solution is complex, prepare a string stating that for the user */
	if (args->solution == 0) {
		
		// if sprintf fails, change the return value to 1
		ret = ((sprintf(args->output_string, "There is no real solution for a = %f, b = %f, and c = %f", 
			args->a, args->b, args->c)) < 0 ? 1 : 0);
	
	} 

	/*  Double Solution */
	else if (args->solution == 1) {

		// if sprintf fails, change the return value to 1
		ret = ((sprintf(args->output_string, "a = %f, b = %f, and c = %f produces a double solution\n\troot 1 = %.7f, root 2 = %.7f",
				args->a, args->b, args->c, args->root_1, args->root_2)) < 0 ? 1 : 0);
	}	

	 /* Single Double Root Solution */
	else if (args->solution == 2) {

		// if sprintf fails, change the return value to 1
		ret = ((sprintf(args->output_string, "a = %.7f, b = %.7f, and c = %.7f produces a Single Double Root Solution\n\t root = +-%.7f",
			args->a, args->b, args->c, args->root_1)) < 0 ? 1 : 0);
	}

	else {
		ret = 1; // solution should only be between 0 and 2
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