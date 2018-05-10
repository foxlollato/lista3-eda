#include "racionais.h"

int main(int argc, char *argv[])
{
    int i=0;
    rac *racV[6], *resultado;

    racV[0] = criaRac(3,5);
    racV[1] = criaRac(8,3);
    racV[2] = criaRac(24,9);
    racV[3] = criaRac(9,2);
    racV[4] = criaRac(8,13);
    racV[5] = NULL;

    if((resultado = somaRac(racV))!=NULL){
        printf("Soma: %s", imprimeRac(resultado));
    }

    printf("\n");

    if((resultado = multiplicaRac(racV))!=NULL){
        printf("Produto: %s", imprimeRac(resultado));
    }

    char *rac1 = imprimeRac(racV[0]);
    char *rac2 = imprimeRac(racV[1]);
    char *rac3 = imprimeRac(racV[2]);

    printf("\n%s e %s sao %s", rac1, rac2, (comparaRac(racV[0], racV[1]))==TRUE ? "IGUAIS" : "DIFERENTES");

    printf("\n%s e %s sao %s", rac2, rac3, (comparaRac(racV[2], racV[1]))==TRUE ? "IGUAIS" : "DIFERENTES");



    destroyRac(rac1);
    destroyRac(rac2);
    destroyRac(rac3);

    return 0;
}
