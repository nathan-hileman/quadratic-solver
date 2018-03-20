#include <stdio.h>
#include "log_output.h"

/**
* Logs a message to a file - log.txt
*/

int log_output(char * message) {

	FILE * fp;
	
    // fopens file to append a message

	fp = fopen("log.txt", "a"); 

	// using fprintf to log a formated output to stream

	fprintf(fp, "%s\n", message);

	// close file

	fclose(fp);
	
	return 0;
}