#include "fila.h"

int main(){

    t_fila f;

    inicializar(&f);

    //vazia(&f);
    //inicio(&f);
    //final(&f);

    insereFinal(5, &f);
    insereFinal(6, &f);
    insereFinal(7, &f);
    insereInicio(4, &f);
    removeInicio(&f);
    removeInicio(&f);
    removeInicio(&f);
    removeInicio(&f);
    
    inicio(&f);
    final(&f);


    return 0;
}