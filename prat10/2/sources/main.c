#include <stdio.h>
#include <stdlib.h>
#include "..\headers\void-encadin.h"

int main(){
    list l;
    int operador, retorno, flag = 0;
    float gradeF;
    char gradeC;
    void *inOut;
    int i;
    
    printf("---------Tabela---------\n");
    printf("[1]....Inicializar Lista\n");
    printf("[2].........Inserir Nota\n");
    printf("[3].........Remover Nota\n");
    printf("[4].......Imprimir Lista\n");
    printf("[5]....Encerrar Operacao\n");

    do{
        printf("\nInput de operador: ");
        scanf("%d", &operador);

        switch(operador){
            case 1:
                if(flag == 1){
                    printf("Lista ja inicializada\nRequisicao cancelada\n");
                    break;
                }

                flag = 1;
                l = createList();
                printf("Lista inicializada\n");
            break;

            case 2:
                if(flag == 0){
                    printf("Lista ainda nao inicializada\nRequisicao cancelada\n");
                    break;
                }

                printf("Digite o tipo de nota a ser inserida:\n");
                printf(" [1] Conceito (A, B, C ou D)\n");
                printf(" [2] Numero real (Ex: 9.5, 6.3, etc.)\n");

                do{
                    printf("\n Input:\n");
                    scanf("%d", &operador);
                    printf("\n Digite a nota a ser inserida:\n");
                    if(operador == 1){
                        setbuf(stdin, NULL);
                        do{
                            scanf("%c", &gradeC);
                        }while(gradeC != 'A' && gradeC != 'B' && gradeC != 'C' && gradeC != 'D');
                        inOut = &gradeC;
                    }
                    else if(operador == 2){
                        scanf("%f", &gradeF);
                        inOut = &gradeF;
                    }
                }while(operador != 1 && operador != 2);

                retorno = insertGrade(&l, inOut, operador);

                if(retorno == 0)
                    printf("Erro ao alocar novo no\nFalha ao inserir\n");
                else
                    printf("Sucesso\n");
            break;

            case 3:
                if(flag == 0){
                    printf("Lista ainda nao inicializada\nRequisicao cancelada\n");
                    break;
                }

                printf("Digite o tipo de nota a ser removida:\n");
                printf(" [1] Conceito (A, B, C ou D)\n");
                printf(" [2] Numero real (Ex: 9.5, 6.3, etc.)\n");

                do{
                    printf("\n Input:\n");
                    scanf("%d", &operador);
                    printf("\n Digite a nota a ser removida:\n");
                    if(operador == 1){
                        setbuf(stdin, NULL);
                        do{
                            scanf("%c", &gradeC);
                        }while(gradeC != 'A' && gradeC != 'B' && gradeC != 'C' && gradeC != 'D');
                        inOut = &gradeC;
                    }
                    else if(operador == 2){
                        scanf("%f", &gradeF);
                        inOut = &gradeF;
                    }
                }while(operador != 1 && operador != 2);

                retorno = removeGrade(&l, inOut, operador);
                
                if(retorno == 0)
                    printf("Lista vazia ou nota nao encontrada\nFalha ao remover\n");
                else
                    printf("Sucesso ao remover\n");
            break;

            case 4:
                if(flag == 0 || emptyList(l)){
                    printf("Lista nao inicializada ou vazia\nRequisicao cancelada\n");
                    break;
                }

                i = 1;
                do{
                    retorno = getGradebyPos(l, &inOut, &operador, i);
                    if(retorno == 1){
                        if(operador == 1){
                            printf("[%d] %c\n", i, *(char *) inOut);
                        }
                        else
                            printf("[%d] %.1f\n", i, *(float *) inOut);
                    }
                    i++;
                }while(retorno == 1);
            break;
        }

    }while(operador != 5);

    printf("Fim de operacao\n");

    return 0;
}