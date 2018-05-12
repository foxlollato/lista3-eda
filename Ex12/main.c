#include "tad.h"

int main(int argc, char *argv[]){
	Lista *lista=criaLista();

	printf("\nResultado %.2f\n", calc(lista));

	return 0;
}
