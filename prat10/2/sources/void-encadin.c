#include <stdlib.h>
#include "..\headers\void-encadin.h"

struct node{
    int type;
    void *data;
    struct node *next;
};

list createList(){
    return NULL;
}

int emptyList(list l){
    if(l == NULL)
        return 1;
    return 0;
}

int insertGrade(list *l, void *input, int type){
    list newNode = (list) malloc(sizeof(struct node));
    if(newNode == NULL)
        return 0;

    newNode->type = type;
    if(type == 1){
        newNode->data = (char *) malloc(sizeof(char));
        *(char*) newNode->data = *(char *) input;
    }
    else{
        newNode->data = (float *) malloc(sizeof(float));
        *(float *) newNode->data = *(float *) input;
    }
    
    newNode->next = *l;
    *l = newNode;
    
    return 1;
}

int equalGrade(void *data1, void *data2, int type1, int type2){
    if(type1 != type2)
        return 0;
    if((type1 == 1 && *(char*) data1 == *(char*) data2) || (type2 == 2 && *(float *) data1 == *(float *) data2))
        return 1;
    return 0;
}


int removeGrade(list *l, void *input, int type){
    if(emptyList(*l) == 1)
        return 0;

    list aux = *l;
    if(equalGrade(input, (*l)->data, type, (*l)->type) == 1){
        *l = (*l)->next;
        free(aux);
        return 1;
    }

    while(aux->next != NULL && equalGrade(input, aux->next->data, type, aux->next->type) == 0){
        aux = aux->next;
    }
    if(aux->next == NULL)
        return 0;

    list aux2 = aux->next;
    aux->next = aux2->next;
    free(aux2);

    return 1;
}

int getGradebyPos(list l, void **output, int *type, int pos){
    if(emptyList(l))
        return 0;

    list aux = l;
    while(pos > 1){
        aux = aux->next;
        if(aux == NULL)
            return 0;
        pos--;
    }

    if(aux->type == 1){
        *output = (char *) malloc(sizeof(char));
        *(char *) *output = *(char *) aux->data;
    }
    else{
        *output = (float *) malloc(sizeof(float));
        *(float *) *output = *(float *) aux->data;
    }

    *type = aux->type;
    
    return 1;
}