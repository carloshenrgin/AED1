#include <stdlib.h>
#include "..\headers\dupla-ord.h"

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

int insereOrd(list *lst, int elem){
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

    if(elem <= (*lst)->info){
        no->prox = *lst;
        no->prox->ant = no;
        *lst = no;
        return 1;
    }

    list aux = *lst;
    while(aux->prox != NULL && aux->prox->info < elem) // Tem algo dando errado por aqui. Sem cabeça pra arrumar agora
        aux = aux->prox;
    
    no->prox = aux->prox;
    if(aux->prox != NULL){
        no->prox->ant = no;
    }

    no->ant = aux;
    aux->prox = no;
    return 1;
}

int removeElem(list *lst, int elem){
    if(listaVazia(lst) == 1 || elem < (*lst)->info)
        return 0;
    list aux = *lst;
    while(aux->prox != NULL && aux->info < elem)
        aux = aux->prox;

    if(aux->info > elem)
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