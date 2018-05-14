#include "tad.h"
int main(int argc, char *argv[]){

	Pilha *pilha = criaPilha();
	Dado dados[10]={
		{1},
		{2},
		{3},
		{4},
		{5},
		{6},
		{7},
		{8},
		{9},
		{10}
	};	
	int i = 0;		
	while(i<10){
		entra(pilha,dados[i]);
		imprimePilha(pilha);
		printf("\n");		
		i++;
	}
	printf("A Pilha esta vazia? %s\n", (vazia(pilha) ? "SIM" : "NAO"));
	i=0;
	while(i<10){
		imprimePilha(pilha);
		sai(pilha);
		printf("\n");		
		i++;
	}
	printf("A Pilha esta vazia? %s\n", (vazia(pilha) ? "SIM" : "NAO"));
	imprimePilha(pilha);	
	free(pilha);
	return 0;
}
