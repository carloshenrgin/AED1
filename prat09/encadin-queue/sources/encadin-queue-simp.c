#include <stdlib.h>
#include <string.h>
#include "..\headers\encadin-queue-simp.h"

struct bev{
    char name[11];
    int vol;
    float price;
};

struct node{
    struct bev data;
    struct node *next;
};

struct queue{
    struct node *start;
    struct node *end;
};

Queue newQ(){
    Queue q = (Queue) malloc(sizeof(struct queue));
    if(q != NULL){
        q->start = NULL;
        q->end = NULL;
    }

    return q;
}

int emptyQ(Queue q){
    if(q->start == NULL)
        return 1;
    return 0;
}

int insertEnd(Queue q, char *name, int vol, float price){
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    if(newNode == NULL)
        return 0;

    newNode->data.price = price;
    newNode->data.vol = vol;
    strcpy(newNode->data.name, name);
    newNode->next = NULL;

    if(emptyQ(q) == 1){
        q->start = newNode;
    }
    else (q->end)->next = newNode;

    q->end = newNode;
    return 1;
}

int removeStart(Queue q, char **name, int *vol, float *price){
    if(emptyQ(q) == 1)
        return 0;

    *vol = q->start->data.vol;
    *price = q->start->data.price;
    strcpy(*name, q->start->data.name);

    struct node* aux = q->start;

    if(q->start == q->end)
        q->end = NULL;
    

    q->start = aux->next;
    free(aux);

    return 1;
}

int backToEmpty(Queue q){
    if(emptyQ(q) == 1)
        return 0;

    struct node *aux = q->start;

    while(aux != NULL){
        struct node *aux2 = aux;
        aux = aux->next;
        free(aux2);
    }

    q->end = NULL;
    q->start = NULL;

    return 1;
}


int eraseQ(Queue *q){
    if(emptyQ(*q) == 1)
        return 0;

    backToEmpty(*q);

    free(q);
    return 1;
}
