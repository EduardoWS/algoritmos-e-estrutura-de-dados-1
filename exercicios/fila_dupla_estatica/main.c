#include "fila.h"

int main(){
    
    t_fila f;
    inicializar(&f);

    insereFinal(5, &f);
    insereFinal(6, &f);
    insereFinal(7, &f);
    //insereFinal(8, &f);

    //insereInicio(8, &f);
    inicio(&f);
    final(&f);

    vazia(&f);
    cheia(&f);

    //insereInicio(8, &f);
    removeInicio(&f);
    //removeInicio(&f);
    //removeInicio(&f);
    insereFinal(5, &f);
    insereFinal(5, &f);


    inicio(&f);
    final(&f);



    return 0;

}