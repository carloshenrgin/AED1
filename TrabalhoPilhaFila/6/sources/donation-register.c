#include <stdlib.h>
#include <string.h>
#include "..\headers\donation-register.h"

struct node{
    char name[20];
    int organFlag[5];
    char recNames[5][20];
    struct node* next;
};

list initList(){
    return NULL;
}

int emptyList(list l){
    if(l == NULL)
        return 1;
    return 0;
}

int evenNode(list listed, list comp){
    if(strcmp(listed->name, comp->name) == 0){
        int i, dif = 0;
        for(i = 0; i < 5; i++){
            if(listed->organFlag[i] != comp->organFlag[i] || strcmp(listed->recNames[i], comp->recNames[i]) != 0 ){
                dif = 1;
                break;
            }
        }
        if(dif == 0)
            return 1;
    }
    return 0;
}

int insertNode(list *l, char *name, int *organFlags, char **recNames){
    list newNode = (list) malloc(sizeof(struct node));
    if(newNode == NULL)
        return 0;

    int i;

    strcpy(newNode->name, name);
    for(i = 0; i < 5; i++){
        strcpy(newNode->recNames[i], *(recNames + i));
        newNode->organFlag[i] = *(organFlags + i);
    }

    if(emptyList(*l) == 1){
        newNode->next = newNode;
        *l = newNode;
    }
    else{
        newNode->next = (*l)->next;
        (*l)->next = newNode;
        *l = newNode;
    }

    return 1;
}

int removeNode(list *l, char *name, int *organFlags, char **recNames){
    if(emptyList(*l) == 1)
        return 0;

    list aux = *l;
    list comp = (list) malloc(sizeof(struct node));
    int i;

    strcpy(comp->name, name);
    for(i = 0; i < 5; i++){
        strcpy(comp->recNames[i], *(recNames + i));
        comp->organFlag[i] = *(organFlags + i);
    }


    if(evenNode(aux, comp) == 1){
        if(aux == aux->next){
            *l = NULL;
        }
        else
            *l = aux->next;

        free(aux);
    }

    else{
        while(aux->next != NULL && evenNode(aux->next, comp) == 0)
            aux = aux->next;
        
        if(aux->next == NULL)
            return 0;
        
        list aux2 = aux->next;
        aux->next = aux2->next;
        free(aux2);
    }

    return 1;
}

int removeFst(list *l, char **name, char ***recNames, int **organFlag){
    if(emptyList(*l) == 1)
        return 0;

    list aux = (*l)->next;
    strcpy(*name, aux->name);
    int i;
    for(i = 0; i < 5; i++){
        strcpy(**(recNames + i), aux->recNames[i]);
        **(organFlag + i) = aux->organFlag[i];
    }

    if(aux == aux->next){
        *l = NULL;
    }
    else{
        (*l)->next = aux->next;
    }
    free(aux);
    return 1;    
}

int getDatabyPos(list l, int pos, char **name, char ***recNames, int **organFlag){
    if(emptyList(l) == 1)
        return 0;

    int size = 0;
    list aux = l;
    do{
        aux = aux->next;
        size++;
    }while(aux != l);

    if(pos > size)
        return 0;

    while(pos > 1){
        aux = aux->next;
        pos--;
    }

    int i;

    strcpy(*name, aux->name);
    for(i = 0; i < 5; i++){
        strcpy(*(*recNames + i), aux->recNames[i]);
        *(*organFlag + i) = aux->organFlag[i];
    }

    return 1;
}