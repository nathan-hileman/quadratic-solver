/* Command Line Quadratic Solver
   TEAM: Ali Itani, Nathan Hleman, Xavier Gray
   Kapenga Inc., LICENSE: GPL 2.0      */
#include <stdio.h>
#include <math.h>
#include "../includes/q_solve.h"
#include "../includes/log_output.h"

/* *
 * Function that implements the quadratic equation.
 * Takes floats a, b, and c from user input and uses them in the equation.
 */
int q_solve(float a, float b, float c, float *root_1, float *root_2, int *solution) {   
    
    // Declaration of variables 
    float disc;  
 
    // Equation for the discriminant.
    disc = (b * b) - (4 * a * c);
    
    // Discriminant positive, Real-Number solution. 
    if (disc > 0) { 
        
        log_output("\tResult: Two real root solutions.");
  	    
        // Set solution for format_line function. 
	    *solution = 1;
        
        // Calculate solution of both roots. 
        *root_1 = (-b + sqrt(disc)) / (2 * a);
        *root_2 = (-b - sqrt(disc)) / (2 * a);

        // printf("Roots of quadratic equation are %.7f and %.7f\n",  root_1[0], root_2[0]);
    }
    
    // Discriminant Zero, One Real Double Root Solution.
    else if (disc == 0) {      
        
        // printf("Real double root solution.\n");
        log_output("\tResult: Real double root solution.");

	    // Set solution for format_line 
 	    *solution = 2;

        // Calculate Single Double Root Solution 
        *root_1 = -b / (2 * a);
        *root_2 = -b / (2 * a);

        // printf("Root of quadratic equation is ±%.7f\n", root_1[0]);
 
        return 0;
    } 
    
    // Discriminant Negative, Complex Number Solution (IGNORE).
    else { 

        // printf("Complex roots. No real solution.\n");
        log_output("\tResult: Complex root, No real solution.");

	    // Set solution for format line
	    *solution = 0;

        return 0; 
    }
 
    return 0;
}
