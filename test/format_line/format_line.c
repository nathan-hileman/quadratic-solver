#include "format_line.h"
//#include "log_output.h"
/* format_line: takes arguments from main and formats a string to be passed to outline
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
	
	return ret;
}

int main(void) {
	struct out_args args;
	args.root_1 = 4;
	args.root_2 = 18;
	args.a = 1;
	args.b = 2;
	args.c = 3;
	args.solution = 0;
	int ret = format_line(&args);
	printf("%s\n", args.output_string);

	args.solution = 1;
        ret = format_line(&args);
        printf("%s\n", args.output_string);

	args.solution = 2;
	ret = format_line(&args);
        printf("%s\n", args.output_string);


	return 0;
}