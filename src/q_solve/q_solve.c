#include <stdio.h>
#include <math.h>
#include "q_solve.h"
#include "log_output.h"

/* Function that implements the quadratic equation.
 * Takes floats a, b, and c from user input and uses them in the equation.
 */
int q_solve(float a, float b, float c)
{   
    
    /* Declaration of Variables */
    float d, root_1, root_2;  // discrimanant, and the two possible root solutions
 
    /* Equation for the Discriminant */
    d = b * b - 4 * a * c;

    /* Discriminant Positive, Real Number Solution */
    if (d > 0)
    {
        printf("Roots are real numbers.\n");
  
        /* Calculate Solution of Both Roots */
        root_1 = (-b + sqrt(d)) / (2 * a);
        root_2 = (-b - sqrt(d)) / (2 * a);

        printf("Roots of quadratic equation are: %.7f , %.7f", root_1, root_2);
    }

    /* Discriminant Zero, One Real Double Root Solution */
    else if (d == 0)
    {
        printf("Double root solution.\n");
 
        /* Calculate Single Double Root Solution */
        root_1 = -b / (2 * a);

        printf("Root of quadratic equation is +/-: %.7f ", root_1);
 
        return 0;
    }

    /* Discriminant Negative, Complex Number Solution (IGNORE) */
    else
    {
        printf("Complex roots. No real solution.\n");
    
        return 0; 
    }
 
    return 0;
}