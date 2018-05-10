#include <stdio.h>
#include <stdlib.h>
#include "listaDuplamenteEncadeada.h"

#define qtde 5

int main(int argc, char *argv[]){
	struct elemento vetAlunos[qtde] = {
		{1,"Lucas Pedro",8.2,7.5,7.8},
		{3,"Beatriz Alfredo",6.5,8.3,8.8},
		{5,"Mariana Oliveira",9.1,7.8,7.5},
		{7,"Joao Junior",7.6,8.1,6.4},
		{9,"Carlos Alberto",7.8,7.1,6.3}
	};

	struct elemento vetAlunos2[qtde] = {
		{2,"Pedro Lucas",8.2,7.5,7.8},
		{4,"Alfredo Beatriz",6.5,8.3,8.8},
		{6,"Oliveira Mariana",9.1,7.8,7.5},
		{8," Junior Joao",7.6,8.1,6.4},
		{2.,"Alberto Carlos",7.8,7.1,6.3}
	};

	Lista *inicio = criaLista();
	Lista *inicio2 = criaLista();

	int i;


	for(i=0; i < qtde; i++){
		insereFinal(inicio, vetAlunos[i]);
		insereFinal(inicio2, vetAlunos2[i]);

	}
	printf("\n=====Lista 1 TAMANHO: %d=====\n\n",tamLista(inicio));
	imprimeLista(inicio);

	printf("\n=====Lista 2 TAMANHO: %d=====\n\n", tamLista(inicio2));
	imprimeLista(inicio2);

	Lista *l3=unionLista(inicio,inicio2);
	apagaLista(inicio);
	apagaLista(inicio2);
	printf("\n=====Lista UNION TAMANHO: %d=====\n\n", tamLista(l3));
	imprimeLista(l3);


	apagaLista(l3);

	return 0;
}
