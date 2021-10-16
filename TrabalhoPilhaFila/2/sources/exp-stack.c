#include <stdlib.h>
#include <math.h>
#include "..\headers\exp-stack.h"


struct nodeStack{
    char data;
    struct nodeStack *next;
};


Stack initStk(){
    return NULL;
}

int emptyStk(Stack stk){
    if(stk == NULL)
        return 1;
    return 0;
}

int push(Stack *stk, char data){
    Stack newNode = (Stack) malloc(sizeof(struct nodeStack));
    if(newNode == NULL)
        return 0;
    
    newNode->data = data;
    newNode->next = *stk;
    *stk = newNode;

    return 1;
}

int pop(Stack *stk, char *data){
    if(emptyStk(*stk) == 1)
        return 0;

    Stack aux = *stk;
    *data = aux->data;
    *stk = aux->next;
    free(aux);
    
    return 1;
}

int getTop(Stack stk, char *data){
    if(emptyStk(stk) == 1)
        return 0;

    *data = stk->data;

    return 1;
}

int back2Empty(Stack *stk){
    if(emptyStk(*stk) == 1)
        return 0;

    while(*stk != NULL){
        Stack aux = *stk;
        *stk = (*stk)->next;
        free(aux);
    }

    *stk = initStk();

    return 1;
}

/* Tabela de retornos
   ret 0 -> Pilha Vazia
   ret 1 -> Expressão não respeita ordem de fechamento
   ret 2 -> Expressão não respeita ordem de precedencia de escopo
   ret 3 -> Delimitador de escopo correspondente nao encontrado
   ret 4 -> Delimitador de escopo fechado sem ser aberto
   ret 5 -> Sucesso */




