#include <stdio.h>
#include "..\headers\rec-encadin.h"

int main(){
    list lst;
    int input, output, retorno, operador, flag = 0;
    double elem;

    printf("Insira a operacao desejada:\n[1] Criar lista\n[2] Inserir Elemento\n[3] Remover Elemento\n[4] Imprimir Lista\n[5] Encerrar Operacao\n");

    do{
        printf("\nInput de operador: ");
        scanf("%d", &operador);

        switch(operador){
            case 1:
                if(flag == 1){
                    printf("Lista ja inicializada\nInsira outra operacao\n");
                    break;
                }

                flag = 1;
                lst = criaLista();
                printf("Inicializacao requisitada\n");
            break;

            case 2:
                if(flag == 0){
                    printf("Lista nao inicializada\nImpossivel inserir\n");
                    break;
                }

                printf("Digite o inteiro a ser inserido: ");
                scanf("%lf", &elem);

                retorno = insereOrd(&lst, elem);
                if(retorno == 0)
                    printf("Falha ao alocar no\nImpossivel inserir elemento\n");
                else if(retorno == 1)
                    printf("Elemento inserido com sucesso\n");
            break;

            case 3:
                if(flag == 0 || listaVazia(&lst) == 1){
                    printf("Lista nao inicializada ou vazia\nImpossivel remover\n");
                    break;
                }

                printf("Digite o inteiro a ser removido: ");
                scanf("%lf", &elem);

                retorno = removeOrd(&lst, elem);
                if(retorno == 0)
                    printf("Lista vazia ou elemento nao presente\nFalha ao remover\n");
                else if(retorno == 1)
                    printf("Elemento removido com sucesso\n");
            break;

            case 4:
                if(flag == 0 || listaVazia(&lst) == 1){
                    printf("Lista nao inicializada ou vazia\nImpossivel imprimir elementos\n");
                    break;
                }

                input = 1;
                do{
                    retorno = getData(&lst, input, &elem);
                    if(retorno == 0)
                         break;
                    printf("[%d] %.2lf\n", input, elem);
                    input++;
                }while(retorno == 1);
            break;
        }
    }while(operador != 5);

    printf("Encerramento de operacao requisitado\nFim do programa\n");

    return 0;
}