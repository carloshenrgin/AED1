#include <stdlib.h>
#include <stdio.h>
#include "..\headers\naoordenada.h"
#define MAX 20

struct lista{
    float no[MAX];
    int fim;
};

list criaLista(){
    list lst = (list) malloc(sizeof(struct lista));
    if(lst == NULL){
        printf("Erro ao criar lista\n");
    }
    else lst->fim = 0;
    return lst;
}

int listaVazia(list lst){
    if(lst->fim == 0)
        return 1;
    else return 0;
}

int listaCheia(list lst){
    if(lst->fim == MAX){
        return 1;
    }
    else return 0;
}

int insereElem(list lst, float elem){
    if(lst->fim == MAX || lst == NULL){
        return 0;
    }
    
    lst->no[lst->fim] = elem;
    lst->fim++;
    return 1;
}

int removeElem(list lst, float elem){
    if(lst == NULL || listaVazia(lst) == 1)
        return 0;

    int i, aux = 0;
    while(aux < lst->fim && lst->no[aux] != elem)
        aux++;
    
    if(aux == lst->fim)
        return 0;

    for(i = aux+1; i < lst->fim; i++)
        lst->no[i-1] = lst->no[i];
    
    lst->fim--;
    return 1;
}

void limpaLista(list lst){
    free(lst);
    lst = criaLista();
}

void getPos(list lst, int pos){
    if(lst == NULL || listaVazia(lst))
        printf("Lista Vazia ou Nao Inicializada\nImpossivel Informar Valor na Posicao Desejada\n");
    else if(lst->fim <= pos)
        printf("Posicao informada ainda nao preenchida\nImpossivel Informar Valor na Posicao Desejada\n");
    else if(pos > MAX)
        printf("Posicao informada maior do que o tamanho da lista\n Impossivel Informar o Valor na Posicao Desejada");
    else
        printf("Valor na %da posicao da lista: %f\n", pos, lst->no[pos-1]);
}

void imprimeLista(list lst){
    if(lst == NULL || listaVazia(lst)){
        printf("Lista Vazia ou Nao Inicializada\nImpossivel Imprimir Lista\n");
    }
    else{
        int i;
        for(i = 0; i < lst->fim; i++){
            printf("Valor na %da posicao da lista: %.2f\n", i+1, lst->no[i]);
        }
    }
}