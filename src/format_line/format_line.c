#include "format_line.h"
//#include "log_output.h"
/* format_line: takes arguments from main and formats a string to be passed to outline
 * out_args: see format_line.h for details
 */
int format_line(struct out_args *args) {
	log_output("Entering format_line");

	int ret = 0;
	
	args->output_string = malloc(500); // allocate space for the output string
	
	/* if the solution is complex, prepare a string stating that for the user */
	
	if (args->solution == 0) {
		
		// if sprintf fails, change the return value to 1
		
		ret = ((sprintf(args->output_string, "There is no real solution for a = %f, b = %f, and c = %f", 
			args->a, args->b, args->c)) < 0 ? 1 : 0);
	
	} 
	else if (args->solution == 1) {
	/* Single Double Root Solution */
		// if sprintf fails, change the return value to 1
		ret = ((sprintf(args->output_string, "a = %f, b = %f, and c = %f produces a double solution\n\troot 1 = %.7f, root 2 = %.7f",
				args->a, args->b, args->c, args->root_1, args->root_2)) < 0 ? 1 : 0);
	}	
	else if (args->solution == 2) {
	 /* Single Double Root Solution */
		// if sprintf fails, change the return value to 1
		ret = ((sprintf(args->output_string, "a = %.7f, b = %.7f, and c = %.7f produces a Single Double Root Solution\n\t root = +-%.7f",
			args->a, args->b, args->c, args->root_1)) < 0 ? 1 : 0);
	}
	else{
		log_output("format_line was passed a solution that is not between 0 and 2");
		ret = 1; // solution should only be between 0 and 2
	}
	if (ret == 1)
		log_output("Failed to generate output_string\n");
	return ret;
}

