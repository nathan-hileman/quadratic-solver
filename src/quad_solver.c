#include <stdlib.h>
#include <stdio.h>
#include "quad_solver.h"
#include "./read_line/read_line.h"
#include "./log_output/log_output.h"

/**
* Controller for the quadratic equation solver
*/
int main()
{
    char *input = read_line();  // reads a,b,c from user input
    log_output(input);  // write input to log file

    // validate here

}