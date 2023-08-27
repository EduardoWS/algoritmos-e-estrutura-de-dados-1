#include <stdio.h>
#include <string.h>

#include "conjuntos.h"

void inicializar(t_conjunto A){
	memset(A, 0, sizeof(t_conjunto));
}

int limite(t_elemento e){

	if(e < 0 || e > maximo){
		printf("o valor %d é invalido\n", e);
		return 1;
	}

	return 0;

}

int pertence(t_elemento e, t_conjunto A){
	if (limite(e)){
		return INVALIDO;
	}

	return A[e];
}

int inserir(t_elemento e, t_conjunto A){

	if(limite(e)){
		return INVALIDO;
	}

	if(pertence(e, A)){
		return JA_EXISTE;
	}

	A[e] = 1;

	return SUCESSO;
}


int remover(t_elemento e, t_conjunto A){

	if(limite(e)){
		return INVALIDO;
	}

	if(!pertence(e, A)){
		printf("O valor %d nao esta no vetor.\n", e);
		return NAO_EXISTE;
	}

	A[e] = 0;

	return SUCESSO;

}


void interseccao(t_conjunto A, t_conjunto B, t_conjunto C){

	for(int i = 0; i <= maximo; i++){

		if(A[i] == 1 && B[i] == 1){
			C[i] = 1;
		}
	}
}


void uniao(t_conjunto A, t_conjunto B, t_conjunto C){

	for(int i = 0; i <= maximo; i++){

		if(A[i] == 1 || B[i] == 1){
			C[i] = 1;
		}
	}

}




void imprimir(t_conjunto A){

	printf("{");

	for (int i = 0; i < maximo+1; i++) {
		if (pertence(i, A)) {
			printf("%d, ", i);
		}
	}

	printf("}\n");



}