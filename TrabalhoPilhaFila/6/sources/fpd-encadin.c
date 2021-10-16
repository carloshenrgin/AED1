#include <stdlib.h>
#include <string.h>
#include "..\headers\fpd-encadin.h"

struct node{
    int age, severity;
    char name[20], organ[10];
    struct node* next;
};

pQueue initQueue(){
    return NULL;
}

int emptyQueue(pQueue q){
    if(q == NULL)
        return 1;
    return 0;
}

int insertSort(pQueue *q, int severity, int age, char *name, char *organ){
    pQueue newNode = (pQueue) malloc(sizeof(struct node));
    if(newNode == NULL)
        return 0;

    pQueue aux = *q;
    
    newNode->age = age;
    newNode->severity = severity;
    strcpy(newNode->name, name);
    strcpy(newNode->organ, organ);

    if(emptyQueue(*q) == 1){
        newNode->next = newNode;
        *q = newNode;
    }

    else if(newNode->severity <= aux->severity){
        newNode->next = aux->next;
        aux->next = newNode;
        *q = newNode;
        return 1;
    }

    else{ // Menor ou igual porque quem chegou primeiro e tem o mesmo grau de gravidade tem prioridade
        while(aux->next != *q && aux->next->severity >= newNode->severity){
            aux = aux->next;
        }

        newNode->next = aux->next;
        aux->next = newNode;
    }

    return 1;
}

int removeBeg(pQueue *q, int *severity, int *age, char **name, char **organ){
    if(emptyQueue(*q) == 1)
        return 0;

    pQueue aux = (*q)->next;

    strcpy(*name, aux->name);
    strcpy(*organ, aux->organ);
    *age = aux->age;
    *severity = aux->severity;

    if(*q == aux){
        *q = NULL;
        free(aux);
        return 1;
    }


    (*q)->next = aux->next;
    free(aux);

    return 1;
}

int back2Empty(pQueue *q){
    if(emptyQueue(*q) == 1)
        return 0;

    pQueue aux = (*q)->next; // aux olha para o inicio da fila
    (*q)->next = NULL; // O final é desconectado da fila e aponta para NULL
    while(aux != NULL){
        pQueue aux2 = aux;
        aux = aux->next;
        free(aux2);
    }

    return 1;
}

int peek(pQueue q, int *severity, int *age, char **name, char **organ){
    if(emptyQueue(q) == 1)
        return 0;

    strcpy(*name, q->name);
    strcpy(*organ, q->organ);
    *age = q->age;
    *severity = q->severity;

    return 1;
}
