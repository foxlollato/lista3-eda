#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
int prox;
int num[10];
}Lista;

Lista* copiaLista(Lista*);
void imprimeLista(Lista*);

int main(int argc, char *argv[])
{

    Lista *l1, *l2;

    l1=(Lista*)malloc(sizeof(Lista));

    l1->prox=9;
    l1->num[0]=1;
    l1->num[1]=2;
    l1->num[2]=3;
    l1->num[3]=4;
    l1->num[4]=5;
    l1->num[5]=6;
    l1->num[6]=7;
    l1->num[7]=8;
    l1->num[8]=9;

    l2=copiaLista(l1);

    imprimeLista(l1);
    printf("\n");
    imprimeLista(l2);

    return 0;
}


Lista* copiaLista(Lista* l1){
    Lista* l2=NULL;

    if(l1!=NULL){

        l2=(Lista*)malloc(sizeof(Lista));
        l2->prox=0;

        int i, x, aux,c;


        for(i=0;i<l1->prox;i++){
                c=0;
                for(x=0;x<l2->prox;x++){
                    if(l1->num[i]==l2->num[x]){
                        c++;
                    }
                }
                if(c==0){
                    l2->num[l2->prox]=l1->num[i];
                    l2->prox++;
                }
        }

        for(i=0;i<l2->prox;i++){
            for(x=0; x<l2->prox;x++){
                if(l2->num[x]<l2->num[x+1]){
                    aux=l2->num[x];
                    l2->num[x]=l2->num[x+1];
                    l2->num[x+1]=aux;
                }
            }
        }
    }

        return l2;
}

void imprimeLista(Lista* inicio){
    if(inicio == NULL)
        return;
    int i=0;
    while(i < inicio->prox){
        printf("\t%d", inicio->num[i]);
        i++;
    }
}
