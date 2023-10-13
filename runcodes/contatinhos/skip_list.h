#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[11];
    int telefone;
} t_contato;


typedef struct t_no** t_apontador;
typedef struct t_no {
    t_contato contato;
    t_apontador proximo; //array de ponteiros
} t_no;


typedef struct {
    int max_level;
    int level;
    t_no* sentinela;
} t_skiplist;

//t_no* criarNo(t_contato contato, int level);
t_skiplist* criarSkipList(int max_level);
int inserir(t_skiplist* skip_list, t_contato contato);
int alterar(t_skiplist* skip_list, t_contato contato);
int remover(t_skiplist* skip_list, char* nome);
t_no* pesquisar(t_skiplist* skip_list, char* nome);
void liberarSkipList(t_skiplist* skip_list);


#endif