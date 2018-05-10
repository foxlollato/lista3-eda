/**
verifica se lista esta ordenada
retorna 1 se estiver ordenada em ordem crescente, -1 decrescente e 0 se nao estiver ordenada
*/

int verificaOrdenacao(Lista *lista){
	int i=0, flag=0;
	if(Lista!=NULL){
		do{
			if(lista->inteiro[i]<=lista->inteiro[i+1]){
				flag++;
			}
			if(lista->inteiro[i]>=lista->inteiro[i+1]){
				flag--;
			}				
			i++;
		}while(i!=lista->prox);
		
		if(flag==lista->prox-1){
			return 1;
		}
		
		if(flag==(-1*lista->prox-1)){
			return -1;
		}
	}
	return 0;
}