#include <stdlib.h>
#include <stdio.h>
#include "..\headers\encadin.h"

int main(){
    lista lst;
    char elem;
    int operador, retorno;

    printf("Insira a operacao desejada:\n[1] Criar lista\n[2] Inserir Elemento\n[3] Remover Elemento\n[4] Imprimir Lista\n[5] Limpar Lista\n[6] Finalizar Operacao\n");
    
    do{
        printf("\nOperacao: ");
        scanf("%d", &operador);
        switch(operador){
            case 1:
                lst = criaLista();
                printf("Lista criada\n");
            break;
            case 2:
                printf("Insira o elemento a ser inserido na lista: ");
                scanf(" %c", &elem);
                retorno  = insereElem(&lst, elem);
                if(retorno == 1)
                    printf("Elemento inserido com sucesso\n");
                else if(retorno == 0){
                    printf("Falha ao inserir o elemento\n");
                }
            break;
            case 3:
                printf("Insira o elemento a ser removido da lista: ");
                scanf(" %c", &elem);
                retorno = removeElem(&lst, elem);
                if(retorno == 1)
                    printf("Elemento removido com sucesso\n");
                else if(retorno == 0){
                    printf("Falha ao remover o elemento\nLista nao criada ou elemento nao presente\n");
                }
            break;
            case 4:
                if(listaVazia(&lst))
                    printf("Lista vazia\nImpossivel imprimi-la na tela\n");
                else{
                    printf("Lista:\n");
                    int i = 0;
                    do{
                        retorno = obtemPos(&lst, i);
                        i++;
                    }while(retorno != 0);
                }   
            break;
            case 5:
                limpaLista(&lst);
                printf("Lista limpa\n");
            break;
        }
    }while(operador != 6);

    limpaLista(&lst);
    return 0;
}