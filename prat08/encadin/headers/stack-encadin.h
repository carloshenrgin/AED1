typedef struct nodeStack* Stack;

Stack newStack();
int emptyStack(Stack stk);
int push(Stack *stk, int input);
int pop(Stack *stk, int *output);
int getTop(Stack stk, int *output);