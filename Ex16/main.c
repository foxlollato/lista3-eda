#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void inverterString(char*);

int main(int argc, char *argv[]){

	char *string = "Este exercicio e muito facil.";

	inverterString(string);

	printf("\n");

	return 0;
}
void inverterString(char *string){
char *normal=string;//guardando referencia para string
char *inicio; //referencia inicio de cada palavra
char *fim;//referencia fim de cada palavra
char *inv=(char*)malloc(sizeof(strlen(string)+1));//allocando espaco para string invertida
char *invAux=inv;//referencia posicoes da nova string

while(*string != '.'){
        inicio=string;
		do{
            string++;
            fim=string;
		}while(*string != ' ' && *string!='.');
        if(*string == '.'){
            fim--;
        }
		while(fim!=inicio-1){
            *invAux=*fim;
            fim--;
            invAux++;
		}
	}
	invAux--;
	strcpy(invAux, ".");

	printf("Normal: %s", normal);
	printf("\nInvert: %s", inv);
}

