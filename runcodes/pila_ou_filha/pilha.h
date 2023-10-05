#ifndef PILHA_H
#define PILHA_H

#define MAX 100

#define SUCESSO 1
#define NAO_EXISTE -1
#define JA_EXISTE -2
#define INVALIDO -3
#define CHEIA -4
#define VAZIA -5

typedef struct {
	int topo;
	int pilha[MAX];
} t_pilha;

void inicializarPilha(t_pilha *p);
int push(int e, t_pilha *p);
int pop(t_pilha *p);
int vaziaPilha(t_pilha *P);
int cheiaPilha(t_pilha *P);
int topo(t_pilha *p);
int contar(t_pilha *p);



#endif