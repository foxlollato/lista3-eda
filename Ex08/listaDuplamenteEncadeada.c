#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listaDuplamenteEncadeada.h"

struct retangulo* criaRetangulo();
struct triangulo* criaTriangulo();
struct circulo* criaCirculo();
float calculaAreaFigura(void *figura, int tipo); //Retorna Area da figura passada por referencia, e 0 em caso de erro

struct tipoNo{
	struct tipoNo *ant;
    	Ret dado;
    struct tipoNo *prox;
};

typedef struct tipoNo noLista;

Lista* criaLista(){//igual LSE
    Lista* list = (Lista*) malloc(sizeof(Lista));
    if(list != NULL)//criou corretamente
        *list = NULL; //ponteiro list est� vazio - aponta para NULL
    return list;
}

int tamLista(Lista* inicio){ //igual LSE
    if(inicio == NULL)
        return 0;
    int cont = 0;
    noLista* no = *inicio;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int listaCheia(Lista* inicio){ //s� acontecer� se n�o houver espa�o na mem�ria
    return 0; //nunca estar� cheia, retornar� sempre ZERO
}

int listaVazia(Lista* inicio){//igual LE
    if(inicio == NULL)//verifica se a cabe�a existe (lista v�lida)
        return 1;
    if(*inicio == NULL)//verifica se o conte�do dela (p/ quem aponta) � NULL
        return 1;
    return 0;
}




int insereFinal(Lista* inicio, int a, int b){
    if(inicio == NULL){
        return 0;
    }

    noLista *no = (noLista*) malloc(sizeof(noLista));
    if(no == NULL){
        return 0;
    }
        no->dado.a=a;
	no->dado.b=b;
        no->prox=NULL;

    if((*inicio) == NULL){ //lista vazia: insere in�cio
    	no->ant = NULL; //ATUALIZA ant DO novoNO
        *inicio = no;
    }else{
        noLista *aux = *inicio;
        while(aux->prox != NULL)
            aux = aux->prox;

        aux->prox = no;
        no->ant = aux;//ATUALIZA ant DO novoNO
    }
    return 1;
}




int removeInicio(Lista* inicio){
    if(inicio == NULL)
        return 0;
    if((*inicio) == NULL)//lista vazia
        return 0;

    noLista *no = *inicio;
    *inicio = no->prox;

	if (no->prox != NULL)//TINHA MAIS DE 1 ELEMENTO NA LISTA
    	no->prox->ant = NULL; //valor do ponteiro "ant" que
							 //� apontado pelo campo "prox"
    						//de quem o "n�" aponta
    free(no);
    return 1;
}

int removeFinal(Lista* inicio){
    if(inicio == NULL)
        return 0;
    if((*inicio) == NULL)//lista vazia
        return 0;

    noLista *no = *inicio;
    while(no->prox != NULL){
        no = no->prox;
    }

    if(no->ant == NULL)//remover o primeiro (e �nico)?
        *inicio = no->prox;
    else
        no->ant->prox = no->prox;
    free(no);
    return 1;
}

void imprimeLista(Lista* inicio){//IGUAL LSE
    if(inicio == NULL)
        return;
    noLista* no = *inicio;
    while(no != NULL){
        printf("Area figura: %.2f\n", calculaArea(no->dado));
        printf("-------------------------------\n");
        no = no->prox;
    }
}


void apagaLista(Lista* inicio){//IGUAL LSE
    if(inicio != NULL){
        noLista* no;
        while((*inicio) != NULL){ 		 //retira cada n� at� encontrar fim da lista (NULL)
            no = *inicio; 				//no aux recebe o in�cio da lista ("1�..." elemento)
            *inicio = (*inicio)->prox; //in�cio da lista passa a apontar p/ "2�..." elemento
            free(no); 				  //libero mem�ria do "1�..." elemento da lista
        }
        free(inicio); //libero cabe�a da lista
    }
}

float calculaArea(Ret figura){
       return figura.a * figura.b;
}
