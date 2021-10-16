#include <stdio.h>
#include <stdlib.h>
#include "..\headers\encadin.h"

struct node{
    char info;
    struct node *prox;
};


lista criaLista(){
    return NULL;    
}

int listaVazia(lista *lst){
    if(*lst == NULL)
        return 1;
    return 0;
}

int listaCheia(lista *lst){
    return 0;
}

int insereElem(lista *lst, char item){
    lista no = (lista) malloc(sizeof(struct node));
    if(no == NULL) return 0;
    no->info = item;
    if(listaVazia(lst) || item <= (*lst)->info){
        no->prox = *lst;
        *lst = no;
        return 1;
    }
    lista aux = *lst;
    while(aux->prox != NULL && aux->prox->info < item){
        aux = aux->prox;
    }

    no->prox = aux->prox;
    aux->prox = no;
    return 1;
}

int removeElem(lista *lst, char item){
    if(listaVazia(lst) == 1 || item < (*lst)->info)
        return 0;
    lista aux = *lst;
    if(item == (*lst)->info){ //Se meu item for igual a informação no conteúdo de ontem lst aponta (primeiro node), meu *lst passa a apontar para onde prox aponta e aux é liberado (antigo endereço para onde lst apontava)
        *lst = aux->prox;
        free(aux);
        return 1;
    }
    while(aux->prox != NULL && aux->prox->info < item){ // Enquanto meu aux nao estiver apontando para NULL (fim da lista) e a informação do próximo node não for meu item eu avanço minha lista
        aux = aux->prox;
    }
    if(aux->prox == NULL || aux->prox->info > item) // Seu meu aux prox apontar para NULL depois disso quer dizer que eu não achei meu item, então a remoção falhou
        return 0; 

    lista aux2 = aux->prox; // Se a informação do meu próximo node for o meu item, meu nó auxiliar recebe o endereço de onde o item se encontra
    aux->prox = aux2->prox; // Meu nó auxiliar passa a apontar para o node depois de onde o elemento se encontra
    free(aux2); // Meu node com o elemento é liberado, sucesso na remoção
    return 1;
}

int obtemPos(lista *lst, int pos){
    if(listaVazia(lst) == 1)
        return 0;
    int i;
    lista aux = *lst;
    for(i = 0; i < pos; i++){ // enquanto meu i não chegar na posição desejada da lista eu avanço meu nó auxiliar
        aux = aux->prox;
        if(aux == NULL){ // Se meu nó for NULL então eu percorri toda a minha lista e não achei aquela posição, ou seja, minha lista não tem aquela posição ainda
            return 0;
        }
    }
    printf("Item na %d posicao: %c\n", pos, aux->info);
    return 1;
}

int limpaLista(lista *lst){
    if(listaVazia(lst) == 1) return 0;
    lista aux;
    while(*lst != NULL){
        aux = *lst;
        *lst = (*lst)->prox;
        free(aux);
    }
    free(lst);
    return 1;
}