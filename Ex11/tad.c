#include "tad.h"

struct pilha{
	int topo1;
	int topo2;
	int size;
	int *dados;

};

Pilha* criaPilha(int size){
	Pilha *p=NULL;

	if(size>1){
		p=(Pilha*)malloc(sizeof(Pilha));
		p->dados=(int*)malloc(sizeof(int)*size);
		p->topo1=-1;
		p->topo2=size;
		p->size=size;
	}
	return p;
}

int push(Pilha *pilha, int dado, int op){
	int retorno = 0;
	if(pilha!=NULL && pilha->topo1+1 != pilha->topo2 && op >=1 && op <=2){
		if(op==1){
			pilha->dados[pilha->topo1+1] = dado;
			if(pilha->topo1 != pilha->topo2-1){
				pilha->topo1++;
			}
			retorno = 1;
		}else{
			pilha->dados[pilha->topo2-1] = dado;
			if(pilha->topo2 != pilha->topo1+1){
				pilha->topo2--;
			}
			retorno = 1;
		}
	}
	return retorno;
}

int pop(Pilha *pilha, int op){
	int retorno = 0;
	if(pilha!=NULL && op >=1 && op <=2){
		if(op == 1 && pilha->topo1 != -1){
			pilha->dados[pilha->topo1] = NULL;
			pilha->topo1--;
			retorno = 1;
		}
		if(op == 2 && pilha->topo2 != pilha->size){
			pilha->dados[pilha->topo2] = NULL;
			pilha->topo2++;
			retorno = 1;
		}
	}
	return retorno;
}

void imprimePilha(Pilha *pilha){
	if(pilha!=NULL){
	printf("\n<========================>");
		int i =0;
		while(i != pilha->size){
			printf("\n||\tElemento: %d\t||", pilha->dados[i]);
			i++;	
		}
	}	
	printf("\n||----------------------||");
	printf("\n||Topo 1: %d\t\t||", pilha->topo1);
	printf("\n||Topo 2: %d\t\t||", pilha->topo2);
	printf("\n<========================>");
}
