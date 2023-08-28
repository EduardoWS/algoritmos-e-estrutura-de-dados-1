#include <stdio.h>
#include <string.h>

#include "lista.h"

int main(){

	t_lista lista;
	t_elemento e;

	e.chave = 50;
	strcpy(e.nome, "Edu");

	inicializar(&lista);
	inserir(e, &lista);
	inserir(e, &lista);
	imprimir(&lista);

	e.chave = 10;
	strcpy(e.nome, "Carol");
	inserir(e, &lista);

	imprimir(&lista);

	//remover(50, &lista);
	//imprimir(&lista);

	remover(100, &lista);

	e.chave = 100;
	strcpy(e.nome, "Bob");
	inserir(e, &lista);
	imprimir(&lista);

	e.chave = 11;
	strcpy(e.nome, "Charlie");
	inserir(e, &lista);
	imprimir(&lista);

	return 0;
}