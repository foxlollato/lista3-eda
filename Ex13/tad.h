#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
	int info;
}Dado;

typedef struct tipoNo *Lista;

Lista* criaLista();
int entra(Lista*, Dado);
int sai(Lista*);
int vazia(Lista*);
void imprimeFila(Lista*);
