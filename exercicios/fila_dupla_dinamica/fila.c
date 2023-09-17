#include "fila.h"

int inicializar(t_fila *f)
{
    f->inicio = NULL;
    f->final = NULL;
    f->contador = 0;

    return SUCESSO;
}

int insereInicio(int v, t_fila *f)
{
    t_apontador aux = (t_apontador)malloc(sizeof(t_no));
    if (aux == NULL){
        printf("Memoria cheia!\n");
        return CHEIA;
    }

    aux->valor = v;
    if(f->inicio == NULL && f->final == NULL){
        f->final = aux;
    }
    aux->proximo = f->inicio;
    aux->anterior = NULL;
    if(f->inicio != NULL){
        f->inicio->anterior = aux;
    }
    f->inicio = aux;

    return SUCESSO;
    
}
int insereFinal(int v, t_fila *f)
{
    t_apontador aux = (t_apontador)malloc(sizeof(t_no));
    if (aux == NULL){
        printf("Memoria cheia!\n");
        return CHEIA;
    }

    aux->valor = v;
    if(f->inicio == NULL && f->final == NULL){
        f->inicio = aux;
    }
    aux->anterior = f->final;
    aux->proximo = NULL;
    if(f->final != NULL){
        f->final->proximo = aux;
    }
    f->final = aux;

    return SUCESSO;
}

int removeInicio(t_fila *f)
{
    if(vazia(f)){
        printf("Ja esta vaiza!\n");
        return VAZIA;
    }

    t_apontador aux = f->inicio;
    if(f->inicio == f->final){
        f->inicio = NULL;
        f->final = NULL;
        free(aux);
        return SUCESSO;
    }
    f->inicio = aux->proximo;
    f->inicio->anterior = NULL;
    free(aux);

    return SUCESSO;

}
int removeFinal(t_fila *f)
{
    if(vazia(f)){
        printf("Ja esta vaiza!\n");
        return VAZIA;
    }

    t_apontador aux = f->final;
    if(f->inicio == f->final){
        f->inicio = NULL;
        f->final = NULL;
        free(aux);
        return SUCESSO;
    }
    f->final = aux->anterior;
    f->final->proximo = NULL;
    free(aux);

    return SUCESSO;
}

int vazia(t_fila *f)
{
    if(f->inicio == NULL && f->final == NULL)
    {
        printf("Vazia!\n");
        return 1;
    }
    return 0;
}

void inicio(t_fila *f)
{
    if(f->inicio == NULL)
    {
        printf("Vazia!\n");
    }
    else{
        printf("Inicio: %d\n", f->inicio->valor);
    }
}
void final(t_fila *f)
{
    if(f->final == NULL)
    {
        printf("Vazia!\n");
    }
    else{
        printf("Final: %d\n", f->final->valor);
    }
}