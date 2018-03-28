#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calc_sin();
double calc_serie(double valor, int i);
double calc_fatorial(double valor);
void calc_cos();
extern FILE *popen( const char *command, const char *modes);
extern int pclose(FILE *stream); 
