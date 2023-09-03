#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int inicializar(t_lista *l){

	l->primeiro = NULL;

	return SUCESSO;
}

int inserir(t_elemento e, t_lista *l){

	t_apontador p = (t_apontador)malloc(sizeof(t_no));

	if(p == NULL){
		printf("ERRO: memoria cheia!");
		return CHEIA;
	}

	p->elemento = e;
	p->proximo = l->primeiro;
	l->primeiro = p;

	return SUCESSO;
}







void imprimir(t_lista *l) {

	t_apontador p = l->primeiro;

	printf("\n{\n");
	while (p != NULL) {
		printf("%d %s\n", p->elemento.chave, p->elemento.nome);
		p = p->proximo;
	}
	printf("}\n");

}