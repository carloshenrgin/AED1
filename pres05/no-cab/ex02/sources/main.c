#include <stdio.h>
#include "..\headers\ord.h"

int main(){
    list lst = NULL;
    int operador, output, input, retorno;

    printf("Insira a operacao desejada:\n[1] Inicializar Lista\n[2] Inserir Elemento\n[3] Remover Elemento\n[4] Imprimir Lista\n[5] Encerrar Operacao\n");

    do{
        printf("\nInput de operacao: ");
        scanf("%d", &operador);

        switch(operador){
            case 1:
                if(lst == NULL){
                    lst = criaLista();
                    if(lst == NULL){
                        printf("Inicializacao falhou\n");
                        break;
                    }

                    printf("Inicializacao bem sucedida\n");
                }
                if(lst != NULL){
                    printf("Lista ja inicializada\n");
                }
            break;
            case 2:
                if(lst == NULL){
                    printf("Lista nao inicializada\nImpossivel inserir elemento\n");
                    break;
                }
                
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &input);

                retorno = insereElem(lst, input);
                if(retorno == 0){
                    printf("Falha ao inserir elemento\nMemoria insuficiente\n");
                }
                else if(retorno == 1){
                    printf("Sucesso ao inserir elemento\n");
                }
            break;
            case 3:
                if(lst == NULL || listaVazia(lst) == 1){
                    printf("Lista nao inicializada ou vazia\nImpossivel remover elemento\n");
                    break;
                }

                printf("Digite o elemento a ser removido: ");
                scanf("%d", &input);

                retorno = removeElem(lst, input);
                if(retorno == 0){
                    printf("Elemento nao presente\nFalha ao remover elemento\n");
                }
                else if(retorno == 1){
                    printf("Sucesso ao remover elemento\n");
                }
            break;
            case 4:
                if(lst == NULL || listaVazia(lst) == 1){
                    printf("Lista nao inicializada ou vazia\nImpossivel realizar impressao\n");
                    break;
                }
                
                input = 1;

                do{
                    retorno = getElem(lst, input, &output);
                    if(retorno == 0)
                        break;
                    printf("[%d] %d\n", input, output);
                    input++;
                }while(retorno == 1);
            break;
        }
    }while(operador != 5);

    printf("Encerramento de operacao requisitado\nFim do programa\n");

    limpaLista(lst);

    return 0;
}