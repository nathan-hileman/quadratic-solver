#include <stdio.h>
#include "log_output.h"

/**
* Logs a message to a file - log.txt
*/

int log_output(char * message) {

	FILE * fp;
	
    // Function fopen opens a file to append a message to. 

	fp = fopen("log.txt", "a"); 

	// Function fprintf logs a message to stream. 

	fprintf(fp, "%s\n", message);

	// Close file when done appending. 

	fclose(fp);
	
	return 0;
}