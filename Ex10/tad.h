#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
	int cod;
	int combustivel;
}Aeronave;

typedef struct tipoNo *Lista;

Lista* criaLista();
void apagaLista(Lista*);
int insereElemento(Lista*, Aeronave);
int insereElementoPrioritario(Lista*, Aeronave);
int removeElemento(Lista*);
int tamLista(Lista*);
void imprimeLista(Lista*);
