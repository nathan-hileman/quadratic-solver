#include <stdio.h>
#include <math.h>
/* struct for holding the arguments to format_line */
struct out_args
{
	float x; // the x value from q_solve
	float a; // a
	float b; // b
	float c; // c
	int real_solution; // is it a real solution?
	int double_solution; // is it a double solution
	char* output_string; // the string to be passed to outline - will be allocated within format_line
};
int format_line(struct out_args *args);