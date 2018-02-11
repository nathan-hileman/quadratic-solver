/**
* Read Line
* 2/4/2018
* Prompts the user for input
*/

#include <stdio.h>
#include <stdlib.h>
#include "read_line.h"

/**
* Prompts the user for input and reads the line that was inputted.  
* 
* @return input
*/
char *read_line()
{
    char *input = malloc(sizeof(char) * 100);   // allocate memory for the input buffer
    printf("Enter values for a, b, and c: ");
    fgets(input, sizeof(char) * 100, stdin);    // read the line of input

    return input;
}
