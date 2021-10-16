#include <stdlib.h>
#include "..\headers\nord.h"

struct node{
    int info;
    struct node *prox;
};

list criaLista(){
    list cab = (list) malloc(sizeof(struct node));

    if(cab != NULL){
        cab->info = 0;
        cab->prox = NULL;
    }

    return cab;
}

int listaVazia(list lst){
    if(lst->prox == NULL)
        return 1;
    
    return 0;
}

int insereElem(list lst, int elem){
    list no = (list) malloc(sizeof(struct node));
    if(no == NULL)
        return 0;

    no->info = elem;
    no->prox = lst->prox;
    lst->prox = no;
    lst->info++;
    return 1;
}

int removeElem(list lst, int elem){
    if(listaVazia(lst) == 1)
        return 0;
    list aux = lst;
    while(aux->prox != NULL && aux->prox->info != elem)
        aux = aux->prox;
    if(aux->prox == NULL)
        return 0;
    
    list aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    lst->info--;
    return 1;
}

int getElem(list lst, int pos, int *output){
    if(pos > lst->info){
        return 0;
    }

    list aux = lst;
    while(aux->prox != NULL && pos > 1){
        aux = aux->prox;
        pos--;
    }
    *output = aux->prox->info;
    return 1;
}

void limpaLista(list lst){
    list aux = lst;
    while(aux->prox != NULL){
        lst = lst->prox;
        free(aux);
        aux = lst;
    }
}