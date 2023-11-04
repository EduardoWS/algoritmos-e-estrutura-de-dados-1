#ifndef ABB_H
#define ABB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 1
#define NAO_EXISTE -1
#define JA_EXISTE -2
#define INVALIDO -3
#define CHEIA -4
#define VAZIA -5

typedef int t_chave;

typedef struct t_no* t_apontador;
typedef struct t_no {
	t_apontador esq, dir;
	t_chave chave;
} t_no;

typedef t_apontador t_abb;


void inicializar(t_abb *t);
void limpar(t_abb *t);
t_chave pesquisar(t_chave c, t_abb *t);
int inserir(t_chave c, t_abb *t);
int remover(t_chave c, t_abb *t);
int vazia(t_abb *t);
void em_ordem(t_abb *t);

// alterar


#endif