#include "format_line.h"
//#include "log_output.h"
/* format_line: takes arguments from main and formats a string to be passed to outline
 * out_args: see format_line.h for details
 */
int format_line(struct out_args *args)
{
	int ret = 0;
	
	args->output_string = malloc(100); // allocate space for the output string
	
	/* if there exists no real solution, prepare a string stating that for the user */
	
	if (!args->real_solution) {
		
		// if sprintf fails, change the return value to 1
		
		ret = ((sprintf(args->output_string, "There is no real solution for a = %f, b = %f, and c = %f", 
			args->a, args->b, args->c)) < 0 ? 1 : 0);
	
	} else {

		/* in case of a double solution */
		if (args->double_solution) {
			
			// if sprintf fails, change the return value to 1
			ret = ((sprintf(args->output_string, "a = %f, b = %f, and c = %f produces a double solution\n\tx= +-%f",
				args->a, args->b, args->c, args->x)) < 0 ? 1 : 0);
		
		} else { /* in case of a single solution */

			// if sprintf fails, change the return value to 1

			ret = ((sprintf(args->output_string, "a = %f, b = %f, and c = %f produces a single solution\n\tx= %f",
				args->a, args->b, args->c, args->x)) < 0 ? 1 : 0);

		}
	}
	
	return ret;
}
