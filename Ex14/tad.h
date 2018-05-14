#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
	int info;
}Dado;

typedef struct tipoNo *Pilha;

Pilha* criaPilha();
int entra(Pilha*, Dado);
int sai(Pilha*);
int vazia(Pilha*);
void imprimePilha(Pilha*);
