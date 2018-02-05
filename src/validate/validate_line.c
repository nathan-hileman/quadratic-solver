/*
    Author: Ali Itani
*/

#include <stdio.h> // needed
#include <stdlib.h> // needed
#include <string.h> // for strtok() and more
#include <math.h> // for isnan()

// function that checks if an input is empty

int is_empty(char * line) { 
    return (line[0] == '\0') ? 1 : 0;
}

// checks whether the arguments contain numbers or characters 

int is_number(char * result) {
    
    char * ptr;
    double ret;


    // strtod checks input if its a number or a character.
    ret = strtod(result, &ptr);

    if(strlen(ptr) != 0) {
        printf("Error: Not a number, character was inserted instead.\n");
        exit(-1); // or return -1 doesnt matter, i like exit more...
    }

    return 1;
}

// validator function that checks for possible errors and reports back to user with a result

int check_validation(char * line) {


    // checks if line is empty using [is_empty] function
    
    if ( is_empty(line) ){
        
       printf("Error: Line is empty.\n");
        exit(-1); // or return -1 doesnt matter, i like exit more...
   }


    // splits the string with values

    char * numbers = strtok(line, " ");
    char * results[3];
    double a, b, c;

    int i = 0;

    // loops through line, tokenizes, and assigns values to char * results
    while (numbers != NULL) { 
        if(i < 3) {
            results[i++] = numbers;
        }
        numbers = strtok(NULL, " ");
    }

    // checks if numbers are not empty

    if (results[0] == '\0' || results[1] == '\0' || results[2] == '\0') {
        printf("Error: Missing arguments of a, b, c.\n");
        return -1;
    }
    
    // checks if numbers are all valid
    
   if (is_number(results[0]) && is_number(results[1]) && is_number(results[2])) {
        
        a = atof(results[0]);
        b = atof(results[1]);
        c = atof(results[2]);
        
        printf("Numbers are valid they are: %.7lf %.7lf %.7lf\n", a, b, c);

    } else {

        printf("Error: Not a Number.\n");
        
        return -1;
    }

    // if all checks went through should reach here and return 0
    return 0;
}


// this main is just for testing, should be removed later on!
int main(int argc, char ** argv) {
    
    // testing
    char * line = (char *) malloc(100);
    
    strcat(line, "2016.12124 2017.2342 2018.1234567");

    printf("\n\nTesting\nLine, as sent by cmd line:");
    printf("%s\n", line);
    printf("Result: ");
    
    check_validation(line);
    
    printf("\n\n");

    return 0;
}
