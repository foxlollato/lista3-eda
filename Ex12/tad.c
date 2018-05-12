#include "tad.h"
struct tipoNo{
	struct tipoNo *ant;
	char op[10];
	struct tipoNo *prox;
};

typedef struct tipoNo noLista;

int insere(Lista*, char*);
int removeNo(Lista*);

Lista* criaLista(){
	Lista *lista=NULL;
	lista=(Lista*)malloc(sizeof(Lista));
	(*lista)=NULL;
	return lista;
}

int insere(Lista *lista, char *op){
	int retorno=0;
	if(lista!=NULL){
		noLista *aux, *no = (noLista*)malloc(sizeof(noLista));
		no->ant=NULL;
		no->prox=NULL;
		strcpy(no->op, op);
		if(*lista==NULL){
			*lista=no;
			retorno = 1;
		}else{
			aux=*lista;
			while(aux->prox != NULL){
				aux=aux->prox;
			}
			aux->prox=no;
			no->ant=aux;
			retorno = 1;
		}
	}

	return retorno;
}
int removeNo(Lista *lista){
    int retorno=0;
    if(lista!=NULL && *lista!=NULL){
       noLista *no;
       no=*lista;
       *lista=no->prox;
        (*lista)->ant=NULL;
        free(no);
        retorno = 1;
    }
    return retorno;
}
float calc(Lista *lista){
	char op[10];
	float resultado;
	noLista *next, *aux, *init, *initAux;

	while(*op!='.'){
		printf("\nDigite a operacao: ");
		scanf("%s", op);
		insere(lista, op);
	}
    aux=*lista;
    init=*lista;
    resultado=(float)atof(init->op);
    init=init->prox;


	while(*aux->op!= '.'){
		while(*aux->op != '-' && *aux->op != '+' && *aux->op != '/' && *aux->op != '*'){
			aux=aux->prox;
			next=aux->prox;
		}
         if(*aux->op=='-'){
			while(init!=next->ant){
				resultado -= (float)atof(init->op);
				init=init->prox;
				removeNo(lista);
			}
		}else if(*aux->op=='+'){
			while(init!=next->ant){
				resultado += (float)atof(init->op);
				init=init->prox;
				removeNo(lista);
			}
		}else if(*aux->op=='/'){
			while(init!=next->ant){

				resultado /= (float)atof(init->op);
				init=init->prox;
				removeNo(lista);;
			}
		}else if(*aux->op=='*'){
			while(init!=next->ant){

				resultado *=(float)atof(init->op);
				init=init->prox;
				removeNo(lista);
			}
		}
		removeNo(lista);
		aux=next;
		init=next;
	}

	return resultado;
}


