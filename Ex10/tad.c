#include "tad.h"

struct tipoNo{
	Aeronave aeronave;
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

int insereElemento(Lista* inicio, Aeronave aeronave){
	if(inicio == NULL)
		return 0;
	noLista *no = (noLista*) malloc(sizeof(noLista));
	if(no == NULL)
		return 0;
	no->aeronave = aeronave;
	no->prox = NULL;
	if((*inicio) == NULL){//lista vazia: insere início
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

	if((*inicio) == NULL){//lista vazia: insere início
		no->prox = NULL;
		*inicio = no;
		return 1;
	}
	else{ //lista não vazia - procura onde inserir
		noLista *anterior, *atual = *inicio;
		while(atual != NULL && atual->aeronave.combustivel < aeronave.combustivel){
			anterior = atual;
			atual = atual->prox;
		}
		if(atual == *inicio){//não entrou no while - insere início
			no->prox = (*inicio);//PROX DO novoNo APONTA PARA ONDE O INÍCIO ESTÁ APONTANDO
			*inicio = no;//atualiza início
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
		while((*inicio) != NULL){ 		 //retira cada nó até encontrar fim da lista (NULL)
			no = *inicio; 				//no aux recebe o início da lista ("1º..." elemento)
			*inicio = (*inicio)->prox; //início da lista passa a apontar p/ "2º..." elemento
			free(no); 				  //libero memória do "1º..." elemento da lista
		}
		free(inicio); //libero cabeça da lista
	}
}
