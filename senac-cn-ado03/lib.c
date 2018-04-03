#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"

void calc_float(){
	float  divisao,total, expoente, soma;
	double i;
	FILE *arq,*pipe;
	arq=fopen("float.txt","wb");
	if (arq == NULL) // Se não conseguiu criar
    {
        printf("Problemas na CRIACAO do arquivo\n");
   		exit(1);
	}

	for(i=0;i<20;i+=0.001){
		expoente=pow(10,i);
		divisao=1.00000000000000000000000000/expoente;
		soma= divisao +1.00000000000000000000000;
		total= pow(soma, expoente);
		printf("10^%lf    %.20f\n",i,total);
		fprintf(arq, "%f %f\n",expoente,total);
	}
	fclose(arq);
	pipe=popen("gnuplot","w");
	fprintf(pipe, "set terminal png size 600,400\nset logscale x 10\nset title'Euler'\nset xlabel 'X'\nset ylabel 'Y'\nset output'euler_flt.png'\nplot'float.txt' title'Euler' with lines\n");
	pclose(pipe);
}

void calc_double(){
	double  divisao,total, expoente, soma;
	double i;
	FILE *arq,*pipe;
	arq=fopen("double.txt","wb");
	if (arq == NULL) // Se não conseguiu criar
    {
        printf("Problemas na CRIACAO do arquivo\n");
   		exit(1);
	}

	for(i=0;i<20;i+=0.001){
		expoente=pow(10,i);
		divisao=1.00000000000000000000000000/expoente;
		soma= divisao +1.00000000000000000000000;
		total= pow(soma, expoente);
		printf("10^%lf    %.20lf\n",i,total);
		fprintf(arq, "%lf %lf\n",expoente,total);
	}
	fclose(arq);
	pipe=popen("gnuplot","w");
	fprintf(pipe, "set terminal png size 600,400\nset logscale x 10\nset title'Euler'\nset xlabel 'X'\nset ylabel 'Y'\nset output'euler_dbl.png'\nplot'double.txt' title'Euler' with lines\n");
	pclose(pipe);
}

void calc_ldouble(){
	long double  divisao,total, expoente, soma;
	double i;
	FILE *arq,*pipe;
	arq=fopen("ldouble.txt","wb");
	if (arq == NULL) // Se não conseguiu criar
    {
        printf("Problemas na CRIACAO do arquivo\n");
   		exit(1);
	}

	for(i=0;i<20;i+=0.001){
		expoente=pow(10,i);
		divisao=1.00000000000000000000000000/expoente;
		soma= divisao +1.00000000000000000000000;
		total= pow(soma, expoente);
		printf("10^%lf    %.20Lf\n",i,total);
		fprintf(arq, "%Lf %Lf\n",expoente,total);
	}
	fclose(arq);
	pipe=popen("gnuplot","w");
	fprintf(pipe, "set terminal png size 600,400\nset logscale x 10\nset title'Euler'\nset xlabel 'X'\nset ylabel 'Y'\nset output'euler_ldbl.png'\nplot'ldouble.txt' title'Euler' with lines\n");
	pclose(pipe);
}