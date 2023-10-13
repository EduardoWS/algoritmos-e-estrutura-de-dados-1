#include "skip_list.h"


static int sortearLevel(int max_level){
    int level = 0;
    while (rand() % 2 && level < max_level) {
        level++;
    }

    return level;
}

static t_no* criarNo(t_contato contato, int level){
    t_no* novo_no = (t_no*)malloc(sizeof(t_no));
    novo_no->contato = contato;
    novo_no->proximo = (t_no**)malloc((level + 1) * sizeof(t_no*));
    for(int i = 0; i<=level; i++){
        novo_no->proximo[i] = NULL;
    }
    
    return novo_no;
}

t_skiplist* criarSkipList(int max_level){

    t_skiplist* skip_list = (t_skiplist*)malloc(sizeof(t_skiplist));
    skip_list->max_level = max_level;
    skip_list->level = 0;
    skip_list->sentinela = criarNo((t_contato){"", -1}, max_level);

    return skip_list;
}

int inserir(t_skiplist* skip_list, t_contato contato){


    t_no* pesquisa = pesquisar(skip_list, contato.nome);
    if(pesquisa != NULL){
        //printf("Contatinho ja inserido\n");
        return 1;
    }

   
    t_no* update[skip_list->max_level + 1]; //tabela com os ponteiros que serão atualizados
    t_no* current = skip_list->sentinela;

    for (int i = skip_list->level; i >= 0; i--) {
        while (current->proximo[i] != NULL &&
               strcmp(current->proximo[i]->contato.nome, contato.nome) < 0) {
            current = current->proximo[i];
        }
        update[i] = current;
    }

    int new_level = sortearLevel(skip_list->max_level);
    //printf("\nnovo level: %d\n\n", new_level);
    if (new_level > skip_list->level) {
        for (int i = skip_list->level + 1; i <= new_level; i++) {
            update[i] = skip_list->sentinela;
        }
        skip_list->level = new_level;
    }

    t_no* new_node = criarNo(contato, new_level);

    for (int i = 0; i <= new_level; i++) {
        new_node->proximo[i] = update[i]->proximo[i];
        update[i]->proximo[i] = new_node;
    }

    return 0;
    
}

int alterar(t_skiplist* skip_list, t_contato contato){
    t_no* pesquisa = pesquisar(skip_list, contato.nome);
    if(pesquisa == NULL){
        //printf("Operacao invalida: contatinho nao encontrado\n");
        return 1;
    }

    remover(skip_list, contato.nome);
    inserir(skip_list, contato);

    return 0;
}

int remover(t_skiplist* skip_list, char* nome){
    t_no* update[skip_list->max_level + 1];
    t_no* current = skip_list->sentinela;

    for (int i = skip_list->level; i >= 0; i--) {
        while (current->proximo[i] != NULL &&
               strcmp(current->proximo[i]->contato.nome, nome) < 0) {
            current = current->proximo[i];
        }
        update[i] = current;
    }

    current = current->proximo[0];

    if (current != NULL && strcmp(current->contato.nome, nome) == 0) {
        for (int i = 0; i <= skip_list->level; i++) {
            if (update[i]->proximo[i] != current)
                break;
            update[i]->proximo[i] = current->proximo[i];
        }
        free(current->proximo);
        free(current);
        while (skip_list->level > 0 &&
               skip_list->sentinela->proximo[skip_list->level] == NULL) {
            skip_list->level--;
        }
    } else {
        //printf("Operacao invalida: contatinho nao encontrado\n");
        return 1;
    }

    return 0;
}

t_no* pesquisar(t_skiplist* skip_list, char* nome){

    t_no* current = skip_list->sentinela;
    for (int i = skip_list->level; i >= 0; i--) {
        while (current->proximo[i] != NULL &&
               strcmp(current->proximo[i]->contato.nome, nome) < 0) {
            current = current->proximo[i];
        }
    }
    current = current->proximo[0];
    if (current != NULL && strcmp(current->contato.nome, nome) == 0) {
        return current; // Contatinho encontrado
    } else {
        return NULL; // Contatinho não encontrado
    }

}

static void liberarNos(t_no* no) {
    if (no == NULL) {
        return;
    }
    liberarNos(no->proximo[0]); // Liberar os nós seguintes recursivamente
    free(no->proximo); // Liberar o array de ponteiros
    free(no); // Liberar o próprio nó
}

void liberarSkipList(t_skiplist* skip_list) {
    liberarNos(skip_list->sentinela); // Começar a liberação a partir do sentinela
    free(skip_list); // Liberar a estrutura da skip list
}