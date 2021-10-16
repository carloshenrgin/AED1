#include <stdlib.h>
#include "..\headers\ordenada.h"

struct node{
    int info;
    struct node* prox;
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
    if(no == NULL) return 0;

    no->info = elem;

    if(listaVazia(lst) == 1 || elem <= (*lst)->info ){ // Se a minha lista tiver vazia ou se meu elemento for menor/igual que a info do primeiro eu insiro ele no começo
        no->prox = *lst;
        *lst = no;
        return 1;
    }

    list aux = *lst;
    while(aux->prox != NULL && aux->prox->info < elem){ // Se eu chegar no fim da lista eu paro e se eu achar um elemento maior ou igual ao meu eu paro também
        aux = aux->prox;
    }

    no->prox = aux->prox;
    aux->prox = no;
    return 1;
}

int removeOrd(list *lst, int elem){
    if(listaVazia(lst) == 1 || elem < (*lst)->info)
        return 0;

    list aux = *lst;

    if(elem == (*lst)->info){
        *lst = aux->prox;
        free(aux);
        return 1;
    }

    
    while(aux->prox != NULL && aux->prox->info < elem) // Se meu aux->prox for NULL eu não posso mais percorrer e se meu aux->prox->info nao for menor que o meu elemento eu nao tenho mais porque percorrer
        aux = aux->prox;
    if(aux->prox == NULL || aux->prox->info > elem) // Como eu to olhando a informação da frente para comparar, se o aux->prox for NULL nao tem mais info pra olhar e se a info da frente for maior que o elemento ele nao tá na lista
        return 0;

    list aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    return 1;
}

int tamanhoLista(list *lst){
    if(listaVazia(lst) == 1)
        return 0;

    list aux = *lst;
    int cont = 1;

    while(aux->prox != NULL){
        aux = aux->prox;
        cont++;
    }
    return cont;
}

int limpaLista(list *lst){
    if(listaVazia(lst) == 1){
        return 0;
    }
    
    int i;
    list aux;
    for(i = 0; i < tamanhoLista(lst); i++){
        aux = *lst;
        *lst = aux->prox;
        free(aux);
    }
    free(*lst);
    return 1;
}

int getElem(list *lst, int pos, int *out){
    if(listaVazia(lst) == 1 || pos > tamanhoLista(lst)){
        return 0;
    }
    
    list aux = *lst;
    while(pos > 1){
        aux = aux->prox;
        pos--;
    }
    *out = aux->info;
    return 1;
}

int removePos(list *lst, int pos, int *out){
    if(listaVazia(lst) == 1 || pos > tamanhoLista(lst)){
        return 0;
    }

    list aux = *lst;
    getElem(lst, pos, out);
    while(aux->prox != NULL && pos > 2){
        aux = aux->prox;
        pos--;
    }

    list aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    return 1;
}