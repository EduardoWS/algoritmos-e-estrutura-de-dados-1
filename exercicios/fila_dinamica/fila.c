#include "fila.h"

int inicializar(t_fila *f)
{
    f->inicio = NULL;
    f->final = NULL;

    return SUCESSO;
}

int enfileirar(int v, t_fila *f)
{
    t_apontador aux = (t_apontador)malloc(sizeof(t_no));
    if (aux == NULL){
        return CHEIA;
    }

    aux->valor = v;
    aux->proximo = f->inicio;
    f->inicio = aux;
    if(f->final==NULL){
        f->final = aux;
    }

    return SUCESSO;
}

int desenfileirar(t_fila *f)
{
    if(vazia(f)){
        return VAZIA;
    }

    t_apontador aux = f->inicio;
    f->inicio = aux->proximo;
    if(aux->proximo == NULL){
        f->final = NULL;
    }
    free(aux);

    return SUCESSO;
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