#include <stdlib.h>
#include <stdio.h>
#include "./includes/quad_solver.h"
#include "string.h"

/**
* Controller for the Command Line Quadratic Solver.
*/
int main() {
    
    // Declared and initialized variables.
    n = 100;                                  
    a = 0.0, b = 0.0, c = 0.0;              // equation coefficients         
    root_1 = 0.0, root_2 = 0.0;             // root solutions
    solution = 0;			                
    buffer = malloc(sizeof(char) * 100);  
    counter = 1;                             

    // Begin to log output of the program
    log_output("+----------------------------------------------------------+");
    log_output("|               Command Line Quadratic Solver              |");
    log_output("|        Team: Ali Itani, Nathan Hleman, Xavier Gray       |");
    log_output("|                            v1.0                          |");
    log_output("+----------------------------------------------------------+");

    // Print to console
    printf("+----------------------------------------------------------+\n");
    printf("|               Command Line Quadratic Solver              |\n");
    printf("|        Team: Ali Itani, Nathan Hleman, Xavier Gray       |\n");
    printf("|                            v1.0                          |\n");
    printf("+----------------------------------------------------------+\n");


    // Prompts the user for the numbers.
    char * input = read_line();        
    
    // Checks if the prompt is a command to quit program. 
    int prompt = strncmp(input, "q", 1);
   
   // While the user doesn't input "q" the program will continue to run
    while(prompt != 0) {

        // Log question number.
        char buff[100];
        sprintf(buff, "\nQuestion %d:", counter);
        log_output(buff);
        log_output("============\n");

        // Read line function.
        log_output("\tread_line Function: ");     
        log_output("\t===================");        

        // Logs result of read line to file. 
        char read_line_buff[1024];
        sprintf(read_line_buff, "\tLine read from user: %s", input);

        log_output(read_line_buff);                  

        // Validate line function. 
        log_output("\tvalidate_line Function: ");
        log_output("\t=======================");        
        
        // Flag for validate line. 
        int ret = check_validation(input, n, &a, &b, &c);   

        // Check if the flag is valid.
        if ( ret == -1 ) {
            
            // Log the result of validate line function to file.
            log_output("\tERROR: Input is invalid!");
            
            return -1;

        } else {
            
            // Log result of validate line to file. 
            log_output("\tInput is valid!");            
             
            char message[1024];
            sprintf(message, "\tCoefficients: [a] = %.7lf, [b] =  %.7lf, and [c] %.7lf\n", a, b, c);

            log_output(message);
        }

        //Q Solve Function
        log_output("\tq_solve Function: ");
        log_output("\t=================");

        // Check if q_solve returned an error
        if ( q_solve(a, b, c, &root_1, &root_2, &solution) != 0 ) {   
             
            log_output("\tERROR: Operation failed!");

            return -1;

        } else {
        
            log_output("\tOperation was successful!");
            
            // Format line function. 
            log_output("\n\tformat_line Function: ");
            log_output("\t====================="); 

            // Struct to store results of roots that will be sent to format line and outline functions.
            struct out_args final_args;
            final_args.a = a;
            final_args.b = b;
            final_args.c = c;
            final_args.root_1 = root_1;
            final_args.root_2 = root_2;
            final_args.solution = solution;
            
            if (format_line(&final_args) != 0) {
                log_output("\tOperation failed!");
                return -1;
            } else {
                log_output("\tOperation was successful!");
            }
            
            // Format line function. 
            log_output("\n\toutline Function: ");
            log_output("\t================="); 

            if (outline(final_args.output_string) != 0){
                log_output("\tOperation failed!");
                log_output(final_args.output_string);
                        return -1;
            } else {
                log_output("\tOperation was successful!");
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
    log_output("\nExiting program...\n\n");

    // Free buffer memory.
    free(buffer);

    return 0;
}
