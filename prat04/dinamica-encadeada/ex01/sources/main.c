#include <stdio.h>
#include "..\headers\ordenada.h"

int main(){
    list lst;
    int leitura, operador, retorno, flag = 0, out;

    printf("Insira a operacao desejada:\n[1] Inicializar Lista\n[2] Inserir Elemento\n[3] Remover Primeira Ocorrencia de Elemento\n[4] Remover Elemento Por Posicao\n[5] Imprimir Lista\n[6] Encerrar Operacao\n");

    do{
        printf("\nOperacao: ");
        scanf("%d", &operador);

        switch(operador){
            case 1:
                if(flag == 0){
                    flag = 1;
                    printf("Inicializacao requisitada\n");
                    lst = criaLista();
                    
                }
                else if(flag == 1){
                    printf("Lista ja inicializada\nPor favor insira outra operacao no terminal\n");
                }
            break;
            case 2:
                if(flag == 0){
                    printf("Lista Nao Inicializada\nImpossivel Inserir Elementos\n");
                    break;
                }
                printf("Insira o numero inteiro a ser listado: ");
                scanf("%d", &leitura);
                
                retorno = insereOrd(&lst, leitura);
                if(retorno == 0){
                    printf("Falha ao inserir elemento\n");
                }
                if(retorno == 1){
                    printf("Elemento inserido com sucesso\n");
                }
            break;
            case 3:
                if(flag == 0 || listaVazia(&lst) == 1){
                    printf("Lista Vazia ou Nao Inicializada\nImpossivel Remover Elementos\n");
                    break;
                }
                printf("Insira o numero inteiro a ser removido: ");
                scanf("%d", &leitura);

                retorno = removeOrd(&lst, leitura);
                if(retorno == 0){
                    printf("Falha ao remover elemento\nElemento Nao Presente\n");
                }
                if(retorno == 1){
                    printf("Elemento removido com sucesso\n");
                }
            break;
            case 4:
                if(flag == 0 || listaVazia(&lst) == 1){
                    printf("Lista Vazia ou Nao Inicializada\nImpossivel Remover Elementos\n");
                    break;
                }
                printf("Insira a posicao do numero a ser removido: ");
                scanf("%d", &leitura);

                retorno = removePos(&lst, leitura, &out);
                if(retorno == 0){
                    printf("Lista Vazia ou Posicao Nao Preenchida\nImpossivel Remover Elementos\n");
                }
                if(retorno == 1){
                    printf("Elemento %d removido com sucesso da %da poiscao\n", out, leitura);
                }
            break;
            case 5:
                if(flag == 0 || listaVazia(&lst) == 1){
                    printf("Impossivel mostrar elementos\nLista vazia ou nao inicializada\n");
                    break;
                }

                int i;
                for(i = 0; i < tamanhoLista(&lst); i++){
                    retorno = getElem(&lst, i+1, &out);
                    if(retorno == 0){
                        printf("Erro ao mostrar elementos\n");
                        break;
                    }
                    if(retorno == 1){
                        printf("%do elemento: %d\n", i+1, out);
                    }
                }
            break;
        }

    }while(operador != 6);

    printf("Encerramento da operacao requisitado\nFim do programa\n");

    if(flag == 1)
        limpaLista(&lst);

    return 0;
}