#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 1
#define NAO_EXISTE -1
#define JA_EXISTE -2
#define INVALIDO -3
#define CHEIA -4
#define VAZIA -5

typedef struct t_noF* t_apontadorF;
typedef struct t_noF{
    int valor;
    t_apontadorF proximo;
} t_noF;

typedef struct t_fila{
    t_apontadorF inicio;
    t_apontadorF final;
} t_fila;

int inicializar(t_fila *f);
int enfileirar(int v, t_fila *f);
int desenfileirar(t_fila *f);
int vazia(t_fila *f);
void inicio(t_fila *f);
void final(t_fila *f);


#endif