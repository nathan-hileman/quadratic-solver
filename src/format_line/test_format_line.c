
#include "format_line.c"

int main(void){
	struct out_args args;
	args.root_1 = 4;
	args.root_2 = 18;
	args.a = 1;
	args.b = 2;
	args.c = 3;
	args.solution = 0;
	int ret = format_line(&args);
	printf("%s\n", args.output_string);

	args.solution = 1;
        ret = format_line(&args);
        printf("%s\n", args.output_string);

	args.solution = 2;
	ret = format_line(&args);
        printf("%s\n", args.output_string);


	return 0;
}
