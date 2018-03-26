/* Command Line Quadratic Solver
   TEAM: Ali Itani, Nathan Hleman, Xavier Gray
   Kapenga Inc., LICENSE: GPL 2.0      */
#include <stdio.h>
#include <stdlib.h>     // for malloc
#include <string.h>     // for memset
#include <math.h>
#include "q_solve.h"
#include "../cunit.h"   // for unit testing

/* Function that implements the quadratic equation.
 * Takes floats a, b, and c from user input and uses them in the equation.
 */
int q_solve(float a, float b, float c, float *root_1, float *root_2, int *solution) {   
    
    // Declaration of Variables
    float disc;  // discriminant
 
    // Equation for the Discriminant
    disc = (b * b) - (4 * a * c);
    
    // Discriminant Positive, Real Number Solution
    if (disc > 0) {
        
        printf("\tTwo real root solutions.\n");
  
        // Calculate Solution of Both Roots
        *root_1 = (-b + sqrt(disc)) / (2 * a);
        *root_2 = (-b - sqrt(disc)) / (2 * a);

        printf("\tRoots of quadratic equation are %.7f and %.7f\n",  root_1[0], root_2[0]);

    } else if (disc == 0) {  // Discriminant Zero, One Real Double Root Solution
        
        printf("\tReal double root solution.\n");
 
        // Calculate Single Double Root Solution
        *root_1 = -b / (2 * a);
        *root_2 = b / (2 * a);

        printf("\tRoot of quadratic equation is ±%.7f\n", fabs(root_1[0]));
 
        return 0;
        
    } else {    // Discriminant Negative, Complex Number Solution (IGNORE)
        
        printf("\tComplex roots. No real solution.\n");

        return 0; 
    }
 
    return 0;
}

