#include <stdio.h>
#include <stdlib.h>
#include "lib.h"


int main(int argc, const char *argv[]){
	int t,i, base_atual, base_desejada, conversao[32], valor_em_base10;
	for(i=0; i<argc;i++){
	}

	 
	 for(i=0; argv[1][i]!='\0';i++){
	 		conversao[i]=argv[1][i];	
	 }

	if(argc>4){
		printf("Muitos parametros digitados\n");
		exit(1);
	}

	base_atual=atof(argv[2]);
	if(base_atual<1 || base_atual>=37){
		printf("Valor de base atual incorreto\n");
		exit(1);
	}
	base_desejada=atof(argv[3]);
	if(base_desejada<1 || base_desejada>=37){
		printf("Valor de base desejada incorreto\n");
		exit(1);
	}

//24963829878
	for(t=0; t<i;t++){
		if(conversao[t]>64 && conversao[t]<90){
			conversao[t]= conversao[t]-55;
		}
		else if(conversao[t]>=97){
			conversao[t]= conversao[t] -87;
		}
		else if(conversao[t]>47 && conversao[t]<=57){
			conversao[t]= conversao[t]-48;
		}
		else{
			printf("Caractere digitado inválido\n");
			exit(1);
		}
	}

	 for(t=0;t<i;t++){
	 	if(conversao[t]>base_atual || conversao[t]<0){
	 		printf("Valor da base atual incorreto\n");
	 		exit(1);
	 	}
	 }
	 if(i>10){
	 	printf("Mantissa muito grande\n");
	 	exit(1);
	 }

	valor_em_base10 = transformar_para_base10(conversao, i, base_atual);
	transformar_para_base_desejada(valor_em_base10, base_desejada);

}
