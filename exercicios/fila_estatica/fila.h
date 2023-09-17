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

#define MAX 3

//typedef int* t_apontador;
typedef struct {
    int valor;
    int inicio;
    int final;
    int fila[MAX];
} t_fila;

int inicializar(t_fila *f);
int enfileirar(int v, t_fila *f);
int desenfileirar(t_fila *f);
int vazia(t_fila *f);
int cheia(t_fila *f);
void inicio(t_fila *f);
void final(t_fila *f);
//int pesquisar(int v, )


#endif