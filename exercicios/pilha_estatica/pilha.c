#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int inicializar(t_pilha *p){

	p->pilha = (int *)calloc(MAX, sizeof(int));
	if(p->pilha == NULL){
		return CHEIA;
	}

	p->topo = -1;
	return SUCESSO;
}

int push(int e, t_pilha *p){

	if(p->topo == MAX-1){
		printf("ERRO: a pilha esta cheia!\n");
		return CHEIA;
	}

	p->topo++;
	p->pilha[p->topo] = e;

	return SUCESSO;

}

int pop(t_pilha *p){

	if(p->topo==-1){
		printf("\nA pilha esta vazia!\n");
		return VAZIA;
	}

	p->pilha[p->topo] = 0;
	p->topo--;

	return SUCESSO;
}

int topo(t_pilha *p) {

	if (p->topo==-1) {
		printf("Nao tem topo!!!!\n");
		return VAZIA;
	}
	return p->pilha[p->topo];

}


int contar(t_pilha *p) {
	return p->topo + 1;
}



void imprimir(t_pilha *p){

	int aux;

	printf("\n{\n");
	for(int i=p->topo; i>=0; i--){
		aux = p->pilha[i];
		printf("i:%d valor:%d\n", i, aux);
	}
	printf("}\n");
}