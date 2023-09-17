#include <stdio.h>
#include "pilha.h"

int main() {

	t_pilha P;
	int e;
    

	inicializar(&P);
    tamanho(&P);
	push(5, &P);
	push(7, &P);
	push(9, &P);

    tamanho(&P);

    printf("Topo: %d\n", topo(&P));


	e = pop(&P);
	printf("%d\n", e);
    tamanho(&P);
    printf("Topo: %d\n", topo(&P));

	push(10, &P);
    tamanho(&P);
	while(!vazia(&P)) {
		e = pop(&P);
		printf("%d\n", e);
	}

    printf("Topo: %d\n", topo(&P));
    tamanho(&P);
}