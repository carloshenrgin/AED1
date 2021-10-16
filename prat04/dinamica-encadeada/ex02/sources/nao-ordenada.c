#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "..\headers\nao-ordenada.h"


struct node{
    dados info;
    list prox;
};

list criaLista(){
    return NULL;
}

int listaVazia(list *lst){
    if(*lst == NULL)
        return 1;
    return 0;
}

int insereElem(list *lst, dados leitura){
    list no = (list) malloc(sizeof(struct node));
    if(no == NULL) return 0;
    
    no->info = leitura;

    no->prox = *lst;
    *lst = no; // *lst agora estava apontando para o segundo elemento assim como o novo nó, então essa associação faz esse ponteiro apontar para o nó
    // Por algum motivo a associação acima faz com que o elemento recém inserido seja copiado para o segundo
    return 1;
}

int removeElem(list *lst, dados leitura){
    if(listaVazia(lst) == 1) return 0;

    list aux = *lst; // Ponteiro auxiliar para o primeiro nó, para poder percorrer a lista sem perder o primeiro endereço


    if((*lst)->info.faltas == leitura.faltas && (*lst)->info.matricula == leitura.matricula && (*lst)->info.media == leitura.media && strcmp((*lst)->info.nome, leitura.nome) == 0){
        *lst = aux->prox;
        free(aux);
        return 1;
    }

    
    else{
        while(aux->prox != NULL && (strcmp(aux->prox->info.nome, leitura.nome) != 0 || aux->prox->info.faltas != leitura.faltas || aux->prox->info.media != leitura.media || aux->prox->info.matricula != leitura.matricula)){ // Enquanto meu ponteiro prox do auxiliar não apontar para nulo e a informação do meu próximo for diferente de elem eu continuo percorrendo
            aux = aux->prox;
        }
        if(aux->prox == NULL) return 0; // Se meu aux->prox apontar para NULL então a condição de parada do while foi de que eu cheguei no fim da lista. O elemento não está presente na lista
    
        list aux2 = aux->prox; // Meu aux aponta para o nó anterior àquele com os dados iguais aos que eu quero remover, então aux2 aponta recebe o endereço do que eu quero de fato remover
        aux->prox = aux2->prox; // aux->prox passa a apontar para o elemento após àquele a ser removido
        free(aux2);
        return 1;
    }
}

int tamanhoLista(list *lst){
    if(listaVazia(lst) == 1){
        return 0;
    }
    list aux = *lst;
    int cont = 1;
    while(aux->prox != NULL){
        aux = aux->prox;
        cont++;
    }
    return cont;
}

int getPos(list *lst, int pos){
    if(listaVazia(lst) == 1 || pos > tamanhoLista(lst)){
        return 0;
    }
    
    int i = 1;
    list aux = *lst;

    while(aux->prox != NULL && i < pos){
        aux = aux->prox;
        i++;
    }
    if(aux == NULL)
        return 0;

    else{
        printf("Dados na %da posicao:\nMatricula: %u\nNome: %s\nMedia: %.2f\nFaltas: %d\n\n", i, aux->info.matricula, aux->info.nome, aux->info.media, aux->info.faltas);
        return 1;
    }
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
    free(lst);
    return 1;
}