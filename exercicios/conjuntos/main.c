#include <stdio.h>
#include "conjuntos.h"

int main(){

    t_conjunto A, B, C, D;

    inicializar(A);
    inicializar(B);
    inicializar(C);
    inicializar(D);

    inserir(50, A);
    inserir(25, A);
    inserir(100, A);

    inserir(25, B);
    inserir(100, B);
    inserir(500, B);
    inserir(1000, B);
    remover(1000, B);

    interseccao(A, B, C);
    uniao(A, B, D);

    imprimir(A);
    imprimir(B);
    imprimir(C);
    imprimir(D);
    

    return 0;
}