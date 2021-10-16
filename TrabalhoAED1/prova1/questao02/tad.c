#include <stdlib.h>
#include <string.h>
#include "tad.h"

#define MAX 20

struct node{
    struct bebida bebidas[MAX];
    int fim;
};

list criaLista(){
    list lst = (list) malloc(sizeof(struct node));
    if(lst != NULL){
        lst->fim = 0;
    }
    return lst;
}

int listaVazia(list lst){
    if(lst->fim == 0){
        return 1;
    }
    return 0;
}

int listaCheia(list lst){
    if(lst->fim == MAX){
        return 1;
    }
    return 0;
}

int igual(struct bebida novo, struct bebida atual){
    if(strcmp(novo.bebida, atual.bebida) == 0 && novo.vol == atual.vol)
        return 1;
    return 0;
}

int maior(struct bebida novo, struct bebida atual){
    if(strcmp(novo.bebida, atual.bebida) > 0 && novo.vol > atual.vol)
        return 1;
    return 0;
}

int menor(struct bebida novo, struct bebida atual){
    if(maior(novo, atual) == 0 && igual(novo, atual) == 0)
        return 1;
    return 0;
}

int insereBebida(list lst, struct bebida data){
    if(lst == NULL || listaCheia(lst) == 1){
        return 0;
    }

    if(listaVazia(lst) == 0 || maior(data, lst->bebidas[lst->fim - 1]) == 1 || igual(data, lst->bebidas[lst->fim -1]) == 1){
        lst->bebidas[lst->fim] = data;
    }
    else{
        int i, aux = 0;
        while(maior(data, lst->bebidas[aux]) == 1 || igual(data, lst->bebidas[aux])){
            aux++;
        }
        for(i = lst->fim; i > aux; i--){
            lst->bebidas[i] = lst->bebidas[i-1];
        }
        lst->bebidas[aux] = data;
    }
    lst->fim++;
    return 1;
}

int removeBebida(list lst, struct bebida data){
    if(lst == NULL || listaVazia(lst) == 1 || maior(data, lst->bebidas[lst->fim - 1]) == 1){
        return 0;
    }

    int i, aux = 0;
    while(aux < lst->fim && menor(lst->bebidas[aux], data) == 1){
        aux++;
    }
    if(aux == lst->fim || maior(lst->bebidas[aux], data) == 1){
        return 0;
    }

    for(i = aux + 1; i < lst->fim; i++){
        lst->bebidas[i-1] = lst->bebidas[i];
    }
    lst->fim--;
    return 1;
}