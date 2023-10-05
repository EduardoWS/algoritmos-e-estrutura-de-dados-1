#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void inicializarPilha(t_pilha *P) {
	P->topo = -1;
}


int push(int e, t_pilha *P) {

	if (cheiaPilha(P)) {
		printf("Pilha cheia\n");
		return CHEIA;
	}

	P->topo++;
	P->pilha[P->topo] = e;

	return SUCESSO;

}

int pop(t_pilha *P) {

	if (vaziaPilha(P)) {
		printf("Nao pode popar\n");
		return VAZIA;
	}

	int e = P->pilha[P->topo];
	P->topo--;	

	return e;

}

int vaziaPilha(t_pilha *P) {
	if (P->topo < 0) {
		return 1;
	} else {
		return 0;
	}
}

int cheiaPilha(t_pilha *P) {
	// return (P->topo == MAX - 1) ? 1 : 0;
	// return P->topo == MAX -1;
	if (P->topo == MAX - 1) {
		return 1;
	} else {
		return 0;
	}
}

int topo(t_pilha *P) {

	if (vaziaPilha(P)) {
		printf("Nao tem topo!!!!\n");
		return VAZIA;
	}
	return P->pilha[P->topo];

}


int contar(t_pilha *P) {
	return P->topo + 1;
}