#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "..\headers\bebida-ordenada.h"
#define MAX 20

struct bebidas{
    char nome[21];
    int volume;
    float preco;
};

struct lista{
    bebida *no[MAX];
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


int insereOrd(list lst, char nome[], int vol, float preco){
    lst->no[lst->fim] = (bebida *) malloc(sizeof(bebida)); 
    if(lst == NULL || listaCheia(lst) == 1){
        return 0;
    }

    // Se o strcmp retornar menor que zero, a primeira string é menor em valor alfabetico que a segunda
    if(listaVazia(lst) == 1){
        strcpy(lst->no[lst->fim]->nome, nome);
        lst->no[lst->fim]->volume = vol;
        lst->no[lst->fim]->preco = preco;
    }


    else if(strcmp(nome, lst->no[lst->fim - 1]->nome) > 0){
            strcpy(lst->no[lst->fim]->nome, nome);
            lst->no[lst->fim]->volume = vol;
            lst->no[lst->fim]->preco = preco;
    }

    else if(strcmp(nome, lst->no[lst->fim - 1]->nome) == 0 && vol >= lst->no[lst->fim - 1]->volume){
        strcpy(lst->no[lst->fim]->nome, nome);
        lst->no[lst->fim]->volume = vol;
        lst->no[lst->fim]->preco = preco;
    }

    else{
        int i, aux = 0;
        while(strcmp(nome, lst->no[aux]->nome) > 0)
            aux++;
        if(strcmp(nome, lst->no[aux]->nome) == 0){
            if(vol >= lst->no[aux]->volume){
                aux++;
            }
        }
        for(i = lst->fim; i > aux; i--){
            strcpy(lst->no[i]->nome, lst->no[i-1]->nome);
            lst->no[i]->volume = lst->no[i-1]->volume;
            lst->no[i]->preco = lst->no[i-1]->preco;
        }
        strcpy(lst->no[aux]->nome, nome);
        lst->no[aux]->volume = vol;
        lst->no[aux]->preco = preco;
    }
    lst->fim++;
    return 1;
}

int removeOrd(list lst, char nome[], int vol, float preco){
    if(lst == NULL || listaVazia(lst) == 1 || strcmp(nome, lst->no[lst->fim - 1]->nome) > 0 || strcmp(nome, lst->no[0]->nome) < 0)
        return 0;
    int i, aux = 0;

    while(aux < lst->fim && (strcmp(lst->no[aux]->nome, nome) != 0 || lst->no[aux]->volume != vol || lst->no[aux]-> preco != preco)){
        aux++;
    }

    if(aux == lst->fim) return 0;
    for(i = aux+1; i < lst->fim; i++){
        strcpy(lst->no[i-1]->nome, lst->no[i]->nome);
        lst->no[i-1]->volume = lst->no[i]->volume;
        lst->no[i-1]->preco = lst->no[i]->preco;
    }

    free(lst->no[lst->fim - 1]);
    lst->fim--;
    return 1;
}

void getElem(list lst, int pos){
    if(lst == NULL || listaVazia(lst) == 1 || pos > lst->fim)
        printf("Lista vazia, nao inicializada ou posicao nao preenchida\nImpossivel mostrar elemento\n");
    printf("Nome da %da bebida: %s\n", pos, lst->no[pos-1]->nome);
    printf("Volume da %da bebida: %dmL\n", pos, lst->no[pos-1]->volume);
    printf("Preco da %da bebida: %.2f\n", pos, lst->no[pos-1]->preco);
}

int limpaLista(list lst){
    if(lst == NULL || listaVazia(lst) == 1)
        return 0;
    int i = 0;
    while(i < lst->fim){
        free(lst->no[i]);
    }
    free(lst);
    return 1;
}

int tamanhoLista(list lst){
    if(lst == NULL) return 0;
    return lst->fim;
}