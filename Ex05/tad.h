#include <stdio.h>
#include <stdlib.h>

typedef struct data{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct produto{
    int cod;
    char desc[20];
    float valor;
    int qtd;
    Data dataCompra;
}Produto;

typedef struct noLista *Lista;

Lista* criaLista();
int cadastraProduto(Lista*);
void imprimeLista(Lista*);
int buscaMenorPreco(Lista*, Produto*);
void buscaProdutoQtdEstoque(Lista*, int);
int apagaProduto(Lista*, int);
int atualizaCadastroProduto(Lista*, int);
void relatorioEstoqueAsc(Lista*);
void relatorioEstoqueDesc(Lista*);
