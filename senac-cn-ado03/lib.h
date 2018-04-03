#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern FILE *popen( const char *command, const char *modes);
extern int pclose(FILE *stream); 
void calc_float();
void calc_double();
void calc_ldouble();