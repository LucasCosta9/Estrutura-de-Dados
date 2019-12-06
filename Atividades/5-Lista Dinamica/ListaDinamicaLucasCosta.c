/*
/*Autor: Lucas Costa Bezerra (20180000247)
/Programa com funcoes de lista com alocação dinamica 
*/

//PROTOTIPOS

#include <stdio.h>
#include <stdlib.h>


struct caixa{
    int dado; //Valor do struct caixa
    struct caixa *prox; //Ponteiro que vai apontar para o próximo da lista
    
};  

//Prototipo
struct caixa* criar_lista(); //Retorna valor 0 para ser usado na criação de uma lista 
void inserir_inicio(int valor , struct caixa**); //Insere um inteiro no inicio da lista 
void  inserir_final(int valor,struct caixa**); //Insere um inteiro no final da lista
void remocao_inicio(struct caixa**); //Remove o primeiro da lista
void  remocao_final(struct caixa**); //Remove o ultimo da lista
void listar(struct caixa**); //Lista todos da lista 
void eh_vazia(struct caixa**); //Diz se a lista eh vazia ou nao
void limpar(struct caixa**); //Limpa a lista 



//CRIAR LISTA
struct caixa* criar_lista(){
    return(0); //Retorna 0 para se usada para apontar o valor inicial da lista
}

//INSERIR NO INICIO
void inserir_inicio(int valor, struct caixa**lista){
	struct caixa *laux; //Ponteiro auxiliar
	laux = (struct caixa *)malloc(sizeof(struct caixa)); //Alocando espaço na memoria

	if (laux == 0){//Caso a memoria estourar
		printf("\n Funcao nao realizada por falta de memoria\n");
	return;	
}

	laux->dado =valor; //Valor do ponteiro auxiliar (O que foi determinado como um parâmetro)
	laux -> prox = *lista; //Faz o ponteiro auxiliar apontar para o primeiro da lista principal
	*lista = laux; //Faz a lista apontar para o ponteiro auxiliar

}

//INSERIR NO FINAL
void  inserir_final(int valor,struct caixa**lista){
	struct caixa *laux,*laux2; //laux para chegar ao ultimo termo e laux2 para armazenar o valor dado como parâmetro
	laux = (struct caixa *)malloc(sizeof(struct caixa)); //Alocando espaco na memoria

	if (laux == 0){//Caso a memoria estourar
		printf("\n Funcao nao realizada por falta de memoria\n");
		return;
	}

	laux2 = (struct caixa*)malloc(sizeof(struct caixa)); //Alocando espaco na memoria

	if (laux2 == 0){//Caso a memoria estourar
		printf("\n Funcao nao realizada por falta de memoria\n");
		return;	
	}

	laux2->dado = valor; //Guardar o valor  
	laux2-> prox= 0; //Faz o laux 2 apontar para zero (como ele vai ser o ultimo da lista)

	if (*lista ==0){ //Caso a lista estiver vazia
		*lista = laux2;//Fazer a lista apontar diretamente para laux2
		return;
	}

	for(laux=*lista; laux->prox!=0;laux=laux->prox);//Vai até o ultimo 

	laux->prox = laux2; //Faz o ultimo apontar para o laux2, dessa forma o laux2 se torna o novo "ultimo da lista"
}


//REMOÇÃO NO INICIO	
void remocao_inicio(struct caixa**lista){

	struct caixa *laux; //Cria ponteiro auxiliar
	laux = (struct caixa *)malloc(sizeof(struct caixa)); //Alocando espaco na memoria

	if (laux == 0){ //Caso a memoria estourar
		printf("\n Funcao nao realizada por falta de memoria\n");
		return;	
	}

	laux = *lista; //Faz laux apontar para o primeiro da lista

	if(laux ==0){ //Caso a lista ja estiver vazia 
		printf("\nLista ja esta vazia\n");
		return;
}

	laux =laux->prox; //Apontar pro segundo elemento
	*lista=laux; //Faz a lista apontar para o segundo elemento 
}

//REMOVER NO FINAL
void  remocao_final(struct caixa**lista){
	struct caixa *laux,*anterior; //Ponteiro auxiliar
	laux = (struct caixa *)malloc(sizeof(struct caixa)); //Alocacao de memoria 

	if (laux == 0){ //Caso a memoria estourar
		printf("\n Funcao nao realizada por falta de memoria\n");
		return;	
	}

	if (*lista ==0){ //Caso a lista estiver vazia
		printf("\nLista ja esta vazia\n");
		return;
	}

	for(laux=*lista; laux->prox!=0;anterior=laux,laux=laux->prox);//Vai até o ultimo e salva o penultimo 

	if(laux == *lista){ 
		*lista=0; //Apontar diretamente a lista a 0 quando so tiver um elemento
		}else {
			anterior->prox=0; //Fazer o anterior apontar para 0 (esquecendo o ultimo)
		}
	free(laux); //Liberar da memoria o ultimo valor 
}


