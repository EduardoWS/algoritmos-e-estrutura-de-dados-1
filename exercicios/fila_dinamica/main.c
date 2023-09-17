#include "fila.h"

int main(){

    t_fila f;

    inicializar(&f);

    enfileirar(5, &f);

    printf("%d\n", f.inicio->valor);
    printf("%d\n", f.final->valor);

    enfileirar(6, &f);
    enfileirar(7, &f);

    printf("\n%d\n", f.inicio->valor);
    printf("%d\n", f.final->valor);

    desenfileirar(&f);

    printf("\n%d\n", f.inicio->valor);
    printf("%d\n", f.final->valor);

    desenfileirar(&f);
    desenfileirar(&f);

    printf("\n%p\n", f.inicio);
    printf("%p\n", f.final);

    return 0;
}