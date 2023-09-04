#ifndef PILHA_H
#define PILHA_H

#define MAX 128

#define SUCESSO 1
#define NAO_EXISTE -1
#define JA_EXISTE -2
#define INVALIDO -3
#define CHEIA -4
#define VAZIA -5

typedef struct {
	int topo;
	int *pilha;
} t_pilha;

int inicializar(t_pilha *p);
int push(int e, t_pilha *p);
int pop(t_pilha *p);
int topo(t_pilha *p);
int contar(t_pilha *p);

void imprimir(t_pilha *p);


#endif