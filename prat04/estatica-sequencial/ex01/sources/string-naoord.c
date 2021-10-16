#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "..\headers\string-naoord.h"
#define MAX 20

struct lista{
    char frase[MAX][11];
    int fim;
};

list criaLista(){
    list lst = (list) malloc(sizeof(struct lista));
    if(lst != NULL){
        
        lst->fim = 0;
    }
    return lst;
}

int listaVazia(list lst){
    if(lst->fim == 0)
        return 1;

    else return 0;
}

int listaCheia(list lst){
    if(lst->fim == MAX)
        return 1;
    else return 0;
}


int insereElem(list lst, char frase[]){ 
    if(lst == NULL || listaCheia(lst) == 1){
        return 0;
    }
    strcpy(lst->frase[lst->fim], frase);
    lst->fim++;
    return 1;
}

int removeElem(list lst, char nome[]){
    if(lst == NULL || listaVazia(lst) == 1)
        return 0;
    int i, aux = 0;

    while(aux < lst->fim && strcmp(lst->frase[aux], nome) != 0){
        aux++;
    }

    if(aux == lst->fim) return 0;
    for(i = aux+1; i < lst->fim; i++){
        strcpy(lst->frase[i-1], lst->frase[i]);
    }

    lst->fim--;
    return 1;
}

void getElem(list lst, int pos){
    if(lst == NULL || listaVazia(lst) == 1 || pos > lst->fim)
        printf("Lista vazia, nao inicializada ou posicao nao preenchida\nImpossivel mostrar elemento\n");
    printf("%da String: %s\n", pos, lst->frase[pos-1]);
}

int limpaLista(list lst){
    if(lst == NULL || listaVazia(lst) == 1)
        return 0;
    free(lst);
    return 1;
}

int tamanhoLista(list lst){
    if(lst == NULL) return 0;
    return lst->fim;
}