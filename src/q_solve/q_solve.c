#include <stdio.h>
#include <math.h>
#include "q_solve.h"

/* Function that implements the quadratic equation.
 * Takes floats a, b, and c from user input and uses them in the equation.
 */
int q_solve(float a, float b, float c, float *root_1, float *root_2)
{   
    
    /* Declaration of Variables */
    float disc;  // discriminant
 
    /* Equation for the Discriminant */
    disc = (b * b) - (4 * a * c);

    /* Discriminant Positive, Real Number Solution */
    if (disc > 0) {
        
        printf("Roots are real numbers.\n");
  
        /* Calculate Solution of Both Roots */
        *root_1 = (-b + sqrt(disc)) / (2 * a);
        *root_2 = (-b - sqrt(disc)) / (2 * a);

        printf("Roots of quadratic equation are: %.7f , %.7f", (void *) root_1, (void *) root_2);

    } else if (disc == 0) {  /* Discriminant Zero, One Real Double Root Solution */
        
        printf("Double root solution.\n");
 
        /* Calculate Single Double Root Solution */
        *root_1 = -b / (2 * a);
        *root_2 = b / (2 * a);

        printf("Root of quadratic equation is +/-: %.7f ", (void *) root_1);
 
        return 0;
        
    } else {    /* Discriminant Negative, Complex Number Solution (IGNORE) */
        
        printf("Complex roots. No real solution.\n");
    
        return 0; 
    }
 
    return 0;
}