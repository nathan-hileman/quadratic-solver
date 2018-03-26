/* Command Line Quadratic Solver
   TEAM: Ali Itani, Nathan Hleman, Xavier Gray
   Kapenga Inc., LICENSE: GPL 2.0      */
#include <stdio.h>

int main(void)
{
	log_str("hello world");
}

int log_str(char* message)
{
	FILE* fp;
	if ((fp = fopen("logfile", "a")) == null)
		return -1;

	fprintf(fp, "%s\n", message);
	fclose(fp);
}