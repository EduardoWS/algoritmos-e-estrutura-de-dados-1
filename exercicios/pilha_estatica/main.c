#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){

	t_pilha p;

	inicializar(&p);

	push(10, &p);
	push(100, &p);
	push(20, &p);

	imprimir(&p);

	pop(&p);

	imprimir(&p);

	int total_elementos = contar(&p);
	int valor_topo = topo(&p);

	printf("\nA pilha tem %d elementos\n", total_elementos);
	printf("O topo da pilha tem valor igual a %d\n", valor_topo);

	return 0;
}