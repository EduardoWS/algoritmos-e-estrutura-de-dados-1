#include "fila.h"

int inicializar(t_fila *f)
{
    f->inicio = -1;
    f->final = -1;

    return SUCESSO;
}

int enfileirar(int v, t_fila *f)
{
    if(vazia(f)){
        f->inicio = 0;
        f->final = 0;
        f->fila[0] = v;
        return SUCESSO;
    }


    if(f->inicio == ((f->final + 1) % MAX)){
        return CHEIA;
    }

    f->final++;
    f->final = (f->final) % MAX;
    f->fila[f->final] = v;

    return SUCESSO;
}

int desenfileirar(t_fila *f)
{
    if(vazia(f)){
        return VAZIA;
    }
    if(f->inicio == f->final){
        f->inicio = -1;
        f->final = -1;
        return SUCESSO;
    }

    f->inicio++;
    f->inicio = (f->inicio) % MAX;
    return SUCESSO;
}

int vazia(t_fila *f)
{
    if(f->final == -1 && f->inicio == -1){
        return 1;
    }

    return 0;
}

int cheia(t_fila *f)
{

}

void inicio(t_fila *f)
{

}

void final(t_fila *f)
{

}