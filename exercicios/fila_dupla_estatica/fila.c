#include "fila.h"

int inicializar(t_fila *f)
{
    f->inicio = -1;
    f->final = -1;

    return SUCESSO;
}

int insereInicio(int v, t_fila *f)
{
    if (f->inicio == -1 && f->final==-1)
    {
        f->inicio = 0;
        f->final = 0;
        f->fila[0] = v;
        return SUCESSO;
    }

    //if(f->final == (f->inicio - 1)%MAX){
    if(f->inicio - 1 == -1){
        if(f->final == MAX -1){
            printf("Lista cheia!\n");
            return CHEIA;
        }
    }
    if(f->final == (f->inicio - 1)%MAX){
        printf("Lista cheia!\n");
        return CHEIA;
    }

    f->inicio--;
    f->inicio = (f->inicio) % MAX;
    if(f->inicio == -1){
        f->inicio = MAX-1;
    }
    f->fila[f->inicio] = v;

    
    return SUCESSO;
}
int insereFinal(int v, t_fila *f)
{
    if (f->inicio == -1 && f->final==-1)
    {
        f->inicio = 0;
        f->final = 0;
        f->fila[0] = v;
        return SUCESSO;
    }

    if(f->inicio == (f->final + 1)%MAX){
        printf("Lista cheia!!\n");
        return CHEIA;
    }

    f->final++;
    f->final = (f->final) % MAX;
    if(f->final == -1){
        f->final = 0;
    }
    f->fila[f->final] = v;

    return SUCESSO;
}
int removeInicio(t_fila *f)
{
    if (f->inicio == -1 && f->final==-1)
    {
        printf("Lista vazia!\n");
        return VAZIA;
    }

    if(f->inicio == f->final){
        f->inicio = -1;
        f->final = -1;
        return SUCESSO;
    }

    f->inicio++;
    f->inicio = (f->inicio) % MAX;
    if(f->inicio == -1){
        f->inicio = 0;
    }
    

    return SUCESSO;
}
int removeFinal(t_fila *f)
{
    if (f->inicio == -1 && f->final==-1)
    {
        printf("Lista vazia!\n");
        return VAZIA;
    }

    if(f->inicio == f->final){
        f->inicio = -1;
        f->final = -1;
        return SUCESSO;
    }

    f->final--;
    f->final = (f->final) % MAX;
    if(f->final == -1){
        f->final = MAX-1;
    }

    return SUCESSO;
}
int vazia(t_fila *f)
{
    if (f->inicio == -1 && f->final==-1)
    {
        printf("Esta vazia!!!\n");
        return 1;
    }

    printf("Nao esta vazia!!!\n");
    return 0;
}

int cheia(t_fila *f)
{
    if(f->inicio == (f->final + 1)%MAX){
        printf("Lista cheia!!\n");
        return 1;
    }
    if(f->inicio - 1 == -1){
        if(f->final == MAX -1){
            printf("Lista cheia!\n");
            return 1;
        }
    }
    if(f->final == (f->inicio - 1)%MAX){
        printf("Lista cheia!\n");
        return 1;
    }

    return 0;

}

void inicio(t_fila *f)
{
    if(f->inicio == -1){
        printf("Está vazia!\n");
    }
    else{
        printf("Inicio: %d\n", f->fila[f->inicio]);
        printf("Index: %d\n", f->inicio);
    }
}
void final(t_fila *f)
{
    if(f->final == -1){
        printf("Está vazia!\n");
    }
    else{
        printf("Final: %d\n", f->fila[f->final]);
        printf("Index: %d\n", f->final);
    }
}