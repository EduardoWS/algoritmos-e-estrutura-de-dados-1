#include <stdio.h>
#include "pila_ou_filha.h"
#include "fila.h"

int main(){

    int N;
    scanf("%d", &N);

    if(N > 100 || N < 1) return 1;

    t_fila F;
    inicializar(&F);

    int aux;
    for(int i=0; i<N; i++){
        aux = pilaOuFilha();
        enfileirar(aux, &F);
    }

    while(!vazia(&F)){
        aux = desenfileirar(&F);
        if(aux == 1){
            printf("pilha\n");
        }else if(aux == 2){
            printf("fila\n");
        }else if(aux == 3){
            printf("indefinido\n");
        }else{
            printf("impossivel\n");
        }
    }


    return 0;
}