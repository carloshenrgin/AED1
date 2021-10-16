#include <stdlib.h>
#include "tad.h"

struct node{
    char info;
    struct node* prox;
};

list criaLista(){
    return NULL;
}

int listaVazia(list *lst){
    if(lst == NULL)
        return 1;
    return 0;
}

int insereOrd(list *lst, char elem){
    list newNode = (list) malloc(sizeof(struct node));
    if(newNode == NULL)
        return 0;
    
    newNode->info = elem;
    if(listaVazia(lst) == 1 || elem <= (*lst)->info){
        newNode->prox = *lst;
        *lst = newNode;
        return 1;
    }
    list aux = *lst;
    while(aux->prox != NULL && aux->prox->info < elem){
        aux = aux->prox;
    }

    newNode->prox = aux->prox;
    aux->prox = newNode;
    return 1;
}

int removeOrd(list *lst, char elem){
    if(listaVazia(lst) == 1 || elem < (*lst)->info){
        return 0;
    }

    list aux = *lst;
    if(elem == (*lst)->info){
        *lst = aux->prox;
        free(aux);
        return 1;
    }

    while(aux->prox != NULL && aux->prox->info < elem){
        aux = aux->prox;
    }

    if(aux->prox == NULL || aux->prox->info > elem){
        return 0;
    }

    list aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    return 1;
}

int intercala(list *lst, list *lst2, list *lst3){
    list aux = *lst;
    int retorno;

    *lst3 = criaLista();
    if(*lst3 == NULL){
        return 0;
    }
    while(aux != NULL){
        retorno = insereOrd(lst3, aux->info);
        aux = aux->prox;
        if(retorno == 0){
            return 0;
        }
    }
    aux = *lst2;
    while(aux != NULL){
        retorno = insereOrd(lst3, aux->info);
        aux = aux->prox;
        if(retorno == 0){
            return 0;
        }
    }
    
    return 1;
}