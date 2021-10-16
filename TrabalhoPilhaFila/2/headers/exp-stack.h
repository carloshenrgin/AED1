typedef struct nodeStack* Stack;

Stack initStk();
int emptyStk(Stack stk);
int push(Stack *stk, char data);
int pop(Stack *stk, char *data);
int getTop(Stack stk, char *data);
int back2Empty(Stack *stk);
int valScope(Stack *stk);
int checkIfLiteral(char data);
int checkIfOperator(char data);
int precedence(char data);
int infix2Postfix(Stack *infix, Stack *postfix);
int valOpOperand(Stack *stk);
int calcExpression(Stack *stk, float *output, float *values);