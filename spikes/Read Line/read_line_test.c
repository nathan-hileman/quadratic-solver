/* Command Line Quadratic Solver
   TEAM: Ali Itani, Nathan Hleman, Xavier Gray
   Kapenga Inc., LICENSE: GPL 2.0      */
/**
* Read Line
* 2/4/2018
* Prompts the user for input
*/

#include <stdio.h>
#include <stdlib.h>

char *read_line();
void write_to_log(char *input);

int main()
{
    read_line();
}

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

    write_to_log(input);

    return input;
}

/**
* Writes input to log file
*/
void write_to_log(char *input)
{
    FILE * log;
    log = fopen("log.txt", "a");
    fprintf(log, "\nInput returned form read_line(): %s", input);
    fclose(log);
}

