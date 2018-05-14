#include "tad.h"

struct tipoNo{
	Dado dado;
	struct tipoNo *prox;
};
typedef struct tipoNo noLista;

Lista* criaLista(){
	Lista *lista = (Lista*) malloc(sizeof(Lista));

	if(lista != NULL)
		*lista=NULL; 
	return lista;
}

int entra(Lista* fim, Dado dado){
	if(fim == NULL){
		return 0;
	}

	noLista *ant, *aux, *no = (noLista*) malloc(sizeof(noLista));

	no->dado=dado;        
	if(*fim == NULL){ 
		*fim = no;
		no->prox=no;
	}else{
		aux=(*fim)->prox;
		do{
			ant=aux;
			aux=aux->prox;
		}while(aux->dado.info>=dado.info && aux!=(*fim)->prox);
		
		ant->prox=no;
		no->prox=aux;
		if(aux==(*fim) && ant!=ant->prox){
			*fim=no;
		}
	}
	return 1;
}

int sai(Lista *fim){
	if(fim == NULL && *fim == NULL){
		return 0;
	}else{
		noLista *no;
		no=*fim;
		no=no->prox;
		(*fim)->prox=no->prox;
		free(no);
		if(no==no->prox)
			*fim=NULL;
	}	

	return 1;	

}
int vazia(Lista *fim){
	if(*fim==NULL)
		return 1;
	return 0;

}
void imprimeFila(Lista *fim){
	if((*fim) == NULL)
		return;

	noLista *no=*fim;
	no=no->prox;
	do{
		printf("%d\t", no->dado.info);
		no=no->prox;
	}while(no != (*fim)->prox);
	
}
