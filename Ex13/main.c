#include "tad.h"
int main(int argc, char *argv[]){

	Lista *fila = criaLista();
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
		entra(fila,dados[i]);
		imprimeFila(fila);
		printf("\n");		
		i++;
	}
	printf("A Fila esta vazia? %s\n", (vazia(fila) ? "SIM" : "NAO"));
	i=0;
	while(i<10){
		imprimeFila(fila);
		sai(fila);
		printf("\n");		
		i++;
	}
	printf("A Fila esta vazia? %s\n", (vazia(fila) ? "SIM" : "NAO"));
	
	free(fila);
	return 0;
}
