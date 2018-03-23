#include "../includes/outline.h"
#include <stdio.h>

/**
 * Outputs the result to the user
 **/
int outline(char * output) {
	
	int ret;
	
	if ((ret = printf("%s\n", output)) < 0) {
		log_output("\tERROR: Failed to output the result of the test\n");
	} else {
		ret = 0;
	}

	char final_output[256];
	snprintf(final_output, sizeof final_output, "\t%s", output);

	log_output(final_output);
	
	return ret;
}


