#include <stdio.h>
#include "log_output.h"

/**
* Writes a message to a log text file
*/

int log_output(char * message) {

	FILE * fp;
	
    // fopens log.txt to append a message
	fp = fopen("log.txt", "a");

	// appends message to log.txt file
	fprintf(fp, "%s\n", message);

	fclose(fp);
}