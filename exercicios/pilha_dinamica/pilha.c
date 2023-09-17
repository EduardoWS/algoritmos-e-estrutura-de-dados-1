#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


int inicializar(t_pilha *p)
{
    p->topo = NULL;
    p->contador = 0;

    return SUCESSO;
}

int push(int v, t_pilha *p)
{
    t_no* aux = (t_no*)malloc(sizeof(t_no));
    if(aux == NULL){
        return CHEIA;
    }

    aux->valor = v;
    aux->proximo = p->topo;
    p->topo = aux;
    p->contador++;

    return SUCESSO;
}

int pop(t_pilha *p)
{
    if(p->topo == NULL){
        return VAZIA;
    }
    
    t_no* aux = p->topo;
    int v = aux->valor;
    p->topo = aux->proximo;
    p->contador--;
    free(aux);

    return v;
}


int topo(t_pilha *p)
{
    if(p->topo == NULL){
        return VAZIA;
    }

    t_no* aux = p->topo;
    return aux->valor;
}

int vazia(t_pilha *p)
{
    if(p->topo==NULL){
        return 1;
    }

    return 0;
}

void tamanho(t_pilha *p)
{
    printf("Tamanho da pilha: %d\n", p->contador);
}

