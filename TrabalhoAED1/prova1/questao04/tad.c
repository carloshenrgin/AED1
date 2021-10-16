#include <stdlib.h>
#include "tad.h"

struct node{
    float info;
    struct node* prox;
    struct node* ant;
};

list criaLista(){
    return NULL;
}

int listaVazia(list *lst){
    if(*lst == NULL)
        return 1;
    return 0;
}

int insereOrd(list *lst, float elem){
    list no = (list) malloc(sizeof(struct node));
    if(no == NULL)
        return 0;

    no->info = elem;

    if(listaVazia(lst) == 1){
        no->prox = NULL;
        no->ant = NULL;
        (*lst) = no;
        return 1;
    }

    if(elem >= (*lst)->info){
        no->prox = *lst;
        no->prox->ant = no;
        *lst = no;
        return 1;
    }

    list aux = *lst;
    while(aux->prox != NULL && aux->prox->info > elem)
        aux = aux->prox;
    
    no->prox = aux->prox;
    if(aux->prox != NULL){
        no->prox->ant = no;
    }

    no->ant = aux;
    aux->prox = no;
    return 1;
}

int getPosElem(list *lst, float elem, int *pos){
    if(listaVazia(lst) == 1 || elem < (*lst)->info){
        return 0;
    }

    list aux = *lst;
    int i = 1;
    while(aux->prox != NULL && aux->prox->info != elem){
        aux = aux->prox;
        i++;
    }
    if(aux->prox == NULL){
        return 0;
    }
    else{
        *pos = i;
    }
    return 1;
}