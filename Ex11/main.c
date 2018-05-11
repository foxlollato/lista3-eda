#include "tad.h" 


int main(int argc, char *argv[]){
	
	Pilha *p=criaPilha(10);

	push(p, 1, 1);
	push(p, 2, 1);
	push(p, 3, 1);
	push(p, 4, 1);
	push(p, 5, 1);
	push(p, 6, 2);
	push(p, 7, 2);
	push(p, 8, 2);
	push(p, 9, 2);
	push(p, 10, 2);
	
	imprimePilha(p);

	printf("\nPUSH? %d", push(p, 100, 1));
	printf("\nPUSH? %d", push(p, 200, 2));
	
	imprimePilha(p);
	
	pop(p,1);
	pop(p,1);
	pop(p,1);
	pop(p,1);
	pop(p,1);
	
	imprimePilha(p);
	
	pop(p, 2);
	pop(p, 2);
	pop(p, 2);
	pop(p, 2);
	pop(p, 2);

	imprimePilha(p);

	printf("\nPOP? %d", pop(p,1));
	printf("\nPOP? %d", pop(p,2));

	imprimePilha(p);
	
	printf("\n");	
	return 0;
}
