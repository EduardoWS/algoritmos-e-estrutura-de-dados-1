#include "fila.h"

int main(){
    
    t_fila f;
    inicializar(&f);

    insereFinal(5, &f);
    insereFinal(6, &f);
    insereFinal(7, &f);
    insereFinal(8, &f);

    return 0;

}