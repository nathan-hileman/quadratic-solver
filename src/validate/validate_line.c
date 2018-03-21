/*
    Author: Ali Itani
*/

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>     
#include <math.h> 
#include "../includes/validate_line.h"
#include "../includes/log_output.h"
#include "ctype.h"

/* Function that checks if an input is empty. */
int is_empty(char * line) { 
    // return result
    return line[0] == '\n';
}

/* Function that trims trailing white spaces. */
char *trimwhitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)){ 
        str++;
    }
        
    // All spaces?
    if (*str == 0) {  
        return str;
    }

    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) {
        end--;
    }

    // Write new null terminator
    *(end+1) = 0;

    // return result 
    return str;
}

/* Function is_number checks whether the arguments contain numbers or characters. */
int is_number(char * result) {
    
    char * ptr;
    double ret;


    // Function strtod checks input if its a number or a character. 
    ret = strtod(result, &ptr);
    if(strlen(ptr) > 0) {
        return -1;
    }

    return 0;
}

/** 
 * Validator function that checks for possible errors. 
 * Returns an int with the possible result.
 * */
int check_validation(char * line, int n, float * a, float * b, float * c) {
    
    // checks if line is empty using [is_empty] function
    int ret  = is_empty(line);
    char * new_line = trimwhitespace(line);

    if ( ret ){

        log_output("Error: Line is empty.\n");

        return -1; 
   }


    // splits the string with values
    char * numbers = strtok(new_line, " ");
    char * results[3];
    int i = 0;

    // loops through line, tokenizes, and assigns values to char * results
    while (numbers != NULL) { 
        if (i < 3) {
            results[i++] = numbers;
        }
        
        numbers = strtok(NULL, " ");
    }
    
    // checks if there are no missing arguments 
    if (i < 3) {
        log_output("Error: Missing arguments of a, b, c.\n");
        return -1;
    }
    
    results[2] = strtok(results[2], "\n");
        
    // checks if numbers are all valid
    int ret1 = is_number(results[0]);
    int ret2 = is_number(results[1]);
    int ret3 = is_number(results[2]);
    
    if (is_number(results[0]) == 0 && is_number(results[1]) == 0 && is_number(results[2]) == 0) {
        // number are valid. Assign them to each variable respectively.
        *a = atof(results[0]);
        *b = atof(results[1]);
        *c = atof(results[2]);
        
    } else {
        
        log_output("Error: Not a number, character was inserted instead.\n");        
        return -1;
    }

    // if all checks went through should reach here and return 0
    return 0;
}


// this main is just for testing, should be removed later on!
// int main(int argc, char ** argv) {
    
//     // testing
//     int n = 100;
//     float a = 0.0;
//     float b = 0.0;
//     float c = 0.0;
//     char * line = (char *) malloc(100);
//     strcat(line, "2016.12124 2017.0e6 2500.0e-5");

//     printf("\n\nTesting\nLine, as sent by cmd line:");
//     printf("%s\n", line);
//     printf("Result: ");
//     check_validation(line, n, &a, &b, &c);
    
//     printf("\n\n");

//     return 0;
// }
