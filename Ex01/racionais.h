#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

/**
definindo tipo de variavel Racional como 'rac'                                */
typedef struct Racional rac;

/**
criaRac aloca uma estrutura de um racional,
passando como parametro, respectivamente NUMERADOR e DENOMINADOR,
verificando se numerador maior que -1 e denominador  maior que 0,
caso contrario retorna NULL.                                                */
rac* criaRac(int, int);

/**
destroi variavel do tipo rac, liberando memoria alocada.
Retorna TRUE(1) se liberar e FALSE(0) se falhar                             */
int destroyRac(rac*);

/**
retorna a soma de todos racionais dentro do vetor recebido como parametro.
Necessario que o ultimo elemento do vetor receba NULL.
Parametro: rac**(vetor de rac*)                                             */
rac* somaRac(rac**);

/**
retorna o produto de todos racionais dentro do vetor recebido como parametro
Necessario que o ultimo elemento do vetor receba NULL
Parametro: rac** (vetor de rac*)                                            */
rac* multiplicaRac(rac**);

/**
Compara 2 racionais. Retorna TRUE(1) se iguais e FALSE(0) se diferentes.    */
int comparaRac(rac*, rac*);

/**
retorna uma string (char*) de tamanho 4 exibindo o numero racional enviado como parametro,
e NULL caso parametro recebido seja NULL.	                                */
char* imprimeRac(rac*);
