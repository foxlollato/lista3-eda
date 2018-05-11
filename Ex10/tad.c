#include "tad.h"

struct tipoNo{
	Aeronave aeronave;
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

int insereElemento(Lista* inicio, Aeronave aeronave){
	if(inicio == NULL)
		return 0;
	noLista *no = (noLista*) malloc(sizeof(noLista));
	if(no == NULL)
		return 0;
	no->aeronave = aeronave;
	no->prox = NULL;
	if((*inicio) == NULL){//lista vazia: insere in�cio
		*inicio = no;
	}else{
		noLista *aux = *inicio;
		while(aux->prox != NULL)
			aux = aux->prox;

		aux->prox = no;
	}
	return 1;
}


int insereElementoPrioritario(Lista* inicio, Aeronave aeronave){

	if(inicio == NULL)
		return 0;
	noLista *no = (noLista*) malloc(sizeof(noLista));
	if(no == NULL)
		return 0;
	no->aeronave = aeronave;

	if((*inicio) == NULL){//lista vazia: insere in�cio
		no->prox = NULL;
		*inicio = no;
		return 1;
	}
	else{ //lista n�o vazia - procura onde inserir
		noLista *anterior, *atual = *inicio;
		while(atual != NULL && atual->aeronave.combustivel < aeronave.combustivel){
			anterior = atual;
			atual = atual->prox;
		}
		if(atual == *inicio){//n�o entrou no while - insere in�cio
			no->prox = (*inicio);//PROX DO novoNo APONTA PARA ONDE O IN�CIO EST� APONTANDO
			*inicio = no;//atualiza in�cio
		}else{ //insere no meio ou fim
			no->prox = anterior->prox;
			anterior->prox = no;
		}
		return 1;
	}
}

int removeElemento(Lista* inicio){
	if(inicio == NULL)
		return 0;
	if((*inicio) == NULL)//lista vazia
		return 0;

	noLista *no = *inicio;
	*inicio = no->prox;

	free(no);
	return 1;
}

void imprimeLista(Lista* inicio){//IGUAL LSE
	if(inicio == NULL)
		return;
	noLista* no = *inicio;
	while(no != NULL){
		printf("\tAeronave: %d\n",no->aeronave.cod);
		printf("\tCombustivel: %d\n",no->aeronave.combustivel);
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
