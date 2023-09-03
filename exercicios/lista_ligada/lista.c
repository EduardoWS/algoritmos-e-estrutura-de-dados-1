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


int remover(t_chave chave, t_lista *l){

	if (vazia(l)) {
		printf("Nao achei para remover\n");
		return NAO_EXISTE;
	}

	t_apontador p = l->primeiro;
	t_apontador p2;

	if (p->elemento.chave == chave) { // chave na primeira pos

		p2 = l->primeiro;
		l->primeiro = p2->proximo;

		free(p2);

		return SUCESSO;

	}

	while(p->proximo!=NULL){
		if(p->proximo->elemento.chave == chave){
			p2 = p->proximo;
			p->proximo = p2->proximo;
			free(p2);
			return SUCESSO;
		}
		p = p->proximo;
	}

	printf("Valor não encontrado!\n");
	return NAO_EXISTE;

}


int pesquisar(t_chave chave, t_lista *l){

	t_apontador p = l->primeiro;

	while(p!=NULL){
		if(p->elemento.chave == chave){
			printf("%d %s\n", p->elemento.chave, p->elemento.nome);
			return SUCESSO;
		}
		p = p->proximo;
	}

	printf("Valor nao encontrado!\n");
	return NAO_EXISTE;

}




int vazia(t_lista *l){

	return (l->primeiro == NULL) ? 1 : 0;

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