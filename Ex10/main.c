#include "tad.h"

#define qtde 5

int main(int argc, char *argv[]){
	Aeronave aeronaves[qtde] = {
		{1,100},
		{2,80},
		{3,60},
		{4,40},
		{5,20},
	};

	Aeronave aeronave = {6,10};


	Lista *inicio = criaLista();

	int i;

	printf(" --> Tamanho atual da lista: %d\n", tamLista(inicio));

	for(i=0; i < qtde; i++){
		printf("\n.....Inserindo elemento na posicao: %d", i);
		insereElemento(inicio, aeronaves[i]);
	}
	
	printf("\n\n\n------ DADOS NA LISTA ------\n");
	imprimeLista(inicio);
	printf("\n --> Tamanho atual da lista: %d\n\n\n",tamLista(inicio));
	
	insereElementoPrioritario(inicio, aeronave);
	printf("\n\n\n------ DADOS NA LISTA ------\n");
	imprimeLista(inicio);
	printf("\n --> Tamanho atual da lista: %d\n\n\n",tamLista(inicio));

	removeElemento(inicio);
	printf("\n\n\n------ DADOS NA LISTA ------\n");
	imprimeLista(inicio);
	printf("\n --> Tamanho atual da lista: %d\n\n\n",tamLista(inicio));

	apagaLista(inicio);

	return 0;
}
