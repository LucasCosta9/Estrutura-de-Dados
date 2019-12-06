/*
/*Autor: Lucas Costa Bezerra (20180000247)
/*Programa para criar uma array que armazena memória dinamicamente para 20 nomes 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void){
	//Lista que vai armazenar memória dinamicamente para os 20 nomes
	char **vp; //Ponteiro pra uma array de ponteiros
	vp = (char**)malloc(20*sizeof(char*)); //Criar espaço pra 20 nomes
	if (!vp){//Caso não tiver memoria
		printf("Sem memoria");
		return 0;
	}
	//Lista para armazenar os 20 nomes temporariamente
	char **nome; //Ponteiro pra uma array de ponteiro
	nome = (char**)malloc(20*sizeof(char*)); //Criar espaço pra 20 nomes
	if (!vp){ //Caso não tiver memoria
		printf("Sem memoria");
		return 0;
	}
	//lista dos 20 nomes
	nome[0] = "Jose";
	nome[1] = "Matheus";
	nome[2] = "Julia";
	nome[3] = "Luigi";
	nome[4] = "Pedro";
	nome[5] = "Elias";
	nome[6] = "Fernanda";
	nome[7] = "Ryan";
	nome[8] = "Willian";
	nome[9] = "Joninhas";
	nome[10] = "Jamal";
	nome[11] = "Maria";
	nome[12] = "Ingrid";
	nome[13] = "Iris";
	nome[14] = "Sebastiao";
	nome[15] = "Bruno";
	nome[16] = "Gabriel";
	nome[17] = "Michael";
	nome[18] = "Vincent";
	nome[19] = "Eduardo";



	//Colocar o tamanho certo de cada nome 
	int i = 0;
	for  (i = 0;i<20;i++){
	int tamanho = strlen(nome[i]); //Tamanho do nome que o "for está passando"
	vp[i] = (char*)malloc(tamanho*sizeof(char)); //Colocar o tamanho
	vp[i] = nome[i]; //Colocar o nome
	}
	
	//Printar todos os nomes 
	for (i=0;i<20;i++){
	printf("%s\n",vp[i]);
	}

	//Liberar memoria
	for (i=0;i<20;i++){
		free(vp[i]); //Lista principal (nomes)
		free(nome[i]); //Lista temporaria (nomes)
	}
	free(vp); //Liberar ponteiro da lista principal
	free(nome); //Liberar ponteiro da lista temporaria

return 0;
}



