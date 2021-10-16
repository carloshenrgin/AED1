#include <stdlib.h>
#include "..\headers\circular.h"

struct node{
    int info;
    struct node *prox;
};

list criaLista(){
    return NULL;
}

int listaVazia(list *lst){
    if(*lst == NULL)
        return 1;

    return 0;
}

int insereInicio(list *lst, int input){
    list no = (list) malloc(sizeof(struct node));
    if(no == NULL)
        return 0;

    no->info = input;
    if(listaVazia(lst) == 1){
        no->prox = no;
        *lst = no;
    }
    else{
        no->prox = (*lst)->prox;
        (*lst)->prox = no;
    }
    return 1;
}

int removeFinal(list *lst, int *output){
    if(listaVazia(lst) == 1){
        return 0;
    }

    list aux = (*lst);
    *output = aux->info;
    if(*lst == (*lst)->prox){
        *lst = NULL;
    }
    else{
        while((*lst)->prox != aux)
            (*lst) = (*lst)->prox;
        
        (*lst)->prox = aux->prox;
    }
    free(aux);
    return 1;
}

int obtemValor(list *lst, int pos, int *output){
    if(listaVazia(lst) == 1)
        return 0;

    int tam = 0;
    list aux = *lst;
    do{
        aux = aux->prox;
        tam++;
    }while(aux != *lst);

    if(pos > tam)
        return 0;

    while(pos > 1){
        aux = aux->prox;
        pos--;
    }

    *output = aux->prox->info;
    return 1;
}