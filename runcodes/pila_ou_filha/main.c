#include <stdio.h>
#include "pila_ou_filha.h"
#include "fila.h"

int main(){

    int N;
    scanf("%d", &N);

    if(N > 100 || N < 1) return 1;  // Verifica se o número de casos de teste está dentro dos limites

    t_fila F;
    inicializar(&F);

    int aux;
    for(int i=0; i<N; i++){
        // Chama a função para cada caso de teste e armazena o resultado em 'aux'
        aux = pilaOuFilha();

        // Enfileira o resultado na fila
        enfileirar(aux, &F);
    }


    // Imprime os resultados
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