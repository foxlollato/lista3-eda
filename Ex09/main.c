#include <stdio.h>
#include <stdlib.h>
#include "listaDuplamenteEncadeada.h"

#define qtde 5

int main(int argc, char *argv[]){


    Lista *inicio = criaLista();

        insereFinal(inicio, RETANGULO);
        insereFinal(inicio, TRIANGULO);
        insereFinal(inicio, CIRCULO);
        insereFinal(inicio, CIRCULO);
        insereFinal(inicio, CIRCULO);
        insereFinal(inicio, CIRCULO);
        insereFinal(inicio, CIRCULO);


	printf("\n------ DADOS NA LISTA ------\n");
    imprimeLista(inicio);
	printf("\n --> Tamanho atual da lista: %d\n",tamLista(inicio));


    apagaLista(inicio);

    return 0;

}

