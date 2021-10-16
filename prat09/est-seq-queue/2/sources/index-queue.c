#include <stdlib.h>
#include <string.h>
#include "..\headers\index-queue.h"

#define MAX 20

struct queue{
    char data[MAX][11];
    int start, index;
};

Queue newQ(){
    Queue q = (Queue) malloc(sizeof(struct queue));
    if(q != NULL){
        q->index = 0;
        q->start = 0;
    }

    return q;
}

int emptyQ(Queue q){
    if(q->index == 0)
        return 1;
    return 0;
}

int fullQ(Queue q){
    if(q->index == MAX) 
        return 1;
    return 0;
}

int insertEnd(Queue q, char *input){
    if(fullQ(q) == 1)
        return 0;
    
    strcpy(q->data[(q->start + q->index)%MAX], input);
    q->index++;
    return 1;
}

int removeStart(Queue q, char **output){
    if(emptyQ(q) == 1)
        return 0;

    strcpy(*output, q->data[q->start]);
    q->start = (q->start + 1)%MAX;
    q->index--;
    return 1;
}