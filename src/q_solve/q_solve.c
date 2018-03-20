#include <stdio.h>
#include <math.h>
#include "q_solve.h"
#include "../log_output/log_output.h"

/* Function that implements the quadratic equation.
 * Takes floats a, b, and c from user input and uses them in the equation.
 */
int q_solve(float a, float b, float c, float *root_1, float *root_2, int *solution)
{   
    
    /* Declaration of Variables */
    float disc;  // discriminant
 
    /* Equation for the Discriminant */
    disc = (b * b) - (4 * a * c);
//in case of a sin
    /* Discriminant Positive, Real Number Solution */
    if (disc > 0) {
        
        // printf("Two real root solutions.\n");
        log_output("Two real root solutions.");
  	/* Set solution for format_line */
	*solution = 1;
        /* Calculate Solution of Both Roots */
        *root_1 = (-b + sqrt(disc)) / (2 * a);
        *root_2 = (-b - sqrt(disc)) / (2 * a);

        // printf("Roots of quadratic equation are %.7f and %.7f\n",  root_1[0], root_2[0]);

    } else if (disc == 0) {  /* Discriminant Zero, One Real Double Root Solution */
        
        // printf("Real double root solution.\n");
        log_output("Real double root solution.");
	    /* Set solution for format_line */
 	    *solution = 2;
        /* Calculate Single Double Root Solution */
        *root_1 = -b / (2 * a);
        *root_2 = b / (2 * a);

        // printf("Root of quadratic equation is ±%.7f\n", root_1[0]);
 
        return 0;
        
    } else {    /* Discriminant Negative, Complex Number Solution (IGNORE) */
        
        // printf("Complex roots. No real solution.\n");
        log_output("Complex root. No real solution.");

	/* Set solution for format line */
	*solution = 0;

        return 0; 
    }
 
    return 0;
}
