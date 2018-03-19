#include <stdio.h>

int outline(char * output){
	int ret = 0;
	if ((ret = printf("%s\n", output)) < 0)
		perror("Failed to output the result of the test: ");
	return ret;
}

int main (void){
	int ret = outline("Test string 1 2 3");
	return 0;
}
