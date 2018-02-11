#include <stdio.h>
#include "log_output.h"

/**
* Writes a message to a log text file
*/
int log_output(char* message)
{
	FILE* fp;
    fp = fopen("log.txt", "a");
	fprintf(fp, "%s\n", message);
	fclose(fp);
}