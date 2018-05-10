#include "tad.h"

typedef struct tipoNo{
    struct tipoNo *ant;
    Produto p;
    struct tipoNo *prox;
}noLista;


Lista* criaLista(){
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    if(lista != NULL){
        *lista=NULL;
    }
    return lista;
}
int cadastraProduto(Lista *inicio){
    if(inicio==NULL){
        return 0;
    }
    noLista *aux, *p, *no = *inicio;
    p=(Produto*)malloc(sizeof(noLista));

    printf("Insira o codigo do produto: ");
    scanf("%d", &p->p.cod);

    printf("Insira a descricao do produto: ");
    scanf("%s", p->p.desc);

    printf("Insira o valor do produto: ");
    scanf("%f", &p->p.valor);

    printf("Insira a quantidade do produto: ");
    scanf("%d",& p->p.qtd);

    printf("Insira a data de compra do produto: ");
    scanf("%d%d%d", &p->p.dataCompra.dia, &p->p.dataCompra.mes, &p->p.dataCompra.ano);


    if(*inicio==NULL){
        *inicio=p;
        p->ant=NULL;
        p->prox=NULL;
        return 1;
    }else{
        while(no!=NULL && p->p.cod > no->p.cod){
            aux = no;            
            no = no->prox;
            }        
        if((*inicio)==no){
            p->ant=NULL;
            no->ant=p;
            p->prox=*inicio;
            *inicio=p;
            return 1;
        }else{
			p->prox = aux->prox;
            p->ant = aux;
            aux->prox = p;
            if (aux != NULL)
            	aux->ant = no;
        }
        return 1;
	}
    
    return 0;
}

void imprimeLista(Lista *inicio){
    if(*inicio==NULL){
        return;
    }
    noLista *no=*inicio;
    while(no!=NULL){
            printf("ID %d\n", no->p.cod);
        no = no->prox;
    }
}
int buscaMenorPreco(Lista *inicio, Produto *p){
	if((*inicio)==NULL){
		return 0;
	}	
	noLista *no = *inicio;
	*p=no->p;
	while(no->prox!=NULL){
		if(p->valor > no->p.valor){
			*p=no->p;
		}
		no = no->prox;
	}
	
	return 1;
}

void buscaProdutoQtdEstoque(Lista *inicio, int qtd){
	if((*inicio)==NULL){
		return;
	}	
	noLista *no = *inicio;	
	while(no->prox!=NULL){
		if( no->p.qtd < qtd){
			printf("Produto %d, Quantidade: %d\n", no->p.cod, no->p.qtd);
		}
		no = no->prox;
	}	
}
int apagaProduto(Lista*, int);
int atualizaCadastroProduto(Lista*, int);
void relatorioEstoqueAsc(Lista*);
void relatorioEstoqueDesc(Lista*);