int valScope(Stack *stk){
    if(emptyStk(*stk) == 1)
        return 0;

    Stack aux2 = initStk(), delScope = initStk(); // Pilha auxiliar para percorrer a stk e delScope para guardar delimitadores de escopo
    char scope, verif;
    int flagClosure = 0, flagRep;
    int returnCode = 0; // Necessario porque quando eu dou pop na lista de expressao eu altero ela mesmo por valor
    // Como isso acontece, eu preciso reinserir esses elementos antes de retornar meu erro
    // Então ao achar o erro eu guardo ele nessa variavel, quebro o laço, reinsiro tudo que eu retirei da pilha
    // Se eu achei o erro o valor do código é dif de 0 e eu retorno ele
    // Senao eu verifico se a lista de escopos ta vazia, ou seja, eu consegui validar os escopos e retorno sucesso
    // Senao, so falta um erro, que foi abrir algum escopo sem fechar

    do{
        flagRep = pop(&(*stk), &scope);
        if(flagRep == 1){
            push(&aux2, scope);

            if(scope == ')'){
                int output = getTop(delScope, &verif);
                if(output == 0 || verif == ']'){
                    // A unica forma de output ser 0 é a pilha de escopos estar vazia
                    // Isso evita uma nova execução da função de emptyStk
                    // Eu só posso colocar um '(' na pilha se ele for antecedido por abre colchete ou nada antes
                    // Isso para se obedecer a ordem de precedência
                    output = push(&delScope, scope);
                    if(output == 0){
                        returnCode = -1; // Erro de execução do programa por falta de memória. Mudar o numero dps
                        break;
                    }
                    flagClosure = 0;
                }
                else{
                    returnCode = 2; // Se eu tenho um parêntese que é precedido por um abre chaves eu desobedeci ordem de prec. Invalida
                    break;
                }
            }

            else if(scope == ']'){
                int output = getTop(delScope, &verif);
                if(output == 0 || verif == '}'){
                    // Mesmo sentido. Só posso abrir colchete depois de uma chave ou se n houver escopo aberto
                    output = push(&delScope, scope);
                    if(output == 0){
                        returnCode = -1; // Erro de execução do programa por falta de memória. Mudar o numero dps
                        break;
                    }
                    flagClosure = 0;
                }
                else{
                    returnCode = 2; // Invalida por ordem de prec.
                    break;
                }
            }

            else if(scope == '}'){
                if(emptyStk(delScope) == 1){
                    // Nao posso abrir chaves a nao ser que nao tenha nenhum escopo aberto
                    // Então a pilha de escopos deve estar vazia
                    int output = push(&delScope, scope);
                    if(output == 0){
                        returnCode = -1; // Erro de execução do programa por falta de memória. Mudar o numero dps
                        break;
                    }
                    flagClosure = 0;
                }
                else{
                    returnCode = 2; // Invalida por ordem de prec.
                    break;
                }
            }

            if(scope == '('){
                int output = getTop(delScope, &verif);
                if(output != 0 && verif == ')'){
                    // Se a lista não estiver vazia e o que estiver no início for um abre parêntese
                    // eu posso executar esse trecho para estourar o '(' para fora da lista
                    pop(&delScope, &verif);

                    flagClosure = 1; // Indica que eu acabei de fechar um parentese
                }
                else if(output == 0){
                    returnCode = 3; // Invalido por tentar "abrir" um escopo que nao foi "fechado"
                    break;
                }
                else{
                    returnCode = 1; // Lista invalida por ordem de fechamento
                    break;
                }
            }

            else if(scope == '['){
                // Só posso fechar colchete se eu fechei parêntese antes, ou eu estaria desrespeitando ordem de prec.
                // Se eu fechei parêntese logo antes, flagClosure deve ser 1. Verifico isso abaixo
                if(flagClosure == 1){
                    int output = getTop(delScope, &verif);
                    if(output != 0 && verif == ']'){
                        // Se a lista nao estiver vazia e o que estiver no inicio for um '['
                        // eu posso executar esse trecho de codigo para estourar o ']' para fora da lista
                        pop(&delScope, &verif);
                            
                        flagClosure = 2; // Indica que eu fechei clochetes
                    }
                    else if(output == 0){
                        returnCode = 3;
                        break;
                    }
                    else{
                        returnCode = 1; // Lista invalida por ordem de fechamento
                        break;
                    }
                }
                else{
                    returnCode = 2; // Se eu estou tentando fechar colchete sem ter fechado parentese antes eu desrespeito prec.
                    break;
                }
            }

            else if(scope == '{'){
                // Só posso fechar chaves se eu fechei um colchete antes. Garante que n haja erros de prec.
                // Se eu fechei colchete logo antes, flagClosure deve ser 2. Verifico isso abaixo
                if(flagClosure == 2){
                    int output = getTop(delScope, &verif);
                    if(output != 0 && verif == '}'){
                        // Se a lista nao estiver vazia e o que estiver no inicio for um '{'
                        // eu posso executar esse trecho de codigo para estourar o '}' para fora da lista
                        pop(&delScope, &verif);

                        flagClosure = 0; // Resetando a flag pra nao causar erros
                    }
                    else if(output == 0){
                        returnCode = 3;
                        break;
                    }
                    else{
                        returnCode = 1;
                        break;
                    }
                }
                else if(flagClosure == 1){
                    returnCode = 1;
                    break;
                }
                else{
                    returnCode = 2;
                    break;
                }
            }

        }


    }while(flagRep == 1);

    do{
        flagRep = pop(&aux2, &scope);
        if(flagRep == 1)
            flagRep = push(&(*stk), scope);
    }while(flagRep == 1);

    if(returnCode != 0) // Achei algum erro no meio do caminho
        return returnCode; // Retorno esse erro

    
    if(emptyStk(delScope) == 1)
        return 5; // Lista valida

    return 4; // Existe algum escopo aberto que nao foi fechado durante a execução.
    // Infelizmente esse erro especifico só retorna se for um parentese solitario, ou se eu abrir um colchete
    // tiver aberto e fechado parenteses e nao fechado um colchete
    // ou se eu abrir uma chave, tiver aberto e fechado parenteses e colchete e nao fechar a chave
    // Se eu colocar uma chave ou um colchete abrindo solitario, como o meu codigo garante a ordem de precedencia
    // atraves da verificação da abertura de delimitador de escopo, o erro de ordem de precedencia é retornado por
    // ter mais prioridade que esse (por estar dentro do laço)        
}

int checkIfLiteral(char data){
    return (data >= 'A' && data <= 'J');
}

int checkIfOperator(char data){
    return (data == '+' || data == '-' || data == '*' || data == '/' || data == '^');
}


int precedence(char data){
    if(data == '+' || data == '-')
        return 1;
    else if(data == '*' || data == '/')
        return 2;
    else if(data == '^')
        return 3;
    return 0;
}

