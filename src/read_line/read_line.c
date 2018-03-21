#include <stdio.h>
#include <stdlib.h>
#include "../includes/read_line.h"

/**
* Prompts the user for input and reads the line that was inputted.  
* Returns a string of user input.
*/
char *read_line() {
    
    // Allocate memory for the input buffer. 
    char *input = malloc(sizeof(char) * 100);   
    
    printf("Enter values for a, b, and c: ");
    
    // Read the line of input from user from stdin.
    fgets(input, sizeof(char) * 100, stdin);    

    return input;
}
