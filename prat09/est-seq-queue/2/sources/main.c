#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "..\headers\index-queue.h"

int main(){
    Queue q = NULL;
    int operador;
    char *inOut = (char *) malloc(11*sizeof(char));


    printf("----Tabela de Operacoes----\n");
    printf("[1]........Inicializar fila\n");
    printf("[2].Inserir string no final\n");
    printf("[3].Remover primeira string\n");
    printf("[4]...........Imprimir fila\n");
    printf("[5].......Encerrar operacao\n");

    do{
        int retorno;

        printf("\nInput de operacao: ");
        scanf("%d", &operador);

        switch(operador){
            case 1:
                if(q != NULL){
                    printf("Fila ja inicializada\n");
                    break;
                }
                q = newQ();
                printf("Fila inicializada\n");
            break;

            case 2:
                if(q == NULL){
                    printf("Fila nao inicializada\nOperacao cancelada\n");
                    break;
                }

                setbuf(stdin, NULL);
                fgets(inOut, 11, stdin);
                inOut[strlen(inOut) - 1] = '\0';

                retorno = insertEnd(q, inOut);
                if(retorno == 0){
                    printf("Fila cheia\nFalha\n");
                }
                else printf("String inserida na fila\n");
            break;

            case 3:
                if(q == NULL){
                    printf("Fila nao inicializada\nOperacao cancelada\n");
                    break;
                }

                retorno = removeStart(q, &inOut);
                if(retorno == 0){
                    printf("Fila vazia\nFalha\n");
                }
                else printf("String *%s* removida do inicio da fila\n", inOut);
            break;

            case 4:
                if(q == NULL){
                    printf("Fila nao inicializada ou vazia\nOperacao cancelada\n");
                    break;
                }
                Queue aux = newQ();
                int i = 1;

                do{
                    retorno = removeStart(q, &inOut);
                    if(retorno == 0){
                        printf("Fila vazia\n");
                        break;
                    }
                    printf("[%d] %s\n", i, inOut);
                    retorno = insertEnd(aux, inOut);
                    i++;
                }while(retorno == 1);

                do{
                    retorno = removeStart(aux, &inOut);
                    if(retorno == 0)
                        break;
                    retorno = insertEnd(q, inOut);
                }while(retorno == 1);
            break;

        }

    }while(operador != 5);

    printf("Fim do programa\n");

    return 0;
}



