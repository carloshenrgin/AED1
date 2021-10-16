#include <stdio.h>
#include "..\headers\exp-stack.h"

int main(){
    Stack lit, postFix, aux;
    int operador, retorno, flagIn = 0, flagPost = 0, i;
    char inOut;
    float values[10], output;

    printf("----------------Tabela----------------\n");
    printf("[_1].................Inicializar Pilha\n");
    printf("[_2]........Inserir no Inicio da Pilha\n");
    printf("[_3]........Remover do Inicio da Pilha\n");
    printf("[_4].................Ver Topo da Pilha\n");
    printf("[_5]................Imprimir Expressao\n");
    printf("[_6]....................Esvaziar Pilha\n");
    printf("[_7]...............Validacao de Escopo\n");
    printf("[_8]...Converter Expressao p/ Pos-Fixa\n");
    printf("[_9]...Avaliar Expressao e Dar Valores\n");
    printf("[10].................Encerrar Operacao\n");

    do{
        do{
            printf("\nInput de operacao: ");
            scanf("%d", &operador);
        }while(operador < 1 && operador > 10);

        switch(operador){
            case 1:
                if(flagIn == 1){
                    printf("Pilha ja inicializada\nRequisicao Cancelada\n");
                    break;
                }

                lit = initStk();
                printf("Pilha Inicializada\n");
                flagIn = 1;
            break;

            case 2:
                if(flagIn == 0){
                    printf("Pilha ainda nao inicializada\nRequisicao Cancelada\n");
                    break;
                }

                printf("Digite o caractere a ser inserido na pilha da expressao\n");
                printf("OBS Os caracteres validos sao: +, -, *, /, ^, {, }, [, ], (, ), letras maiusculas de A a J\n");
                printf("Caso algum caractere invalido seja digitado, o programa aguardara ate que se digite um valido\n");
                printf("Input: ");
                setbuf(stdin, NULL);

                do{
                    scanf("%c", &inOut);
                }while(checkIfLiteral(inOut) != 1 && checkIfOperator(inOut) != 1 && inOut != '(' && inOut != ')' && inOut != '[' && inOut != ']' && inOut != '{' && inOut != '}');

                retorno = push(&lit, inOut);
                if(retorno == 0)
                    printf("Falha ao alocar novo no\nInsercao Falhou\n");
                else
                    printf("Sucesso ao inserir\n");
            break;
            
            case 3:
                if(flagIn == 0){
                    printf("Pilha ainda nao inicializada\nRequisicao Cancelada\n");
                    break;
                }

                retorno = pop(&lit, &inOut);
                if(retorno == 0)
                    printf("Pilha vazia\nFalha ao remover primeiro caractere\n");
                else
                    printf("O caractere %c foi removido do topo da pilha\n", inOut);
            break;

            case 4:
                if(flagIn == 0){
                    printf("Pilha ainda nao inicializada\nRequisicao Cancelada\n");
                    break;
                }
                printf("   Digite a pilha a ter o topo verificado:");
                printf("   Obs: Caso seja digitada uma opcao invalida ou a opcao 2 seja digitada antes da pilha pos-fixa ser criada, o programa continuara tentando ler ate obter um numero valido\n");
                printf("   [1] Pilha Com Expressao Em Forma Infixa\n");
                printf("   [2] Pilha Com Expressao Em Forma Pos-Fixa\n");
                do{
                    printf("\n   Input: ");
                    scanf("%d", &operador);
                    
                }while(operador != 1 && (operador != 2  || flagPost == 0));

                if(operador == 1)
                    retorno = getTop(lit, &inOut);
                else retorno = getTop(postFix, &inOut);

                if(retorno == 0)
                    printf("Pilha vazia\nFalha ao pegar elemento no topo\n");
                else
                    printf("O caractere %c esta no topo da pilha\n", inOut);
            break;

            case 5:
                if(flagIn == 0 || emptyStk(lit) == 1){
                    printf("Pilha vazia ou ainda nao inicializada\nRequisicao Cancelada\n");
                    break;
                }

                printf("   Digite a pilha a ser impressa:");
                printf("   Obs: Caso seja digitada uma opcao invalida ou a opcao 2 seja digitada antes da pilha pos-fixa ser criada, o programa continuara tentando ler ate obter um numero valido\n");
                printf("   [1] Pilha Com Expressao Em Forma Infixa\n");
                printf("   [2] Pilha Com Expressao Em Forma Pos-Fixa\n");
                do{
                    printf("\n   Input: ");
                    scanf("%d", &operador);
                    
                }while(operador != 1 && (operador != 2  || flagPost == 0));

                aux = initStk();
                if(operador == 1){
                    do{
                        retorno = pop(&lit, &inOut);
                        if(retorno == 1)
                            retorno = push(&aux, inOut);
                    }while(retorno == 1);

                    do{
                        retorno = pop(&aux, &inOut);
                        if(retorno == 1){
                            printf("%c", inOut);
                            retorno = push(&lit, inOut);
                        }
                    }while(retorno == 1);
                }
                else{
                    do{
                        retorno = pop(&postFix, &inOut);
                        if(retorno == 1)
                            retorno = push(&aux, inOut);
                    }while(retorno == 1);

                    do{
                        retorno = pop(&aux, &inOut);
                        if(retorno == 1){
                            printf("%c", inOut);
                            retorno = push(&postFix, inOut);
                        }
                    }while(retorno == 1);
                }

                printf("\n");

            break;

            case 6:
                if(flagIn == 0){
                    printf("Pilha ainda nao inicializada\nRequisicao Cancelada\n");
                    break;
                }

                printf("Retornando Pilhas ao Estado Vazio\n");
                retorno = back2Empty(&lit);
                if(flagPost == 1)
                    retorno = back2Empty(&postFix);

                if(retorno == 0 || lit != NULL)
                    printf("Pilha vazia ou falha ao esvaziar\n");
                else
                    printf("Sucesso ao retornar a pilha para o estado vazio\n");
            break;

            case 7:
                if(flagIn == 0){
                    printf("Pilha ainda nao inicializada\nRequisicao Cancelada\n");
                    break;
                }

                printf("Realizando validacao de escopo\n");
                retorno = valScope(&lit);

                if(retorno == 0)
                    printf("Pilha vazia\nImpossivel Validar Escopo de Expressao");
                else if(retorno == 1)
                    printf("Escopo da Expressao Invalido -> Ordem de Fechamento Nao Respeitada\n");
                else if(retorno == 2)
                    printf("Escopo da Expressao Invalido -> Ordem de Precedencia Nao Respeitada\n");
                else if(retorno == 3)
                    printf("Escopo da Expressao Invalido -> Escopo Aberto E Nao Fechado\n");
                else if(retorno == 4)
                    printf("Escopo da Expressao Invalido -> Escopo Fechado Sem Ser Aberto\n");
                else if(retorno == 5)
                    printf("Escopo da Expressao Valido\n");
                else
                    printf("Erro de execucao por falta de memoria\n");
            break;

            case 8:
                if(flagIn == 0){
                    printf("Pilha ainda nao inicializada\nRequisicao Cancelada\n");
                    break;
                }
                if(flagPost == 1){
                    back2Empty(&postFix);
                }

                postFix = initStk();
                flagPost = 1;

                printf("Passando a expressao para a forma pos-fixa\n");
                retorno = infix2Postfix(&lit, &postFix);
                if(retorno == 0)
                    printf("Pilha de Expressao Infixa Vazia ou Pilha de Expressao Pos-Fixa Preenchida\nRequisicao Cancelada\n");
                else if(retorno == -1)
                    printf("Memoria insuficiente durante execucao\nOs dados da Pilha de Expressao Infixa e de Expressao Pos-Fixa podem ter sido corrompidos\n");
                else{
                    printf("Expressao pos-fixa: ");
                    aux = initStk();
                    do{
                        retorno = pop(&postFix, &inOut);
                        if(retorno == 1)
                            retorno = push(&aux, inOut);
                    }while(retorno == 1);

                    do{
                        retorno = pop(&aux, &inOut);
                        if(retorno == 1){
                            printf("%c", inOut);
                            retorno = push(&postFix, inOut);
                        }
                    }while(retorno == 1);

                    printf("\n");
                }

            break;

            case 9:
                if(flagIn == 0){
                    printf("Pilha ainda nao inicializada\nRequisicao Cancelada\n");
                    break;
                }

                printf("OBS: Deve-se atribuir valores a todos os literais. Valores nao utilizados podem ser inicializados com 0 para facilitar\n");
                for(i = 0; i < 10; i++){
                    printf("Digite o valor de %c: ", 65+i);
                    scanf("%f", &values[i]);
                }

                retorno = calcExpression(&lit, &output, values);
                
                if(retorno == 0)
                    printf("Pilha Vazia\n");
                if(retorno == -1)
                    printf("Numero de operadores nao adequado\n");
                if(retorno == -2)
                    printf("Numero de operandos nao adequado\n");
                else if(retorno == 101)
                    printf("Memoria insuficiente durante execucao\nOs dados da Pilha de Expressao Infixa e de Expressao Pos-Fixa podem ter sido corrompidos\n");
                else
                    printf("O valor da expressao eh: %.5f\n", output);
            break;
        }



    }while(operador != 10);

    printf("Encerramento Requisitado\nFim do Programa\n");

    return 0;
}