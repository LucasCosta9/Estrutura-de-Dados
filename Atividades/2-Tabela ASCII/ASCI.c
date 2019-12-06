//Programa para escrever tabela ASCII
//Autor: Lucas Costa Bezerra (20180000247)
#include <stdio.h>
#include <stdlib.h>

main(){

	FILE*arq; //Ponteiro para arquivo
	arq= fopen("tabela_ascii.txt","w"); //Criar arquivo txt
	fprintf(arq,"-----Tabela ASCII-----\n");
			
	int i;
	for (i = 0; i<256; i++){ //Gerar tabela 
			fprintf(arq,"%d,%c \n",i,i); //Printar caractere com seu código do ASCII
	}
	
	fclose(arq); //Fechar arquivo 
}


