#include <stdlib.h>
#include <stdio.h>
#include "quad_solver.h"
#include "./read_line/read_line.h"
#include "./log_output/log_output.h"
#include "./validate/validate_line.h"

/**
* Controller for the quadratic equation solver
*/
int main()
{
    log_output("Command Line Quadratic Solver\n");

    /* read line */
    char *input = read_line();  // reads a,b,c from user input
    log_output("read_line values:   ");
    log_output(input);  // write input to log file

    /* validate */
    int n = 100;
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    log_output("validation:   ");
    if (check_validation(input, n, &a, &b, &c) != 0)
    {
        log_output("Invalid input");
    }
    else
    {
        log_output("input valid");
    }

    

}