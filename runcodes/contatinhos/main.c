#include "skip_list.h"
#include "fila.h"

int main(){

    t_skiplist* skip_list = criarSkipList(3);  // level de 0 a 3
    char operacao;
    char* nome = (char*)malloc(11 * sizeof(char));
    int telefone;
    int operacoes = 1;
    int flag;
    t_fila fila;
    inicializar(&fila);

    while (operacoes) {
        flag = 0;
        scanf(" %c", &operacao);
        if (operacao == '0') {
            break;
        } else if (operacao == 'I') {
            t_contato contato;
            scanf(" %s %d", contato.nome, &contato.telefone);
            flag = inserir(skip_list, contato);
            if(flag) enfileirar(-1, &fila);
            
        } else if (operacao == 'P'){
            t_no* pesquisa;
            scanf(" %s", nome);
            pesquisa = pesquisar(skip_list, nome);
            if(pesquisa == NULL){
                //printf("Contatinho nao encontrado\n");
                enfileirar(-2, &fila);
            }else{
                //printf("Contatinho encontrado: telefone %d\n", pesquisa->contato.telefone);
                enfileirar(pesquisa->contato.telefone, &fila);
            }

        } else if (operacao == 'A'){
            t_contato contato;
            scanf(" %s %d", contato.nome, &contato.telefone);
            flag = alterar(skip_list, contato);

            if(flag) enfileirar(-3, &fila);
            

        } else if (operacao == 'R'){
            scanf(" %s", nome);
            flag = remover(skip_list, nome);

            if(flag) enfileirar(-3, &fila);
        }

        //operacoes++;
    }

    
    while(!vazia(&fila)){
        flag = desenfileirar(&fila);
        if(flag == -1){
            printf("Contatinho ja inserido\n");
        } else if(flag == -2){
            printf("Contatinho nao encontrado\n");
        } else if(flag == -3){
            printf("Operacao invalida: contatinho nao encontrado\n");
        } else if (flag > 0){
            printf("Contatinho encontrado: telefone %d\n", flag);
        }
    }

    free(nome);
    liberarSkipList(skip_list);

    return 0;
}