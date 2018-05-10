#include <stdio.h>
#include <stdlib.h>
#include "listaDuplamenteEncadeada.h"

struct tipoNo{
	struct tipoNo *ant;
    struct elemento dado;
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

int consultaPosicao(Lista* inicio, int pos, struct elemento *aluno){//IGUAL LSE
    if(inicio == NULL || pos <= 0)
        return 0;
    noLista *no = *inicio;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL)
        return 0;
    else{
        *aluno = no->dado;
        return 1;
    }
}

int consultaMatricula(Lista* inicio, int mat, struct elemento *aluno){//IGUAL LSE
    if(inicio == NULL)
        return 0;
    noLista *no = *inicio;
    while(no != NULL && no->dado.matricula != mat){
        no = no->prox;
    }
    if(no == NULL)
        return 0;
    else{
        *aluno = no->dado;
        return 1;
    }
}

int insereFinal(Lista* inicio, struct elemento aluno){
    if(inicio == NULL)
        return 0;
    noLista *no = (noLista*) malloc(sizeof(noLista));
    if(no == NULL)
        return 0;
    no->dado = aluno;
    no->prox = NULL;
    if((*inicio) == NULL){//lista vazia: insere início
    	no->ant = NULL;//ATUALIZA ant DO novoNO
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

int insereInicio(Lista* inicio, struct elemento aluno){
    if(inicio == NULL)//não alocada
        return 0;
    noLista* no = (noLista*) malloc(sizeof(noLista));
    if(no == NULL)
        return 0;
    no->dado = aluno;
    no->prox = (*inicio);
    no->ant = NULL; //--> PRIMEIRO ELEMENTO DA LISTA

	if(*inicio != NULL)		  //LISTA NÃO ESTAVA VAZIA -> ant de quem inicio
		(*inicio)->ant = no; //aponta, passa a apontar para o novoNo

    *inicio = no;//atualiza início
    return 1;
}

int insereOrdenada(Lista* inicio, struct elemento aluno){
    if(inicio == NULL)
        return 0;
    noLista *no = (noLista*) malloc(sizeof(noLista));
    if(no == NULL)
        return 0;
    no->dado = aluno;

    if((*inicio) == NULL){//lista vazia: insere início
        no->prox = NULL;
        no->ant = NULL;
        *inicio = no;
        return 1;
    }
    else{ //lista não vazia - procura onde inserir
        noLista *anterior, *atual = *inicio;
        while(atual != NULL && atual->dado.matricula < aluno.matricula){
            anterior = atual;
            atual = atual->prox;
        }
        if(atual == *inicio){//não entrou no while - insere início
        	no->ant = NULL; //ATUALIZO ant DO novoNo (SERÁ O 1º)
            (*inicio)->ant = no; //ant DO NÓ QUE, ANTES ERA O 1º, APONTA PARA O novoNo
			no->prox = (*inicio);//PROX DO novoNo APONTA PARA ONDE O INÍCIO ESTÁ APONTANDO
            *inicio = no;//atualiza início
        }else{ //insere no meio ou fim
            no->prox = anterior->prox;
            no->ant = anterior;
            anterior->prox = no;
            if (atual != NULL)
            	atual->ant = no;
        }
        return 1;
    }
}

int removeMatricula(Lista* inicio, int mat){
    if(inicio == NULL)
        return 0;
    if((*inicio) == NULL)//lista vazia
        return 0;
    noLista *no = *inicio;
    while(no != NULL && no->dado.matricula != mat){
        no = no->prox;
    }
    if(no == NULL)//não encontrado
        return 0;

    if(no->ant == NULL)//remover o primeiro?
        *inicio = no->prox;
    else
        no->ant->prox = no->prox;

	if (no->prox != NULL)
		no->prox->ant = no->ant;

    free(no);
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
        printf("\tMatricula: %d\n",no->dado.matricula);
        printf("\tNome: %s\n",no->dado.nome);
        printf("\tNotas: N1 = %4.2f; N2 = %4.2f N3 = %4.2f\n",
								no->dado.n1,
                                no->dado.n2,
                                no->dado.n3);
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


int mergeLista(Lista* l1, Lista* l2){
    int ret=0;
    if( l1 != NULL && l2 != NULL){
        noLista *no = *l1, *no2 = *l2;
        int i;

            while(no2 != NULL){
                    i=0;
                    no=*l1;
                    while(no != NULL){
                        if(no->dado.matricula == no2->dado.matricula){
                            i++;
                        }
                        no=no->prox;
                    }
                    if(!i){
                        insereOrdenada(l1,no2->dado);
                        ret=1;
                    }
                no2 = no2->prox;
            }
            return ret;
    }
return ret;
}
