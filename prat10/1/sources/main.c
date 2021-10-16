#include <stdio.h>
#include "..\headers\het-union.h"

int main(){
    List l = NULL;
    int retorno;
    int operador;
    int type;
    void* inOut;
    char concC;
    float concF;
    int i;

    printf("---------Tabela---------\n");
    printf("[1]....Inicializar Lista\n");
    printf("[2].........Inserir Nota\n");
    printf("[3].........Remover Nota\n");
    printf("[4].......Imprimir Lista\n");
    printf("[5]....Encerrar Operacao\n");

    do{
        printf("\nInput de Operacao: ");
        scanf("%d", &operador);

        switch(operador){
            case 1:
                if(l != NULL){
                    printf("Lista ja inicializada\nRequisicao Cancelada\n");
                    break;
                }
                l = initializeList();
                printf("Lista Inicializada\n");
            break;

            case 2:
                printf("Digite o tipo de nota a ser inserida:\n");
                printf(" [1] Conceito (A, B, C ou D)\n");
                printf(" [2] Numero real entre 0 e 10\n");
                do{
                    printf("\n Input: ");
                    scanf("%d", &operador);
                }while(operador != 1 && operador != 2);

                printf("\n Digite a nota a ser inserida: ");
                if(operador == 1){
                    setbuf(stdin, NULL);
                    do{
                        scanf("%c", &concC);
                    }while(concC != 'A' && concC != 'B' && concC != 'C' && concC != 'D');
                    inOut = &concC;
                }
                else if(operador == 2){
                    do{
                        scanf("%f", &concF);
                        inOut = &concF;
                    }while(concF < 0 || concF > 10);
                }

                retorno = insertGrade(l, inOut, operador);
                if(retorno == 0)
                    printf("Falha ao inserir nota\nLista Cheia ou Nao Criada\n");
                else
                    printf("Sucesso ao inserir nota\n");
            break;

            case 3:
                printf("Digite o tipo de nota a ser removida:\n");
                printf(" [1] Conceito (A, B, C ou D)\n");
                printf(" [2] Numero real entre 0 e 10\n");
                do{
                    printf("\n Input: ");
                    scanf("%d", &operador);
                }while(operador != 1 && operador != 2);
                    
                printf("\n Digite a nota a ser removida: ");
                if(operador == 1){
                    setbuf(stdin, NULL);
                    do{
                        scanf("%c", &concC);
                    }while(concC != 'A' && concC != 'B' && concC != 'C' && concC != 'D');
                    inOut = &concC;
                }
                else if(operador == 2){
                    scanf("%f", &concF);
                    inOut = &concF;
                }

                retorno = removeGrade(l, inOut, operador);
                if(retorno == 0)
                    printf("Falha ao remover nota\nLista Vazia, Nao Criada ou Nota Nao Encontrada\n");
                else
                    printf("Sucesso ao remover nota\n");
            break;

            case 4:
                if(l == NULL || emptyList(l) == 1){
                    printf("Lista vazia ou invalida\nRequisicao Cancelada\n");
                    break;
                }
                i = 1;
                do{
                    retorno = getGradebyPos(l, i, &inOut, &operador);
                    if(retorno == 1){
                        if(operador == 1)
                            printf("[%d] %c\n", i, *(char *) inOut);
                        else
                            printf("[%d] %.1f\n", i, *(float *) inOut);
                    }
                    i++;
                }while(retorno == 1);

            break;
        }

    }while(operador != 5);

    printf("Fim de Operacao\n");
    return 0;
}