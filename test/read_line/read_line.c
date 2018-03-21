/**
* Read Line
* 2/4/2018
* Prompts the user for input
*/

#include <stdio.h>
#include <stdlib.h>
#include "read_line.h"
#include "../cunit.h" // for c unit testing framework
#include <string.h> // for strlen

/**
* Prompts the user for input and reads the line that was inputted.  
* Returns a string of user input.
*/
char *read_line() {
    // allocate memory for the input buffer
    char *input = malloc(sizeof(char) * 100);   
    
    printf("Enter values for a, b, and c: ");
    
    // read the line of input

    fgets(input, sizeof(char) * 100, stdin);    

    return input;
}

/* Main method for testing. */

int main() {

    cunit_init();

    char * line = read_line();
    
    // if nothing was inserted should assert_neq and return error if line is 0

    assert_neq(line, 1, (int) strlen(line));

    return 0;
}