int infix2Postfix(Stack *infix, Stack *postfix){
    if(emptyStk(*infix) == 1 || emptyStk(*postfix) == 0)
        return 0;

    Stack aux = initStk(), temp = initStk();
    push(&temp, '(');
    while(emptyStk(*infix) == 0){
        char expMember;
        pop(&(*infix), &expMember);
        int out = push(&aux, expMember);
        if(out == 0)
            return -1; // Faltou memoria na hora de inserir na auxiliar
    }

    while(emptyStk(aux) == 0){
        char infixOutput;
        pop(&aux, &infixOutput);
        int out = push(&(*infix), infixOutput);
        if(out == 0)
            return -1; // Falta de memoria
        
        if(infixOutput == '(' || infixOutput == '[' || infixOutput == '{'){
            out = push(&temp, infixOutput);
            if(out == 0)
                return -1;
        }

        else if(checkIfLiteral(infixOutput) == 1){
            out = push(&(*postfix), infixOutput);
            if(out == 0)
                return -1;
        }

        else if(infixOutput == ')' || infixOutput == ']' || infixOutput == '}'){
            char tempOutput;
            do{
                pop(&temp, &tempOutput);
                if(checkIfOperator(tempOutput) == 1){
                    out = push(&(*postfix), tempOutput);
                    if(out == 0)
                        return -1;
                }

            }while(tempOutput !=  '(' && tempOutput != '[' && tempOutput != '{' && emptyStk(temp) == 0);
        }

        else if(checkIfOperator(infixOutput) == 1){
            char tempOutput;
            if(emptyStk(temp) == 1){
                out = push(&temp, '(');
                if(out == 0)
                    return -1;
            }
            getTop(temp, &tempOutput);

            if(precedence(infixOutput) <= precedence(tempOutput)){
                do{
                    if(checkIfOperator(tempOutput) == 1){
                        pop(&temp, &tempOutput);
                        out = push(&(*postfix), tempOutput);
                        if(out == 0)
                            return -1;

                    }
                    getTop(temp, &tempOutput);
                }while(emptyStk(temp) == 0 && checkIfOperator(tempOutput) == 1);

                out = push(&temp, infixOutput);
                if(out == 0)
                    return -1;

            }
            else{
                out = push(&temp, infixOutput);
                if(out == 0)
                    return -1;
            }
        }

    }

    while(emptyStk(temp) == 0){
        
        char tempOutput;
        pop(&temp, &tempOutput);
        if(checkIfOperator(tempOutput) == 1){
            int out = push(&(*postfix), tempOutput);
            if(out == 0)
                return -1;
        }
    }

    return 1;
}

int valOpOperand(Stack *stk){
    if(emptyStk(*stk) == 1)
        return 0;

    Stack aux = initStk();

    //Invertendo e guardando numa aux pra me facilitar a fazer as verificações
    while(emptyStk(*stk) == 0){
        char stackOutput;
        pop(&(*stk), &stackOutput);
        int output = push(&aux, stackOutput);
        if(output == 0)
            return 101;
    }

    int returnCode = 0;

    while(emptyStk(aux) == 0){
        char auxOutput;
        pop(&aux, &auxOutput);

        //Primeiro elemento da expressão é um operador. Se sim, operandos demais
        // Ou se ultimo elemento da expressão é um operador. Se sim, operandos demais
        if((emptyStk(*stk) == 1 && checkIfOperator(auxOutput) == 1) || (emptyStk(aux) == 1 && checkIfOperator(auxOutput) == 1)){
            int output = push(&(*stk), auxOutput);
            if(output == 0)
                return 101;
            returnCode = -1;
            break;
        }

        if(emptyStk(*stk) == 0){
            char stackTop;
            getTop(*stk, &stackTop);
            if(checkIfOperator(auxOutput) == 1 && checkIfOperator(stackTop) == 1){
                int output = push(&(*stk), auxOutput);
                if(output == 0)
                    return 101;
                returnCode = -1;
                break;
            }
            else if(checkIfLiteral(auxOutput) == 1 && checkIfLiteral(stackTop) == 1){
                int output = push(&(*stk), auxOutput);
                if(output == 0)
                    return 101;
                returnCode = -2;
                break;
            }
            else if(checkIfOperator(stackTop) == 1 && (auxOutput == ')' || auxOutput == ']' || auxOutput == '}')){
                int output = push(&(*stk), auxOutput);
                if(output == 0)
                    return 101;
                returnCode = -1;
                break;
            }
            else if((stackTop == '(' || stackTop == '[' || stackTop == '{') && checkIfOperator(auxOutput) == 1){
                int output = push(&(*stk), auxOutput);
                if(output == 0)
                    return 101;
                returnCode = -1;
                break;
            }

        }

        int output = push(&(*stk), auxOutput);
        if(output == 0)
            return 101;
    }

    if(returnCode != 0){
        while(emptyStk(aux) == 0){
            char auxOutput;
            pop(&aux, &auxOutput);
            int output = push(&(*stk), auxOutput);
            if(output == 0)
                return 101;
        }

        return returnCode;
    }

    return 1;    
}

