#include "tad.h"


int main()
{
    Lista *inicio = criaLista();

    cadastraProduto(inicio);
    cadastraProduto(inicio);
    cadastraProduto(inicio);

    imprimeLista(inicio);
    Produto *p;
    buscaProdutoQtdEstoque(inicio, 10);
    
    

    return 0;
}
