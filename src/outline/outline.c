#include "../includes/outline.h"

/**
 * Outputs the result to the user
 **/
int outline(char * output) {
	
	log_output("Entering outline");
	
	int ret;
	
	if ((ret = printf("%s\n", output)) < 0) {
		log_output("Failed to output the result of the test\n");
	} else {
		ret = 0;
	}
	
	log_output(output);
	
	return ret;
}


