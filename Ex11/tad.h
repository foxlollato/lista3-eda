#include <stdio.h>
#include <stdlib.h>

typedef struct pilha Pilha;

Pilha* criaPilha(int);
int push(Pilha*, int, int);
int pop(Pilha*, int);
void imprimePilha(Pilha*);
