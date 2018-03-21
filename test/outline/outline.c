#include "outline.h"

int outline(char * output){
	int ret;
	if ((ret = printf("%s\n", output)) < 0){
	}
	else
		ret = 0;

	return ret;
}

int main(int argc, char const *argv[])
{
	int ret;	// variable for return values
    cunit_init();

    /*TEST 1: Null-terminated string */
    cunit_print("\nTEST 1: Null-terminated string");

    char* str1 = "This is a test string\0";
    ret = outline(str1);
    cunit_print("\n\tResults: ");
    assert_eq("\n\tCUNIT ERROR: Reason...", ret, 0);

    /*TEST 2: Un-terminated string */
    cunit_print("\nTEST 2: Un-terminated string");

    char* str2 = "This is a test string";
    ret = outline(str2);
    cunit_print("\n\tResults: ");
    assert_eq("\n\tCUNIT ERROR: Reason...", ret, 0);

    /*TEST 3: empty string */
    cunit_print("\nTEST 3: empty string");

    ret = outline("");
    cunit_print("\n\tResults: ");
    assert_eq("\n\tCUNIT ERROR: Reason...", ret, 0);

	return 0;
}