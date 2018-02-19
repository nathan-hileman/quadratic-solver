#include <stdio.h>

int main(void)
{
	log_str("hello world");
}

int log_str(char* message)
{
	FILE* fp;
	if ((fp = fopen("logfile", "w")) == null)
		return -1;

	fprintf(fp, "%s\n", message);
	fclose(fp);
}