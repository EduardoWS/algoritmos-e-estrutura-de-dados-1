#include <stdio.h>
#include "lista.h"

/*
#define SUCESSO 1
#define NAO_EXISTE -1
#define JA_EXISTE -2
#define INVALIDO -3
#define CHEIA -4
#define VAZIA -5

typedef int t_chave;
typedef struct {
	t_chave chave;
	char nome[50];
	//qqer outra coisa
} t_elemento;

typedef struct {
	int ultimo;
	t_elemento lista[MAX];
} t_lista;

*/

int inicializar(t_lista *l){
	l->ultimo = -1;

	return SUCESSO;
}

int pesquisar(t_chave chave, t_lista *l){

	for (int i = 0; i <= l->ultimo; i++) {
		if (l->lista[i].chave  == chave) {
			return i;
		}
	}

	return NAO_EXISTE;

}


int inserir(t_elemento e, t_lista *l){

	if(cheia(l)){
		printf("A lista esta cheia!\n");
		return CHEIA;
	}

	if(pesquisar(e.chave, l) >= 0){
		printf("Chave ja existe.\n");
		return JA_EXISTE;
	}

	l->ultimo += 1;
	l->lista[l->ultimo] = e;

	return SUCESSO;
}


int remover(t_chave chave, t_lista *l){

	int pos = pesquisar(chave, l);

	if(pos < 0){
		printf("Chave nao existe\n");
		return NAO_EXISTE;
	}

	
	l->lista[pos] = l->lista[l->ultimo];
	l->ultimo--;

	return SUCESSO;
}

int cheia(t_lista *l){

	if(l->ultimo == MAX-1){
		return 1;
	}

	else{
		return 0;
	}
}


int vazia(t_lista *l){

	if(l->ultimo == -1){
		return 1;
	}

	else{
		return 0;
	}
}




void imprimir(t_lista *l){

	printf("{\n");
	for (int i = 0; i <= l->ultimo; i++) {
		printf("%d, %s\n", 
			l->lista[i].chave,
			l->lista[i].nome);
	}
	printf("}\n\n");

}