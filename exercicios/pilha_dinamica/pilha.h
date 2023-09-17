#ifndef PILHA_H
#define PILHA_H

#define SUCESSO 1
#define NAO_EXISTE -1
#define JA_EXISTE -2
#define INVALIDO -3
#define CHEIA -4
#define VAZIA -5

typedef struct t_no* t_apontador;   // ponteiro que aponta para estruturas do tipo t_no
typedef struct t_no{
    int valor;
    t_apontador proximo;
} t_no;


typedef struct {
    t_apontador topo;
    int contador;
} t_pilha;



int inicializar(t_pilha *p);
int push(int v, t_pilha *p);
int pop(t_pilha *p);
int topo(t_pilha *p);
int vazia(t_pilha *p);
void tamanho(t_pilha *p);



#endif