#include <stdlib.h>
#include "..\headers\stack-encadin.h"

struct nodeStack{
    int data;
    struct nodeStack* next;
};

Stack newStack(){
    return NULL;
}

int emptyStack(Stack stk){
    if(stk == NULL)
        return 1;
    return 0;
}

int push(Stack *stk, int input){
    Stack newNode = (Stack) malloc(sizeof(struct nodeStack));
    if(newNode == NULL)
        return 0;

    newNode->data = input;
    newNode->next = *stk;
    *stk = newNode;

    return 1;
}

int pop(Stack *stk, int *output){
    if(emptyStack(*stk) == 1)
        return 0;

    *output = (*stk)->data;

    Stack aux = *stk;
    *stk = aux->next;
    free(aux);

    return 1;
}

int getTop(Stack stk, int *output){
    if(emptyStack(stk) == 1)
        return 0;

    *output =  stk->data;

    return 1;
}