#include <stdlib.h>
#include <string.h>
#include "..\headers\waste-queue.h"

#define MAX 20

struct queue{
    char data[MAX][11];
    int start, end;
};

Queue newQ(){
    Queue q = (Queue) malloc(sizeof(struct queue));
    if(q != NULL){
        q->end = 0;
        q->start = 0;
    }

    return q;
}

int emptyQ(Queue q){
    if(q->start == q->end)
        return 1;
    return 0;
}

int fullQ(Queue q){
    if(q->start == (q->end + 1)%MAX) 
        return 1;
    // Como tem o disperdicio de uma pos, o fim sempre fica uma posição atrás do começo quando tá cheia. Então se o resto da divisão desse fim + 1 por MAX for igual o início, então tá cheia
    return 0;
}

int insertEnd(Queue q, char *input){
    if(fullQ(q) == 1)
        return 0;
    
    strcpy(q->data[q->end], input);
    q->end = (q->end + 1)%MAX;
    return 1;
}

int removeStart(Queue q, char **output){
    if(emptyQ(q) == 1)
        return 0;

    strcpy(*output, q->data[q->start]);
    q->start = (q->start + 1)%MAX;
    return 1;
}