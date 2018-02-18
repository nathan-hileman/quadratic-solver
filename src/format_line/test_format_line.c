#include "format_line.c"

int main(void){
	struct out_args args;
	args.x = 4;
	args.a = 1;
	args.b = 2;
	args.c = 3;
	args.real_solution = 1;
	args.double_solution = 1;
	int ret = format_line(&args);
	printf("%s\n", args.output_string);
	return 0;
}
