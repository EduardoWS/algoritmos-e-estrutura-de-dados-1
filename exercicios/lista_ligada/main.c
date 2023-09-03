#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

int main(){

	t_lista l;
	t_elemento e;

	inicializar(&l);

	e.chave = 50;
	strcpy(e.nome, "Edu");
	inserir(e, &l);

	e.chave = 10;
	strcpy(e.nome, "Carol");
	inserir(e, &l);

	imprimir(&l);

	remover(10, &l);
	imprimir(&l);

	pesquisar(50, &l);

	return 0;
}