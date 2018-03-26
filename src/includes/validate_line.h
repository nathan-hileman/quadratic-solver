/* Command Line Quadratic Solver
   TEAM: Ali Itani, Nathan Hleman, Xavier Gray
   Kapenga Inc., LICENSE: GPL 2.0      */
/* header file for validate_line.c inlcudes needed functions for this source code. */

int is_empty(char * line);

int is_number(char * result);

int check_validation(char * line, int n, float * a, float * b, float * c);

char *trimwhitespace(char *str);