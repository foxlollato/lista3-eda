#include <stdio.h>
#include <stdlib.h>
#include "listaDuplamenteEncadeada.h"

int main(int argc, char *argv[]){


	Lista *inicio = criaLista();

	insereFinal(inicio, 1,2);
	insereFinal(inicio, 3,4);
	insereFinal(inicio, 5,6);
	insereFinal(inicio, 7,8);
	insereFinal(inicio, 9,10);


	printf("\n------ DADOS NA LISTA ------\n");
	imprimeLista(inicio);
	apagaLista(inicio);

	return 0;

}

