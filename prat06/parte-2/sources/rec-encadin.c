#include <stdlib.h>
#include "..\headers\rec-encadin.h"

struct node{
    double info;
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

int insereOrd(list *lst, double input){
    int r;
    if(listaVazia(lst) == 1 || input <= (*lst)->info){
        list newNode = (list) malloc(sizeof(struct node));
        if(newNode == NULL)
            return 0;
        newNode->info = input;
        newNode->prox = *lst;
        *lst = newNode;
        return 1;
    }
    else{
        r = insereOrd(&((*lst)->prox), input);
        return r;
    }
}

int removeOrd(list *lst, double input){
    if(listaVazia(lst) == 1 || input < (*lst)->info)
        return 0;
    else{
        int r;
        if(input == (*lst)->info){
            list aux = (*lst);
            *lst = aux->prox;
            free(aux);
            return 1;
        }
        else{
            r = removeOrd(&((*lst)->prox), input);
            return r;
        }
    }
}


int getData(list *lst, int input, double *output){
    if(listaVazia(lst) == 1)
        return 0;

    int size = 1;
    list aux = *lst;
    while(aux->prox != NULL){
        size++;
        aux = aux->prox;        
    }

    if(input > size)
        return 0;

    aux = *lst;
    while(input > 1){
        aux = aux->prox;
        input--;
    }

    *output = aux->info;
    return 1;
}