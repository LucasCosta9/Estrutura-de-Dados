/*
/*Autor: Lucas Costa Bezerra (20180000247)
/Programa para criar uma array de fichas de pacientes
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Criar um struct ficha com seus atributos
struct ficha{ 
	char nome[30];
	int idade;
	char sexo;
};

int main(void){
	//Inicializar as 3 fichas
	struct ficha paciente;
	struct ficha paciente2;
	struct ficha paciente3;
	
	//Paciente 1 
	char nome_temp[30] = "Tulio"; //Nome do paciente (em array temporaria)
	strcpy(paciente.nome,nome_temp);  //Colocar nome da array temporaria na fixa
	paciente.idade = 30; //Idade do paciente
	paciente.sexo = 'M'; //Sexo do paciente 

	//Paciente 2
	strcpy(nome_temp,"Jose"); //Nome do paciente (em array temporaria)
	strcpy(paciente2.nome,nome_temp); //Colocar nome da array temporaria na fixa
	paciente2.idade = 10;//Idade do paciente
	paciente2.sexo = 'M';//Sexo do paciente

	//Paciente 3
	strcpy(nome_temp,"Maria");//Nome do paciente (em array temporaria)
	strcpy(paciente3.nome,nome_temp);//Colocar nome da array temporaria na fixa
	paciente3.idade = 25;//Idade do paciente
	paciente3.sexo = 'F';//Sexo do paciente
	
    struct ficha* caixa; //Criar lista da fichas
    int tamanho = 3; //Escolher o tamanho
	caixa = (struct ficha*)malloc(tamanho*sizeof(struct ficha)); //Criar espaço para 3 fichas
    if (caixa){ //Caso caixa tenha sido criado
	    caixa[0] = paciente; //Colocar o paciente 1 na lista
	    caixa[1] = paciente2; //Colocar o paciente 2 na lista
	    caixa[2] = paciente3; //Colocar o paciente 3 na lista

    //Iterar e printar todos os pacientes da lista
    int i;
    for(i=0;i<tamanho;i++){
    	printf("%s %d %c\n",caixa[i].nome,caixa[i].idade,caixa[i].sexo);
	}
        

    }else{
  	  printf("Faltou Memoria"); //Caso faltar Memoria
    return 0;
    }


return 0;
}