struct calcStack{
    float data;
    int type;
    struct calcStack *next;
};

struct calcStack* initCalc(){
    return NULL;
}

int emptyCalcStk(struct calcStack* calc){
    if(calc == NULL)
        return 1;
    return 0;
}

int pushCalc(struct calcStack** calc, float data, int type){
    struct calcStack* newNode = (struct calcStack*) malloc(sizeof(struct calcStack));
    if(newNode == NULL)
        return 0;
    
    newNode->type = type;
    newNode->data = data;
    newNode->next = *calc;
    *calc = newNode;

    return 1;
}

int popCalc(struct calcStack** calc, float *data, int *type){
    if(emptyCalcStk(*calc) == 1)
        return 0;

    struct calcStack* aux = *calc;
    *data = aux->data;
    *type = aux->type;
    *calc = aux->next;
    free(aux);

    return 1;
}

int getTopCalc(struct calcStack** calc, float *data, int *type){
    if(emptyCalcStk(*calc) == 1)
        return 0;

    *data = (*calc)->data;
    *type = (*calc)->type;

    return 1;
}

int calcExpression(Stack *stk, float *output, float *values){
    int returnCode = valOpOperand(&(*stk));
    if(returnCode != 1)
        return returnCode;
    
    Stack postfix = initStk();
    returnCode = infix2Postfix(&(*stk), &postfix);
    if(returnCode != 1)
        return 101; // Faltou memoria ou uma pre-condição n foi atendida

    struct calcStack* calc = initCalc();
    while(emptyStk(postfix) == 0){
        char postOutput;
        pop(&postfix, &postOutput);

        if(checkIfLiteral(postOutput) == 1){
            if(postOutput == 'A')
                returnCode = pushCalc(&calc, *(values), 0);
            else if(postOutput == 'B')
                returnCode = pushCalc(&calc, *(values + 1), 0);
            else if(postOutput == 'C')
                returnCode = pushCalc(&calc, *(values + 2), 0);
            else if(postOutput == 'D')
                returnCode = pushCalc(&calc, *(values + 3), 0);
            else if(postOutput == 'E')
                returnCode = pushCalc(&calc, *(values + 4), 0);
            else if(postOutput == 'F')
                returnCode = pushCalc(&calc, *(values + 5), 0);
            else if(postOutput == 'G')
                returnCode = pushCalc(&calc, *(values + 6), 0);
            else if(postOutput == 'H')
                returnCode = pushCalc(&calc, *(values + 7), 0);
            else if(postOutput == 'I')
                returnCode = pushCalc(&calc, *(values + 8), 0);
            else if(postOutput == 'J')
                returnCode = pushCalc(&calc, *(values + 9), 0);
                   
        }

        /* Tipo 0: Literal
           Tipo 1: +
           Tipo 2: -
           Tipo 3: *
           Tipo 4: /
           Tipo 5: ^ */

        else if(checkIfOperator(postOutput) == 1){
            if(postOutput == '+')
                returnCode = pushCalc(&calc, 0, 1);
            else if(postOutput == '-')
                returnCode = pushCalc(&calc, 0, 2);
            else if(postOutput == '*')
                returnCode = pushCalc(&calc, 0, 3);
            else if(postOutput == '/')
                returnCode = pushCalc(&calc, 0, 4);
            else if(postOutput == '^')
                returnCode = pushCalc(&calc, 0, 5);            
        }
        
        if(returnCode == 0)
                return 101; // Faltou memoria

    }

    struct calcStack* auxCalc = initCalc();

    while(emptyCalcStk(calc) == 0){
        float valueOut;
        int typeOut;

        do{
            popCalc(&calc, &valueOut, &typeOut);
            if(typeOut == 0){
                returnCode = pushCalc(&auxCalc, valueOut, 0);
                if(returnCode == 0)
                    return 101;
            }
        }while(typeOut == 0);

        if(typeOut > 0){
            int unuseful;
            float x, y, z;
            popCalc(&auxCalc, &x, &unuseful);
            popCalc(&auxCalc, &y, &unuseful);
            if(typeOut == 1)
                z = y + x;
            else if(typeOut == 2)
                z = y - x;
            else if(typeOut == 3)
                z = y*x;
            else if(typeOut == 4)
                z = y/x;
            else if(typeOut == 5)
                z = pow(y, x);

            returnCode = pushCalc(&auxCalc, z, 0);
            if(returnCode == 0)
                return 101;
        }
    
    }

    int unuseful;
    popCalc(&auxCalc, &(*output), &unuseful);

    return 1;    
}