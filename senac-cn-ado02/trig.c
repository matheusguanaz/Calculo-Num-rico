#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"

int main(){
	calc_sin();
	calc_cos();
	remove("seno.txt");
	remove("cosseno.txt");
}