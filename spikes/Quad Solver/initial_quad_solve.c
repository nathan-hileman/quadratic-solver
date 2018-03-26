/* Command Line Quadratic Solver
   TEAM: Ali Itani, Nathan Hleman, Xavier Gray
   Kapenga Inc., LICENSE: GPL 2.0      */
#include<stdio.h>
#include<math.h>

/* test bed for an initial quadratic equation solver. No multi-precision. Rounds to 7 decimal places. */
int main() {
    
    /* coefficients for the quadratic equation provided by user */
    float a, b, c;     
    
    /* discriminant and the two possible root solutions */
    float d, root_1, root_2;  
 
    printf("Enter a, b, and c for the quadratic equation ax^2 + bx + c: ");
    
    /* read inputs from user */
    scanf("%f%f%f", &a, &b, &c);
   
    /* equation for calculating the discriminant */
    d = b * b - 4 * a * c;

    /* discriminant positive, real number solution */
    if (d > 0) {
        printf("Roots are real numbers.\n");
  
        /* calculate solution of both roots */
        root_1 = (-b + sqrt(d)) / (2 * a);
        root_2 = (-b - sqrt(d)) / (2 * a);

        printf("Roots of quadratic equation are: %.7f , %.7f", root_1, root_2);
    }

    /* discriminant zero, one real double root */
    else if (d == 0) {
        printf("Double root solution.\n");
 
        /* calculate single double root solution */
        root_1 = -b / (2 * a);

        printf("Root of quadratic equation is +/-: %.7f ", root_1);
 
        return 0;
    }

    /* discriminant negative, complex number solution, not interested */
    else {
        printf("Complex roots. No real solution.\n");
    
        return 0; 
    }
 
    return 0;
}