//LISTAR
void listar(struct caixa**lista){
	struct caixa *laux; //Cria ponteiro auxiliar 
	laux = (struct caixa *)malloc(sizeof(struct caixa));//Alocacao de Memoria 

	if(laux ==0){ //Caso a lista ja estiver vazia 
		printf("\nLista ja esta vazia\n");
		return;
	}
		printf("\n"); //Print para organizar a listagem 
		for (laux=*lista;laux!=0;laux=laux->prox){ //Iterar até o final da lista 
			printf("%d",laux->dado); //Printar cada elemento 
		}
		printf("\n"); //Print para organizar a listagem
}

//VER SE EH VAZIA
void eh_vazia(struct caixa**lista){
	struct caixa *laux; //Criacao de ponteiro auxiliar
	laux = (struct caixa *)malloc(sizeof(struct caixa)); //Alocacao de Memoria

	if (laux == 0){ //Caso a memoria estourar
		printf("\n Funcao nao realizada por falta de memoria\n");
	return;	
	}

	laux = *lista;  //laux apontando para o começa da lista

	if (laux == 0){ //Se o primeiro elemento for zero, entao eh vazia
		printf("\nLista eh vazia\n");

	}else{ //Se o primeiro elemento nao for zero, entao nao eh vazia
		printf("\nLista nao eh vazia\n");
	}
}
//LIMPAR
void limpar(struct caixa**lista){
	struct caixa *laux; //Criar ponteiro auxiliar
	laux = (struct caixa *)malloc(sizeof(struct caixa)); //Alocacao de memoria

	if (laux == 0){ //Caso a memoria estourar
		printf("\n Funcao nao realizada por falta de memoria\n");
		return;	
	}

	for(laux=*lista;laux!=0;laux=*lista){ //Iterar sobre todos da lista
			*lista=laux->prox; 
			free(laux); //Liberar memoria 
		}
		free(*lista); //Liberar a lista principal
}


//**********************************MENU***********************************
int main(){
	printf("Bem vindo ao programa de funçoes de alocações dinâmicas\n");
	struct caixa*lista; //Tive que colocar aqui em cima para não dar problema com o compilador
	lista = (struct caixa *)malloc(sizeof(struct caixa)); //Alocacao de memoria

	if (lista == 0){ //Caso a memoria estourar
		printf("\n Funcao nao realizada por falta de memoria\n");
		return;	
	}

	int lista_criada = 0; //1 Se tiver uma lista criada, 0 caso nao
	int numero;//Numero usado para escolher as opcoes  
	int numero2;//Numero usado nas insercoes 
	while(1){//Loop infinito principal

		//Loop que depende se existe uma lista ou nao
		while(lista_criada == 0){ //Caso a lista ainda nao tiver sido criada
			printf("\nEscolha uma opcao\n 1-Criar lista \n 0-Sair do programa\n");
			scanf("%d", &numero); //Pegar o numero inserido pelo usuário

			switch (numero){ 
			case 0: //Sair do programa
			printf("\nPrograma finalizado\n");
			return 0;
			break;

			case 1://Criar lista 
			lista = criar_lista();
			printf("\nLista criada\n");
			lista_criada =1;
			break;
			
			default://Opcao invalida
			printf("\nOpcao invalida\n");
			break;

		}
		while(lista_criada ==1){ //Caso a lida tiver sido criada 
			
			printf("\nEscolha uma opcao\n 1-Inserir no inicio\n 2-Inserir no final\n 3-Remover no Inicio" 
				"\n 4-Remover no final \n 5-Listar \n 6-Ver se eh vazia \n 0-Limpar lista \n ");

		scanf("%d", &numero); //Pegar o numero inserido pelo usuário
		switch (numero){ 

			case 0: //Limpar lista
			limpar(&lista);
			printf("\nLista apagada\n");
			lista_criada =0; //Marcar como 0 o identificador de lista 
			break;

			case 1: //Inserir no inicio
			printf("\nDigite o inteiro que quer inserir\n");
			numero2 = -1;//Valor padrao para não ser aceito por engano
			scanf("%d", &numero2); //Pegar o numero inserido pelo usuário
				if (numero2==0){
					printf("\nNao se pode adicionar 0 nesta lista, numero recusado\n");
				}else{
					inserir_inicio(numero2,&lista);
					printf("\nNumero %d, inserido com sucesso\n",numero2);
				}
			break;

			case 2: //Inserir no final 
			printf("\nDigite o inteiro que quer inserir\n");
			numero2 = -1;//Valor padrao para não ser aceito por engano
			scanf("%d", &numero2); //Pegar o numero inserido pelo usuário
				if (numero2==0){
					printf("\nNao se pode adicionar 0 nesta lista, numero recusado\n");
				}else{
					printf("\nNumero %d, inserido com sucesso\n",numero2);
					inserir_final(numero2,&lista);
				}
			break;

			case 3: //Remover no inicio
			remocao_inicio(&lista);
			break;

			case 4:// Remover no final
			remocao_final(&lista);
			break;

			case 5://Listar
			listar(&lista);
			break;

			case 6://Ver se eh vazia
			eh_vazia(&lista);
			break;

			default:
			printf("\nOpcao invalida\n");
			break;

		}

	}

}
}
}