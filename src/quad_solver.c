#include <stdlib.h>
#include <stdio.h>
#include "quad_solver.h"
#include "./read_line/read_line.h"
#include "./log_output/log_output.h"
#include "./validate/validate_line.h"
#include "./q_solve/q_solve.h"
#include "./format_line/format_line.h"
#include "./outline/outline.h"
#include "string.h"



/**
* Controller for the Command Line Quadratic Solver.
*/
int main() {
    
    // Declared and initialized variables.
    n = 100;                                  
    a = 0.0, b = 0.0, c = 0.0;                
    root_1 = 0.0, root_2 = 0.0;               
    solution = 0;			                  
    buffer = malloc(sizeof(char) * 100);     
    counter = 1;                             

    log_output("============================================================");
    log_output("=");
    log_output("=");
    log_output("=================Command Line Quadratic Solver==============");
    log_output("=");
    log_output("=");
    log_output("============================================================");
    log_output("Team Members: Ali, Nathan, Xavier!");
    log_output("Enjoy!\n\n\n");
    

    // Prompts the user for the numbers.
    char * input = read_line();        
    
    // Checks if the prompt is a command to quit program. 
    int prompt = strncmp(input, "q", 1);
   
    while(prompt != 0) {

        // Log question number.
        char buff[100];
        sprintf(buff, "\n\nQestion %d:", counter);
        log_output(buff);
        log_output("============================\n\n");

        // Read line function.
        log_output("Read Line Function: ");     
        log_output("===================");        

        // Logs result of read line to file. 
        char read_line_buff[1024];
        sprintf(read_line_buff, "Line read from user: %s", input);

        log_output(read_line_buff);                  

        // Validate line function. 
        log_output("Validate Line Function: ");
        log_output("===================");        
        
        // Flag for validate line. 
        int ret = check_validation(input, n, &a, &b, &c);   

        // Check if the flag is valid.
        if ( ret == -1 ) {
            
            // Log the result of validate line function to file.

            log_output("ERROR: Input is Invalid!");
            
            return -1;
        } else {
            
            // Log result of validate line to file. 
        
            log_output("Result: Input is Valid!");            
             
            char message[1024];
            sprintf(message, "Numbers are: [a] = %.7lf [b] =  %.7lf and [c] %.7lf\n", a, b, c);

            log_output(message);

        }

        //Q Solve Function
        log_output("Q Solve Function: ");
        log_output("===================");

        // Check if q_solve returned an error
        if ( q_solve(a, b, c, &root_1, &root_2, &solution) != 0 ) {   
             
            log_output("ERROR: Operation Failed!");

            return -1;
        } else {
        
            log_output("Result: Operation was Successful!");
            
            // Struct to store results of roots that will be sent to format line and outline functions.
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
            
            //sprintf(buffer, "Answers:\nRoot(1)= %.7f\nRoot(2)= %.7f", root_1, root_2);     // write solutions to an output buffer 
            
            //log_output(buffer);     
            
        }

        // Prompt the user for another set of numbers. 

        // Using read line function. 
        input = read_line(); 

        // Checking user prompt value.
        prompt = strncmp(input, "q", 1);

        // Incrementing the number of questions.
        counter++;
    }

    // Free buffer memory.
    free(buffer);

    return 0;
}
