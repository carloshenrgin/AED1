#include <stdio.h>
#include "..\headers\stack-encadin.h"

int main(){
    Stack stk;
    int operador, flag = 0;

    printf("----Lista de Operacoes----\n");
    printf("[1].............Cria Pilha\n");
    printf("[2].......Empilha elemento\n");
    printf("[3]....Desempilha elemento\n");
    printf("[4]............Mostra Topo\n");
    printf("[5]...........Mostra Pilha\n");
    printf("[6].......Encerra Operacao\n");

    do{
        int inOut, retorno, i;

        printf("\nInput de operacao: ");
        scanf("%d", &operador);
        switch(operador){
            case 1:
                if(flag == 1){
                    printf("Pilha ja criada\n");
                    break;
                }

                flag = 1;
                stk = newStack();
                printf("Pilha criada\n");
            break;

            case 2:
                if(flag == 0){
                    printf("Pilha nao criada\nRequisicao cancelada\n");
                    break;
                }

                printf("Digite o elemento a ser empilhado: ");
                scanf("%d", &inOut);
                retorno = push(&stk, inOut);
                if(retorno == 0){
                    printf("Falha ao alocar novo no\nFalha\n");
                }
                else printf("Sucesso\n");
            break;

            case 3:
                if(flag == 0){
                    printf("Pilha nao criada\nRequisicao cancelada\n");
                    break;
                }

                retorno = pop(&stk, &inOut);
                if(retorno == 0){
                    printf("Pilha vazia\nFalha\n");
                }
                else{
                    printf("Elemento desempilhado: %d\n", inOut);
                }
            break;

            case 4:
                if(flag == 0){
                    printf("Pilha nao criada\nRequisicao cancelada\n");
                    break;
                }

                retorno = getTop(stk, &inOut);
                if(retorno == 0)
                    printf("Pilha vazia ou nao alocada\nFalha\n");
                else printf("Elemento do topo: %d\n", inOut);
            break;

            case 5:
                if(flag == 0){
                    printf("Pilha nao criada\nRequisicao cancelada\n");
                    break;
                }

                Stack aux = newStack();
                i = 1;
                do{
                    retorno = pop(&stk, &inOut);
                    if(retorno == 0){
                        printf("Pilha vazia\n");
                        break;
                    }
                    
                    printf("[%d] %d\n", i, inOut);
                    i++;
                    retorno = push(&aux, inOut);
                }while(retorno != 0);

                do{
                    retorno = pop(&aux, &inOut);
                    if(retorno == 0){
                        printf("Pilha auxiliar vazia\n");
                        break;
                    }

                    retorno = push(&stk, inOut);
                }while(retorno != 0);
            break;

        }
    }while(operador != 6);

    printf("Cabo\n");

    return 0;
}