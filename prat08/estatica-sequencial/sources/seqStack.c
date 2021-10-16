#include <stdlib.h>
#include "..\headers\seqStack.h"

#define MAX 20

struct stack{
    int data[MAX];
    int top;
};

Stack newStack(){
    Stack new = (Stack) malloc(sizeof(struct stack));
    
    if(new != NULL)
        new->top = -1;

    return new;
}

int emptyStack(Stack stk){
    if(stk->top == -1)
        return 1;
    return 0;
}

int fullStack(Stack stk){
    if(stk->top == MAX -1)
        return 1;
    return 0;
}

int push(Stack stk, int input){
    if(stk == NULL || fullStack(stk) == 1)
        return 0;

    stk->top++;
    stk->data[stk->top] = input;

    return 1;
}

int pop(Stack stk, int *output){
    if(stk == NULL || emptyStack(stk) == 1)
        return 0;

    *output = stk->data[stk->top];
    stk->top--;

    return 1;
}

int getTop(Stack stk, int *output){
    if(stk == NULL || emptyStack(stk) == 1)
        return 0;

    *output = stk->data[stk->top];

    return 1;
}