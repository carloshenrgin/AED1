#include <stdio.h>
#include "..\headers\circular.h"

int main(){
    list lst = NULL;
    int operador, retorno, input, output, flag = 0;

    printf("Insira a operacao desejada:\n[1] Inicializar Lista\n[2] Inserir Elemento (No Inicio)\n[3] Remover Elemento (No Final)\n[4] Imprimir Lista\n[5] Encerrar Operacao\n");

    do{
        printf("\nInput de operacao: ");
        scanf("%d", &operador);

        switch(operador){
            case 1:
                if(flag == 0){
                    lst = criaLista();
                    flag = 1;
                    printf("Inicializacao requisitada\n");
                    break;
                }
                if(flag == 1){
                    printf("Lista ja inicializada\n");
                }
            break;

            case 2:
                if(flag == 0){
                    printf("Lista nao inicializada\nImpossivel inserir elemento\n");
                    break;
                }
                
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &input);

                retorno = insereInicio(&lst, input);
                if(retorno == 0){
                    printf("Falha ao inserir elemento\nMemoria insuficiente\n");
                }
                else if(retorno == 1){
                    printf("Sucesso ao inserir elemento\n");
                }
            break;

            case 3:
                if(flag == 0 || listaVazia(&lst) == 1){
                    printf("Lista nao inicializada ou vazia\nImpossivel remover elemento\n");
                    break;
                }

                printf("Remocao do ultimo elemento requisitada\n");

                retorno = removeFinal(&lst, &output);
                if(retorno == 0){
                    printf("Lista Vazia\nFalha ao remover elemento\n");
                }
                else if(retorno == 1){
                    printf("Sucesso ao remover o elemento %d do final da lista\n", output);
                }
            break;

            case 4:
                if(flag == 0 || listaVazia(&lst) == 1){
                    printf("Lista nao inicializada ou vazia\nImpossivel realizar impressao\n");
                    break;
                }
                
                input = 1;

                do{
                    retorno = obtemValor(&lst, input, &output);
                    if(retorno == 0)
                        break;
                    printf("[%d] %d\n", input, output);
                    input++;
                }while(retorno == 1);
            break;
        }
    }while(operador != 5);

    printf("Encerramento de operacao requisitado\nFim do programa\n");

    return 0;
}