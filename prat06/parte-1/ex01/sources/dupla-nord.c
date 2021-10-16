#include <stdlib.h>
#include "..\headers\dupla-nord.h"

struct node{
    int info;
    struct node *ant;
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

int insereElem(list *lst, int elem){
    list no = (list) malloc(sizeof(struct node));
    if(no == NULL)
        return 0;

    no->info = elem;
    no->ant = NULL;
    no->prox = *lst;
    if(listaVazia(lst) == 0)
        (*lst)->ant = no;
    *lst = no;
    return 1;
}

int removeElem(list *lst, int elem){
    if(listaVazia(lst) == 1)
        return 0;
    list aux = *lst;
    while(aux->prox != NULL && aux->info != elem)
        aux = aux->prox;

    if(aux->info != elem)
        return 0;
    
    if(aux->prox != NULL)
        aux->prox->ant = aux->ant;

    if(aux->ant != NULL)
        aux->ant->prox = aux->prox;

    if(aux == *lst)
        *lst = aux->prox;

    free(aux);
    return 1;
}

int obtemValor(list *lst, int *output, int pos){
    if(listaVazia(lst) == 1)
        return 0;
    
    list aux = *lst;
    int tam = 1;
    while(aux->prox != NULL){
        aux = aux->prox;
        tam++;
    }

    if(pos > tam)
        return 0;

    aux = *lst;
    while(pos > 1){
        aux = aux->prox;
        pos--;
    }

    *output = aux->info;
    return 1;
}