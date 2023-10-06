#include "pila_ou_filha.h"
#include "fila.h"
#include "pilha.h"

int pilaOuFilha(){
    int K;
    scanf("%d", &K);

    if(K < 2 || K > 100) return -1;

    char C;
    int I;
    int removido;
    int flag_pilha = 1, flag_fila = 1;
    int cont_r=0;

    t_pilha P;
    t_fila F;
    inicializarPilha(&P);
    inicializar(&F);

    int eh_Pilha=0, eh_Fila=0; // 0 = não; 1 = sim

    for(int i=0; i<K; i++){
        scanf(" %c", &C);
        scanf("%d", &I);

        //if(i==0 && C == 'r') return IMPOSSIVEL;
        //if(C == 'r' && (vaziaPilha(&P) || vazia(&F))) return IMPOSSIVEL; 

        if(C == 'i') {
            // Insere na pilha e na fila
            push(I, &P);
            enfileirar(I, &F);

        }else if(C == 'r'){
            cont_r++;
            if(vaziaPilha(&P) || vazia(&F)) return IMPOSSIVEL;

            if(flag_pilha){
                removido = pop(&P);
                eh_Pilha = (removido == I)? 1 : 0;
                if(eh_Pilha == 0) flag_pilha = 0; // Se não corresponde, pilha é impossível
            }

            if(flag_fila){
                eh_Fila = (I == F.fila[F.inicio])? 1 : 0;
                desenfileirar(&F);
                if(eh_Fila == 0) flag_fila = 0;  // Se não corresponde, fila é impossível
            }
            

        }

    }

    if(cont_r == 0){
        eh_Pilha = 1;
        eh_Fila = 1;
    }

    if(eh_Pilha == 1 && eh_Fila == 0) return PILHA;
    else if(eh_Pilha == 0 && eh_Fila == 1) return FILA;
    else if(eh_Pilha == 1 && eh_Fila == 1) return INDEFINIDO;
    else if(eh_Pilha == 0 && eh_Fila == 0) return IMPOSSIVEL;

}