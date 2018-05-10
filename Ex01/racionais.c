#include "racionais.h"

int mmc(int,int);
int simplificaRacional(rac*);

struct Racional{
int numerador;
int denominador;
};

rac* criaRac(int num, int den){

        rac *n =(rac*)malloc(sizeof(rac));

        if(num >= 0 && den >= 1 && n != NULL){
            n->numerador=num;
            n->denominador=den;
            return n;
        }
        return NULL;
}

int destroyRac(rac* n){

        if( n != NULL){
            free(n);
            return TRUE;
        }
        return FALSE;
}

rac* somaRac(rac  **racV){
    rac *resultado=NULL;

        if(*racV != NULL){
            if((resultado=criaRac((*racV)->numerador, (*racV)->denominador))!=NULL){
                racV++;

                do{
                    resultado->numerador = (mmc(resultado->denominador, (*racV)->denominador) / resultado->denominador * resultado->numerador) +
                    (mmc(resultado->denominador, (*racV)->denominador) / (*racV)->denominador * (*racV)->numerador);
                    resultado->denominador = mmc(resultado->denominador, (*racV)->denominador);

                    racV++;

                }while(*racV != NULL);
                simplificaRacional(resultado);
            }
    }
    return resultado;
}

rac* multiplicaRac(rac **racV){
    rac *resultado = NULL;

    if(*racV != NULL){
         if((resultado=criaRac((*racV)->numerador, (*racV)->denominador))!=NULL){
                racV++;

                do{
                    resultado->numerador = resultado->numerador * (*racV)->numerador;
                    resultado->denominador = resultado->denominador * (*racV)->denominador;
                    racV++;

                }while(*racV != NULL);
                simplificaRacional(resultado);
         }
    }
    return resultado;
}

int comparaRac(rac *rac1, rac *rac2){

    if(rac1 != NULL && rac2 != NULL){
        if(rac1->numerador/rac1->denominador == rac2->numerador/rac2->denominador){
            return TRUE;
        }
    }
    return FALSE;
}

int mmc(int den1, int den2){

    int resto, d1, d2;
    d1 = den1;
    d2 = den2;

    do{
        resto = d1%d2;
        d1=d2;
        d2=resto;

    }while(resto!=0);

    return (den1*den2) / d1;
}
int simplificaRacional(rac *rac1){
    if(rac1 != NULL){
        int i;
        for(i=rac1->denominador; i>0; i--){
            if(rac1->numerador%i ==0 && rac1->denominador%i == 0){
                rac1->numerador /= i;
                rac1->denominador /= i;
                return TRUE;
            }
        }
    }
    return FALSE;
}

char* imprimeRac(rac *n){
    char *string=NULL;

    if(n!=NULL){

            string=malloc(4);
            char *num=malloc(2);
            char *den=malloc(2);

            itoa(n->numerador,num,10);
            itoa(n->denominador,den,10);

            strcpy(string,num);
            strcat(string,"/");
            strcat(string,den);

    }
    return string;
}
