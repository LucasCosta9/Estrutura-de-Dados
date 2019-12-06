#include <stdio.h>
#include <stdlib.h>

struct caixa{
    int dado; //Valor do struct caixa
    struct caixa *prox; //Ponteiro que vai apontar para o próximo da lista
    struct caixa *ant; //Ponteiro que vai apontar para o anterior da lista 
    

};  
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
    if(laux->prox){   
     laux -> prox-> ant = 0;
     laux -> prox -> ant = laux;
    }
	*lista = laux; //Faz a lista apontar para o ponteiro auxiliar

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
//INVERTER
void inverter(struct caixa**lista){
if(*lista==0){ //Caso a lista estiver vazia
printf("\nLista vazia");
return;
}


struct caixa *laux; //Cria ponteiro auxiliar 
laux = (struct caixa *)malloc(sizeof(struct caixa));//Pedido de memoria 
if (!laux){printf("Memoria cheia");return;} //

struct caixa *laux2; //Armazenar o ponteiro pro próximo (ja que vai se perder durante a mudança)
laux2 = (struct caixa *)malloc(sizeof(struct caixa));//Pedido de memoria 
if (!laux){printf("Memoria cheia");return;}

struct caixa *laux3; //Armazenar o penultimo da lista 
laux3 = (struct caixa *)malloc(sizeof(struct caixa));//Pedido de memoria 
if (!laux3){printf("Memoria cheia");return;}
 
   //int i =0; //Variavel pra testar um for
   for(laux3=*lista;laux3->prox!=0;laux3=laux3->prox); //Deixar laux3 apontando pro penultimo
    
   for (laux=*lista;laux!=0;laux=laux2->prox){ //Iterar até o final da lista 
             laux2->prox = laux-> prox; //Armazena o próximo
             laux ->prox = laux->ant; //Troca o proximo com o anterior
             laux ->ant = laux2->prox; //Troca o anterior com o proximo que foi armazenado
             // i++;
             // printf("i=%d",i);
            }
    
   *lista=laux3; //Fazer lista apontar pro final 
  
}

int main (void){
    //Criando lista
    struct caixa*lista; //Criando struct
	lista = (struct caixa *)malloc(sizeof(struct caixa)); //Alocacao de memoria
    lista = 0;
    

    listar(&lista);
    inverter(&lista); //Inverter lista vazia
    listar(&lista);   

    inserir_inicio(1,&lista);
    listar(&lista);  
    inverter(&lista); //Inverter 1
    listar(&lista);  


    inserir_inicio(2,&lista);
    listar(&lista);
    inverter(&lista); //Inverter 21
    listar(&lista);  


    inserir_inicio(3,&lista);
    listar(&lista);
    inverter(&lista);//Inverter 312
    listar(&lista);
    

}






















