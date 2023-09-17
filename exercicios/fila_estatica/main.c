#include "fila.h"

int main(){
    
    t_fila f;

    inicializar(&f);

    enfileirar(5, &f);
    enfileirar(6, &f);
    enfileirar(7, &f);
    enfileirar(8, &f);

    printf("%d\n", f.inicio);
    printf("%d\n", f.final);

    printf("%d\n", f.fila[f.inicio]);
    printf("%d\n", f.fila[f.final]);

    desenfileirar(&f);
    enfileirar(8, &f);
    enfileirar(9, &f);

    desenfileirar(&f);
    desenfileirar(&f);
    //desenfileirar(&f);

    printf("%d\n", f.inicio);
    printf("%d\n", f.fila[f.inicio]);

    printf("\n%d\n", f.final);
    printf("%d\n", f.fila[f.final]);

    return 0;
}