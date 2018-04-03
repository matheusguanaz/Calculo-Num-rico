#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"

int main(){
	calc_float();
	calc_double();
	calc_ldouble();
	remove("float.txt");
	remove("double.txt");
	remove("ldouble.txt");
	
}