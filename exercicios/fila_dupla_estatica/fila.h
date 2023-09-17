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

typedef struct{
    int inicio;
    int final;
    int fila[MAX];
} t_fila;

int inicializar(t_fila *f);
int insereInicio(int v, t_fila *f);
int insereFinal(int v, t_fila *f);
int removeInicio(int v, t_fila *f);
int removeFinal(int v, t_fila *f);
int vazia(t_fila *f);
void inicio(t_fila *f);
void final(t_fila *f);


#endif