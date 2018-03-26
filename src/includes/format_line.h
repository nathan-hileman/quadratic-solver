/* Command Line Quadratic Solver
   TEAM: Ali Itani, Nathan Hleman, Xavier Gray
   Kapenga Inc., LICENSE: GPL 2.0      */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "log_output.h"

/* struct for holding the arguments to format_line */
struct out_args {
	float a; 				// first coefficient  - a
	float b; 				// second coefficient - b
	float c; 				// third coefficient  - c
	int solution; 			// 0 = complex solution, 1 = double, 2 = single
	float root_1; 			// first root
	float root_2; 			// second root
	char* output_string; 	// the string to be passed to outline - will be allocated within format_line
};

int format_line(struct out_args *args);
