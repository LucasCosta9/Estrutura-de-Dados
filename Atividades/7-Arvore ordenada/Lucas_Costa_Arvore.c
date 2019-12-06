/*
Autor: Lucas Costa Bezerra  20180000247
Programa com funções de uma árvore binária 
*/
#include <stdio.h>	
#include <stdlib.h>

struct no {
	
	int info; //Valor do noh
	struct no * sad; //Ponteiro para direita
	struct no * sae; //Ponteiro para esquerda
	
};

//Prototipos
struct no *insere(int val, struct no* tree);
struct no *insere_ordenado(struct no* arv, int valor);
struct no* criar_arvore();
struct no* remove_folha(struct no* arv, struct no* anterior, int numero);
struct  no* limpar (struct no* arv);
void prefix(struct no* arv);
void infix(struct no* arv);
void posfix(struct no* arv);
int buscar(struct no* arv, int numero);


//MAIN
int main (void){
	struct no * arvore_principal = 0;
	
	while (1){ //Loop infinito do menu 
		printf("Digite a sua opcao\n");
		printf("1 = Insere Ordenado\n");
		printf("2 = Remove Folha\n");
		printf("3 = Mostrar Prefix\n");
		printf("4 = Mostrar Infix\n");
		printf("5 = Mostrar Posfix\n");
		printf("0 = Finalizar programa");
		
		int entrada;
		scanf("%d", &entrada);
		
		switch (entrada){
			case 0:
			printf("Programa finalizado");
			return 0;
			break;
			
			case 1:
			printf("Digite o valor que quer inserir\n");
			
			int entrada2;
			scanf("%d", &entrada2);
			
			arvore_principal = insere_ordenado(arvore_principal,entrada2);
			break;
			
			case 2:
			printf("Digite o valor que quer remover da folha\n");
			
			int entrada3;
			scanf("%d", &entrada3);
			remove_folha(arvore_principal,0,entrada3);
			break;
			
			case 3:
			prefix(arvore_principal);
			break;
			
			case 4:
			infix(arvore_principal);
			break;
			
			case 5:
			posfix(arvore_principal);
			break;
			
			
			default:
			break;
			
		}
		
	
	}
	return 0;
}

//Insere Ordenado 
struct no *insere_ordenado(struct no* arv, int valor){
		if (arv != NULL){
				if (arv->info>valor){ //Colocar na esquerda caso o valor inserido seja menor que o noh
					arv->sae = insere_ordenado(arv->sae,valor);
				}else{ //Colocar na direita caso contrario
				arv->sad = insere_ordenado(arv->sad,valor);
			}
		}else{ //Adicionar o noh na posicao correta 
			arv = (struct no*)malloc(sizeof(struct no));
			
			arv -> info = valor;
			arv -> sad = NULL;
			arv -> sae = NULL;
			printf("Valor %d inserido na arvore\n",valor);
			return arv;
		}
		
}
//Criar arvore
struct no* criar_arvore(){
	return 0;
}
//Remover folha
struct no* remove_folha(struct no* arv, struct no* anterior, int numero){
	if(buscar(arv,numero)){
		if(arv->info == numero){
			if(anterior ==0){
				anterior = limpar(anterior);
				printf("Arvore esvaziada\n");
				return arv;
				}
			if(anterior->info>numero){
				anterior->sae = 0;
			}
			if(anterior->info<numero){
				anterior->sad = 0;
			}
			arv = limpar(arv);
			return anterior;
		}else{
			struct no* aux;
			if(buscar(arv->sae,numero)){
				aux = remove_folha(arv->sae,arv, numero);
				return arv;
			}
			if(buscar(arv->sad,numero)){
				aux = remove_folha(arv->sad,arv,numero);
				return arv;
			}
			
		}
		
	}
	else{
			printf("Numero nao esta na arvore\n");
			return arv;
	}			
}



//Limpar
struct  no* limpar (struct no* arv){
	if (arv!=NULL){
		limpar(arv->sae);
		limpar(arv->sad);
		free(arv);
	}
	return criar_arvore(); //Retornar arvore vazia
}




//Prefix
void prefix(struct no* arv){  //R SAE SAD 
	if (arv != NULL){
		printf("%d",arv->info); //Noh principal 
		prefix(arv->sae); //Noh da esquerda
		prefix(arv->sad); //Noh da direita
	}
	
}

//Infix
void infix(struct no * arv){ // SAE R SAD
	if(arv != NULL){
		infix(arv->sae); //Noh da esquerda
		printf("%d",arv->info); //Noh principal 
		infix(arv->sad); //Noh da direita	
	}
}

//Posfix
void posfix(struct no * arv){//SAE SAD R 
	if(arv != NULL){
		posfix(arv->sae); //Noh da esquerda
		posfix(arv->sad); //Noh da direita	
		printf("%d",arv->info); //Noh principal 
	}
}

//Buscar
int buscar(struct no* arv, int numero){ //1 = Existe este numero na arvore / 0 = Nao existe
	if(arv == NULL){
	printf("Arvore vazia\n");
	return 0;
	}else{
		return arv->info == numero || buscar(arv->sae, numero) || buscar (arv->sad, numero);
		}
	}











