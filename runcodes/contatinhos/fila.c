#include "fila.h"

int inicializar(t_fila *f)
{
    f->inicio = NULL;
    f->final = NULL;

    return SUCESSO;
}

int enfileirar(int v, t_fila *f)
{
    t_apontadorF aux = (t_apontadorF)malloc(sizeof(t_noF));
    if (aux == NULL){
        return CHEIA;
    }

    aux->valor = v;
    if(f->final==NULL){
        f->final = aux;
        f->inicio = aux;
        f->final->proximo = NULL;
        f->inicio->proximo = NULL;
        return SUCESSO;
    }

    f->final->proximo = aux;
    f->final = aux;
    f->final->proximo = NULL;

    return SUCESSO;
}

int desenfileirar(t_fila *f)
{
    if(vazia(f)){
        return VAZIA;
    }

    t_apontadorF aux = f->inicio;
    int valor = aux->valor;

    f->inicio = aux->proximo;
    if(aux->proximo == NULL){
        f->final = NULL;
    }
    free(aux);

    return valor;
}

int vazia(t_fila *f)
{
    if(f->inicio == NULL && f->final == NULL){
        return 1;
    }
    return 0;
}
void inicio(t_fila *f)
{
    if(f->inicio == NULL){
        printf("NULL\n");
    }
    printf("inicio: %d\n", f->inicio->valor);
}
void final(t_fila *f)
{
    if(f->final == NULL){
        printf("NULL\n");
    }
    printf("final: %d\n", f->final->valor);
}