/**
1. Fazer uma função para verificar se uma lista de inteiros (use conceito de lista sequencial) está ordenada ou não (a ordem
pode ser crescente ou decrescente).
*/
#include <stdio.h>
#include <stdlib.h>


typedef struct lista{
int prox;
int num[10];
}Lista;

int verificaOrdenacao(Lista*);

int main()
{
    Lista *l = (Lista*)malloc(sizeof(Lista));

    l->num[0]=9;
    l->num[1]=9;
    l->num[2]=9;
    l->num[3]=9;
    l->num[4]=9;
    l->num[5]=9;
    l->num[6]=9;
    l->num[7]=9;
    l->num[8]=4;

    l->prox=9;

    printf("Ordenacao: %d\n", verificaOrdenacao(l));
    return 0;
}

/**
verifica se lista esta ordenada
retorna 1 se estiver ordenada em ordem crescente, -1 decrescente e 0 se nao estiver ordenada
*/

int verificaOrdenacao(Lista *lista){
	int i=0, flag=0, flag2=0;
	if(lista!=NULL){

		while(i!=lista->prox-1){
			if(lista->num[i]<lista->num[i+1]){
				flag++;
			}else if(lista->num[i]>lista->num[i+1]){
                flag2--;
            }else if(lista->num[i]==lista->num[i+1]){
                flag++;
                flag2--;
            }
			i++;
		}

		if((flag+1)==lista->prox){
			return 1;
		}else if((flag2-1)*-1==lista->prox){
			return -1;
		}
	}
	return 0;
}
