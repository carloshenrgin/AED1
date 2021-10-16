#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "..\headers\encadin-queue-simp.h"

int main(){
    Queue q;
    int operador, flag = 0, retorno;
    char *nome = (char*) malloc(11*sizeof(char));
    int vol;
    float price;

    printf("----Tabela de Operacoes----\n");
    printf("[1]........Inicializar Fila\n");
    printf("[2]........Inserir no final\n");
    printf("[3].......Remover no comeco\n");
    printf("[4]...........Imprimir fila\n");
    printf("[5]...........Esvaziar fila\n");
    printf("[6].............Apagar fila\n");
    printf("[7].......Encerrar operacao\n");
    
    do{
        printf("\nInput de operacao: ");
        scanf("%d", &operador);

        switch(operador){
            case 1:
                if(flag == 1){
                    printf("Fila ja inicializada\nRequisicao cancelada\n");
                    break;
                }

                printf("Fila inicializada");
                flag = 1;
                q = newQ();
            break;

            case 2:
                if(flag == 0){
                    printf("Fila nao inicializada\nRequisicao cancelada\n");
                    break;
                }

                printf("Digite o nome da bebida a ser inserida: ");
                setbuf(stdin, NULL);
                fgets(nome, 11, stdin);
                nome[strlen(nome) - 1] = '\0';
                printf("Digite o preco da bebida a ser inserida: ");
                scanf("%f", &price);
                printf("Digite o volume da bebida a ser inserida: ");
                scanf("%d", &vol);

                retorno = insertEnd(q, nome, vol, price);
                if(retorno == 0)
                    printf("Falha ao alocar o no\n");
                else printf("Sucesso ao inserir\n");
            break;

            case 3:
                if(flag == 0){
                    printf("Fila nao inicializada\nRequisicao cancelada\n");
                    break;
                }

                retorno = removeStart(q, &nome, &vol, &price);
                if(retorno == 0)
                    printf("Fila vazia\n");
                else printf("Bebida removida: %s, %dmL, R$%.2f\n", nome, vol, price);
            break;

            case 4:
                if(flag == 0){
                    printf("Fila nao inicializada\nRequisicao cancelada\n");
                    break;
                }

                Queue aux = newQ();
                int i = 1;
                do{
                    retorno = removeStart(q, &nome, &vol, &price);
                    if(retorno == 0){
                        printf("Lista vazia\n");
                        break;
                    }
                    printf("Bebida nº %d: %s, %dmL, R$%.2f\n", i, nome, vol, price);
                    retorno = insertEnd(aux, nome, vol, price);
                    i++;
                }while(retorno == 1);

                do{
                    retorno = removeStart(aux, &nome, &vol, &price);
                    if(retorno == 0) break;
                    retorno = insertEnd(q, nome, vol, price);
                }while(retorno == 1);

            break;

            case 5:
                if(flag == 0){
                    printf("Fila nao inicializada\nRequisicao cancelada\n");
                    break;
                }

                retorno = backToEmpty(q);
                if(retorno == 0) printf("Lista vazia\n");
                else printf("Lista esvaziada\n");
            break;

            case 6:
                if(flag == 0){
                    printf("Fila nao inicializada\nRequisicao cancelada\n");
                    break;
                }

                retorno = eraseQ(&q);
                if(retorno == 0) printf("Lista vazia\n");
                else{
                    printf("Lista apagada\n");
                    flag = 0;
                }
            break;
        }
    }while(operador != 7);

}