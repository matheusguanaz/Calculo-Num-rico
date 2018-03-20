#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int transformar_para_base10(int *vetor, int tamanho, int base_atual){
	int valor=0, i;
	int trans[10];

	trans[0]=1;
	trans[1]=base_atual;
	trans[2]=base_atual*base_atual;
	trans[3]=base_atual*base_atual*base_atual;
	trans[4]=base_atual*base_atual*base_atual*base_atual;
	trans[5]=base_atual*base_atual*base_atual*base_atual*base_atual;
	trans[6]=base_atual*base_atual*base_atual*base_atual*base_atual*base_atual;
	trans[7]=base_atual*base_atual*base_atual*base_atual*base_atual*base_atual*base_atual;
	trans[8]=base_atual*base_atual*base_atual*base_atual*base_atual*base_atual*base_atual*base_atual;
	trans[9]=base_atual*base_atual*base_atual*base_atual*base_atual*base_atual*base_atual*base_atual*base_atual;

	if(tamanho==8 && vetor[0]>17){
		printf("Mantissa muito grande\n");
		exit(1);
	}
	if(tamanho==9 && vetor[0]>1){
		printf("Mantissa muito grande\n");
		exit(1);
	}
	if(tamanho==9 && vetor[1]>9){
		printf("Mantissa muito grande\n");
		exit(1);
	}

	for(i=0; i<tamanho; i++){
		valor+=trans[i]*vetor[tamanho-1-i];
	}

	return valor;
}
void transformar_para_base_desejada(int valor, int base_desejada){

	int *quociente, *resto, *resposta_final;
	int i,j,k;
	quociente=(int*)calloc(32,sizeof(int));
	resto=(int*)malloc(32*sizeof(int));
	resposta_final=(int*)calloc(32,sizeof(int));

	quociente[0]=valor/base_desejada;
	resto[0]=valor % base_desejada;
	resposta_final[0]=resto[0];

	for(i=1; quociente[i-1]>=base_desejada;i++){
		quociente[i]=quociente[i-1]/base_desejada;
		resto[i]=quociente[i-1] % base_desejada;
		resposta_final[i]=resto[i];
	}
	k=i;
	resposta_final[k]=quociente[i-1];
	for(j=0; j<k+1;j++){
		if(resposta_final[j]>9){
			resposta_final[j]=resposta_final[j]+55;
		}else{
			resposta_final[j]=resposta_final[j]+48;
		}
	}
	for(j=k; j>=0;j--){
		printf("%c", resposta_final[j]);
	}


	free(resto);
	free(resposta_final);
	free(quociente);

}