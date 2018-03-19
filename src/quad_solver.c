#include <stdlib.h>
#include <stdio.h>
#include "quad_solver.h"
#include "./read_line/read_line.h"
#include "./log_output/log_output.h"
#include "./validate/validate_line.h"
#include "./q_solve/q_solve.h"
#include "./format_line/format_line.h"
#include "./outline/outline.h"

/**
* Controller for the quadratic equation solver
*/
int main() {
    
    /* Declare and Initialize Variables */
    int n = 100;
    float a = 0.0, b = 0.0, c = 0.0;                // input variables for quadratic equation
    float root_1 = 0.0, root_2 = 0.0;               // root solution(s) to quadratic equation
    int solution = 0;			            // type of solution
    char * buffer = malloc(sizeof(char) * 100);     // output buffer

    log_output("============================================================");
    log_output("\nCommand Line Quadratic Solver\n");


    /* Read Line of Input */
    char * input = read_line();         // reads a,b,c from user input
    
    log_output("read_line:   ");     
    log_output(input);                  // write input to log file


    /* Validate Input */
    log_output("check_validation:   ");

    int ret = check_validation(input, n, &a, &b, &c);   // validation flag

    if ( ret == -1 ) {

        log_output("Invalid Input!");
        
        return -1;

    } else {
    
        log_output("Input Valid!");
    }


    /* Ingest Into Quadratic Equation and Solve */
    log_output("\nq_solve:    ");

    if ( q_solve(a, b, c, &root_1, &root_2, &solution) != 0 ) {    // check if q_solve returned an error
    
        log_output("q_solve Failed!");   
        return -1;

    } else {
    
        log_output("q_solve Successful!");
        
	struct out_args final_args;
	final_args.a = a;
	final_args.b = b;
	final_args.c = c;
	final_args.root_1 = root_1;
	final_args.root_2 = root_2;
	final_args.solution = solution;
	if (format_line(&final_args) != 0) {
		log_output("Format line failed!");
		return -1;
	}
	if (outline(final_args.output_string) != 0){
		log_output("outline failed!");
		log_output(final_args.output_string);
                return -1;
        }

       // sprintf(buffer, "The roots are root 1: %.7f, root 2: %.7f", root_1, root_2);     // write solutions to an output buffer 
        
        log_output(buffer);     // write output buffer to log file

    }
    free(buffer);
    return 0;
}
