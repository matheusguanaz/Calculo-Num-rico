#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"



void calc_sin(){
	int i;
	FILE *arq, *arq1, *pipe;
	double vetor_sin[125665];
	double j=0,k=0,erro_abs, erro_rel;

	arq=fopen("seno.dat", "wb");
	arq1=fopen("seno.txt", "wb");
	pipe=popen("gnuplot","w");
	
	if (arq == NULL) // Se não conseguiu criar
    {
        printf("Problemas na CRIACAO do arquivo\n");
   		exit(1);
    }

	for(i=0; i<125664;i++){
		j=j+0.0001;
		k=k+0.0001;
		vetor_sin[i]=calc_serie(j,1);
		if(j>6.28){
			j=0;
		}
		erro_abs= sin(k)- vetor_sin[i];
		if(erro_abs<0){
			erro_abs*=-1;
		}
		erro_rel= erro_abs/vetor_sin[i];
		if(erro_rel<0){
			erro_rel*=-1;
		}
		fprintf(arq,"%lf\t %lf\t  %lf\t %lf\n",k,vetor_sin[i], erro_abs, erro_rel);
		fprintf(arq1,"%lf %lf\n",k,vetor_sin[i]);
	}
	fprintf(pipe, "set terminal png size 600,400\nset title'Seno'\nset xlabel 'X'\nset ylabel 'Y'\nset output'seno.png'\nplot'seno.txt' title'Seno' with lines\n");
	fclose(arq);
	fclose(arq1);
	pclose(pipe);

}

void calc_cos(){
	int i;
	FILE *arq, *arq1, *pipe;
	double vetor_cos[125665];
	double j=0,k=0,erro_abs, erro_rel;

	arq=fopen("cosseno.dat", "wb");
	arq1=fopen("cosseno.txt", "wb");
	pipe=popen("gnuplot","w");
	
	if (arq == NULL) // Se não conseguiu criar
    {
        printf("Problemas na CRIACAO do arquivo\n");
   		exit(1);
    }

	for(i=0; i<125664;i++){
		j=j+0.0001;
		k=k+0.0001;
		vetor_cos[i]=calc_serie(j,0);
		if(j>6.28){
			j=0;
		}
		erro_abs= cos(k)- vetor_cos[i];
		if(erro_abs<0){
			erro_abs*=-1;
		}
		erro_rel= erro_abs/vetor_cos[i];
		if(erro_rel<0){
			erro_rel*=-1;
		}
		fprintf(arq,"%lf\t %lf\t  %lf\t %lf\n",k,vetor_cos[i], erro_abs, erro_rel);
		fprintf(arq1,"%lf %lf\n",k,vetor_cos[i]);
	}
	fprintf(pipe, "set terminal png size 600,400\nset title'Cosseno'\nset xlabel 'X'\nset ylabel 'Y'\nset output'cosseno.png'\nplot'cosseno.txt' title'Cosseno' with lines\n");
	fclose(arq);
	fclose(arq1);
	pclose(pipe);

}

double calc_serie(double valor, int i){
	int j=1,k=0;
	double fat;
	double *vetor;
	vetor=(double*)calloc(19, sizeof(double));
	double result=0;

	while(i<22){
		fat=calc_fatorial(i);
		vetor[k]=pow(valor,i)/fat;
		i=i+2;
		k++;
	}
	j=1;
	for(i=0; i<11;i++){
		if(j==1){
			result=result+vetor[i];
			j=0;
			//printf("%lf\t",result);
			continue;
		}
		if(j==0){
			result=result-vetor[i];
			j=1;
			//printf("%lf\n",result);
			continue;
		}
	}
	return result;
}
double calc_fatorial(double valor){
	unsigned long long int i;
	double result=1;

	for(i=0;i<valor;i++){
		result=(valor-i)*result;
	}
	return result;
}