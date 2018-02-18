#include <stdlib.h>
#include <stdio.h>
#include "quad_solver.h"
#include "./read_line/read_line.h"
#include "./log_output/log_output.h"
#include "./validate/validate_line.h"
#include "./q_solve/q_solve.h"

/**
* Controller for the quadratic equation solver
*/
int main()
{
    /* Declare and Initialize Variables */
    int n = 100;
    float a = 0.0, b = 0.0, c = 0.0;                            // input variables for quadratic equation
    float root_1 = 0.0, root_2 = 0.0;                           // root solution(s) to quadratic equation
    char *buffer = malloc(sizeof(char) * 100);                  // output buffer

    log_output("Command Line Quadratic Solver\n");

    /* Read Line of Input */
    char *input = read_line();                                  // reads a,b,c from user input
    
    log_output("read_line:   ");     
    log_output(input);                                          // write input to log file

    /* Validate Input */
    log_output("check_validation:   ");
    
    if ( check_validation(input, n, &a, &b, &c) != 0 )          // if input is invalid
    {
        log_output("Invalid input");                                // report invalid input to log file
    }
    else                                                        // input valid
    {
        log_output("input valid");                                  // report valid input to log file
    }

    /* Ingest Into Quadratic Equation and Solve */
    log_output("q_solve:    ")

    if ( q_solve(a, b, c, &root1, &root2) != 0 )                // if q_solve received an error
    {
        log_output("q_solve failed");                               // report failure to log file
    }
    else                                                        // if q_solve returned successfuly
    {
        log_output("q_solve successful");                           // report success to log file
        sprintf(buffer, "root1: %.7f, root2: %.7f");                // write solutions to an output buffer 
        log_output(buffer);                                         // write output buffer to log file
    }

}