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
		i++;
		imprimeFila(fila);
		printf("\n");		
	}
	i=0;
	while(i<10){
		i++;
		imprimeFila(fila);
		sai(fila);
		printf("\n");		
	}
	imprimeFila(fila);
	free(fila);
	return 0;
}
