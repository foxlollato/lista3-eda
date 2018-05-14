#include "tad.h"

struct tipoNo{
	Dado dado;
	struct tipoNo *prox;
};
typedef struct tipoNo noPilha;


int insereFinal(Pilha*, Dado);

Pilha* criaPilha(){
	Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));

	if(pilha != NULL)
		*pilha=NULL; 
	return pilha;
}

int entra(Pilha* fim, Dado dado){
	if(fim == NULL){
		return 0;
	}

	noPilha *aux, *no = (noPilha*) malloc(sizeof(noPilha));

	no->dado=dado;
	no->prox=NULL;        

	if(*fim == NULL){ 
		*fim = no;
	}else{
		no->prox=*fim;
		*fim=no;
	}
	return 1;
}

int sai(Pilha *fim){
	if(fim == NULL && *fim == NULL){
		return 0;
	}else{
		noPilha *no;
		no=*fim;
		if(no->prox!=NULL){
			no=no->prox;
			free((*fim));
			*fim=no;
		}else{
			free(no);
			*fim=NULL;
		}
	}	

	return 1;	

}
int vazia(Pilha *fim){
	if(*fim==NULL)
		return 1;
	return 0;

}
void imprimePilha(Pilha *fim){
	if((*fim) == NULL)
		return;

	noPilha *no=*fim;
	while(no !=NULL){
		printf("%d\t", no->dado.info);
		no=no->prox;
	}

}