/* Test case environment */
int main(int argc, char ** argv)
{
    // Initialize the unit testing framework and variables
    float a, b, c = 0;
    float root_1, root_2 = 0;
    int solution = 0;
    char * buffer = malloc(sizeof(char) * 100);     // output buffer
    int ret = 0;

    cunit_init();

    /* TEST 1 - 2 real roots */

        /* Initialize required variables */
        
        a = 10.0;
        b = 5.0;
        c = -8.0;
        solution = 0;
        root_1 = 0.0;
        root_2 = 0.0;
        
        cunit_print("\nTEST 1: \n\tCoefficients: a = 10.0, b = 5.0, c = -8.0");
        
        /* Run q_solve */
        cunit_print("\n\tResults: ");

        ret = q_solve(a, b, c, &root_1, &root_2, solution);
        
        /* Assert if unit test passed */
        assert_eq("\n\tCUNIT ERROR: Reason...", ret, 0);

        /* Clear memory */
        memset(buffer, 0, sizeof(char));

    /* TEST 2 - 1 real double root */   

        /* Initialize required variables */
        a = 9.0;
        b = 12.0;
        c = 4.0;
        solution = 0;
        root_1 = 0.0;
        root_2 = 0.0;

        cunit_print("\nTEST 2 \n\tCoefficients: a = 9.0, b = 12.0, c = 4.0");
        
        /* Run q_solve */
        cunit_print("\n\tResults: ");

        ret = q_solve(a, b, c, &root_1, &root_2, solution);

        /* Assert if unit test passed */
        assert_eq("\n\tCUNIT ERROR: Reason...", ret, 0);

        /* Clear memory */
        memset(buffer, 0, sizeof(char));

    /* TEST 3 - complex roots */

        /* Initialize required variables */
        a = 1.0;
        b = 2.0;
        c = 3.0;
        solution = 0;
        root_1 = 0.0;
        root_2 = 0.0;

        cunit_print("\nTEST 3 \n\tCoefficients: a = 1.0, b = 2.0, c = 3.0");
        
        /* Run q_solve */
        cunit_print("\n\tResults: ");

        ret = q_solve(a, b, c, &root_1, &root_2, solution);

        /* Assert if unit test passed */
        assert_eq("\n\tCUNIT ERROR: Reason...", ret, 0);

        /* Clear memory */
        memset(buffer, 0, sizeof(char));

    /* TEST 4 */

        /* Initialize required variables */
        a = 1.2487584793;
        b = -77.498379872;
        c = -3443.123456789;
        solution = 0;
        root_1 = 0.0;
        root_2 = 0.0;

        cunit_print("\nTEST 4 \n\tCoefficients: a = 1.2487584793, b = -77.498379872, c = -3443.123456789");
        
        /* Run q_solve */
        cunit_print("\n\tResults: ");

        ret = q_solve(a, b, c, &root_1, &root_2, solution);

        /* Assert if unit test passed */
        assert_eq("\n\tCUNIT ERROR: Reason...", ret, 0);

        /* Clear memory */
        memset(buffer, 0, sizeof(char));

    /* TEST 5 */

        /* Initialize required variables */
        a = -999;
        b = 333;
        c = -444;
        solution = 0;
        root_1 = 0.0;
        root_2 = 0.0;

        cunit_print("\nTEST 4 \n\tCoefficients: a = -999, b = 333, c = -444");
        
        /* Run q_solve */
        cunit_print("\n\tResults: ");

        ret = q_solve(a, b, c, &root_1, &root_2, solution);

        /* Assert if unit test passed */
        assert_eq("\n\tCUNIT ERROR: Reason...", ret, 0);

        /* Clear memory */
        memset(buffer, 0, sizeof(char));

    // TEST 1 with relative error

        double x1 = 3.1;
        double x2 = 3.3;
        a = 1.0;
        b = -x1 + - x2;
        c = x1 * x2;
        solution = 0;
        root_1 = 0.0;
        root_2 = 0.0;
        
        cunit_print("\nTEST 1 with Relative Error: \n\tCoefficients: a = 1.0, b = -3.1 + -3.3, c = 3.1 * 3.3");

        // Running q_solve function
        cunit_print("\n\tResults: ");

        ret = q_solve(a, b, c, &root_1, &root_2, solution);

        // check if test passed
        assert_eq("\n\tCUnit ERROR: Failed q_solve(): ", ret, 0);

        // check for relative error
        assert_feqrerr("X1", x1, x2, 10.0 * cunit_dmacheps);
        assert_feqrerr("X2", x2, x1, 10.0 * cunit_dmacheps);

        // clear memory
        memset(buffer, 0,sizeof(char));

   // TEST 2 with relative error

        x1 = 3.9;
        x2 = 3.5;
        a = 1.0;
        b = -x1 + - x2;
        c = x1 * x2;
        solution = 0;
        root_1 = 0.0;
        root_2 = 0.0;
        
        cunit_print("\nTEST 2 with Relative Error: \n\tCoefficients: a = 1.0, b = -3.9 + -3.5, c = 3.9 * 3.5");

        // Running q_solve function
        cunit_print("\n\tResults: ");

        ret = q_solve(a, b, c, &root_1, &root_2, solution);

        // check if test passed
        assert_eq("\n\tCUnit ERROR: Failed q_solve(): ", ret, 0);

        // check for relative error
        assert_feqrerr("X1", x1, x2, 10.0 * cunit_dmacheps);
        assert_feqrerr("X2", x2, x1, 10.0 * cunit_dmacheps);

        // clear memory
        memset(buffer, 0,sizeof(char));

    // TEST 3 with relative error

        x1 = -6.0;
        x2 = -6.0;
        a = 9.0;
        b = -x1 + - x2;
        c = -(x1/3) * -(x2/3);
        solution = 0;
        root_1 = 0.0;
        root_2 = 0.0;
        
        cunit_print("\nTEST 3 with Relative Error: \n\tCoefficients: a = 1.0, b = -3.9 + -3.5, c = 3.9 * 3.5");

        // Running q_solve function
        cunit_print("\n\tResults: ");

        ret = q_solve(a, b, c, &root_1, &root_2, solution);

        // check if test passed
        assert_eq("\n\tCUnit ERROR: Failed q_solve(): ", ret, 0);

        // check for relative error
        assert_feqrerr("X1", x1, x2, 10.0 * cunit_dmacheps);
        assert_feqrerr("X2", x2, x1, 10.0 * cunit_dmacheps);

        // clear memory
        memset(buffer, 0,sizeof(char));

    free(buffer);
}
