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
	int tipo;
    void *dado;
    struct tipoNo *prox;
};

typedef struct tipoNo noLista;

Lista* criaLista(){//igual LSE
    Lista* list = (Lista*) malloc(sizeof(Lista));
    if(list != NULL)//criou corretamente
        *list = NULL; //ponteiro list está vazio - aponta para NULL
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

int listaCheia(Lista* inicio){ //só acontecerá se não houver espaço na memória
    return 0; //nunca estará cheia, retornará sempre ZERO
}

int listaVazia(Lista* inicio){//igual LE
    if(inicio == NULL)//verifica se a cabeça existe (lista válida)
        return 1;
    if(*inicio == NULL)//verifica se o conteúdo dela (p/ quem aponta) é NULL
        return 1;
    return 0;
}




int insereFinal(Lista* inicio, int tipo){
    if(inicio == NULL || tipo<=0 || tipo >=4){
        return 0;
    }

    noLista *no = (noLista*) malloc(sizeof(noLista));
    if(no == NULL){
        return 0;
    }

    if(tipo==1){
        no->dado = criaRetangulo();
    }

    if(tipo==2){
        no->dado = criaTriangulo();
    }

    if(tipo==3){
        no->dado = criaCirculo();
    }
        no->tipo=tipo;
        no->prox=NULL;

    if((*inicio) == NULL){ //lista vazia: insere início
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
							 //é apontado pelo campo "prox"
    						//de quem o "nó" aponta
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

    if(no->ant == NULL)//remover o primeiro (e único)?
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
        if(no->tipo==1){
            printf("Retangulo. Lados: %.2f, %.2f\n", ((Ret*)no->dado)->a, ((Ret*)no->dado)->b);
            printf("Area figura: %.2f\n", calculaAreaFigura(no->dado,no->tipo));

        }
        if(no->tipo==2){
            printf("Triangulo. Base: %.2f, Altura: %.2f\n", ((Tri*)no->dado)->b, ((Tri*)no->dado)->h);
            printf("Area figura: %.2f\n", calculaAreaFigura(no->dado,no->tipo));
        }
        if(no->tipo==3){
            printf("Circulo. Raio: %.2f.\n", ((Cir*)no->dado)->raio);
            printf("Area figura: %.2f\n", calculaAreaFigura(no->dado,no->tipo));
        }
        printf("-------------------------------\n");
        no = no->prox;
    }
}


void apagaLista(Lista* inicio){//IGUAL LSE
    if(inicio != NULL){
        noLista* no;
        while((*inicio) != NULL){ 		 //retira cada nó até encontrar fim da lista (NULL)
            no = *inicio; 				//no aux recebe o início da lista ("1º..." elemento)
            *inicio = (*inicio)->prox; //início da lista passa a apontar p/ "2º..." elemento
            free(no); 				  //libero memória do "1º..." elemento da lista
        }
        free(inicio); //libero cabeça da lista
    }
}
float calculaAreaFigura(void *figura, int tipo){
    if(figura != NULL && tipo >=1 && tipo <=3 ){

        if(tipo == 1){
            return ((Ret*)figura)->a * ((Ret*)figura)->b;
        }
        if(tipo == 2){
            return (((Tri*)figura)->b * ((Tri*)figura)->h)/2;
        }
        if(tipo == 3){
            return (float) 3.14 * (pow(((Cir*)figura)->raio,2));
        }
    }
    return 0;
}

int calculaAreaLista(Lista *inicio){
    noLista *no = *inicio;
    if(inicio!=NULL){
            while(no !=NULL){
               printf("Area figura: %.2f\n", calculaAreaFigura(no->dado, no->tipo));
                no=no->prox;
            }
            return 1;
    }
    return 0;
}



struct retangulo* criaRetangulo(){

    struct retangulo *figura=(struct retangulo*)malloc(sizeof(struct retangulo));

        printf("\nDigite a medida do lado a: ");
        scanf("%f", &figura->a);

        printf("\nDigite a medida do lado b: ");
        scanf("%f", &figura->b);

        return figura;
};
struct triangulo* criaTriangulo(){
    struct triangulo *figura=(struct triangulo*)malloc(sizeof(struct triangulo));

        printf("\nDigite a medida da base a: ");
        scanf("%f", &figura->b);

        printf("\nDigite a medida da altura: ");
        scanf("%f", &figura->h);

        return figura;
}
struct circulo* criaCirculo(){
    struct circulo *figura=(struct circulo*)malloc(sizeof(struct circulo));

        printf("\nDigite a medida do raio: ");
        scanf("%f", &figura->raio);
        return figura;
}

