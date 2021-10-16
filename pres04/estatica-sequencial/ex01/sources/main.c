#include <stdio.h>
#include <stdlib.h>
#include "..\headers\naoordenada.h"

int main(){
    list lst;
    float elem;
    int operador, retorno;

    printf("Tabela de Operacoes:\n[1] Inicializar Lista\n[2] Inserir Elemento\n[3] Remover Elemento\n[4] Imprimir Lista\n[5] Limpar Lista\n[6] Finalizar Operacao\n");

    do{
        printf("\nInsira o numero da operacao desejada: ");
        scanf("%d", &operador);
        
        switch(operador){
            case 1:
                printf("Operacao de Inicializacao Requisitada\n");
                lst = criaLista();
            break;
            case 2:
                printf("Insira o elemento a ser inserido na lista: ");
                scanf("%f", &elem);
                retorno = insereElem(lst, elem);
                if(retorno == 0)
                    printf("Erro ao inserir o elemento\nLista Cheia ou Nao Inicializada\n");
                if(retorno == 1)
                    printf("Elemento inserido com sucesso\n");
            break;
            case 3:
                printf("Insira o elemento a ser removido da lista: ");
                scanf("%f", &elem);
                retorno = removeElem(lst, elem);
                if(retorno == 0){
                    printf("Erro ao remover o elemento\nLista Vazia, Nao Inicializada ou Elemento nao Presente\n");
                }
                if(retorno == 1){
                    printf("Elemento removido com sucesso\n");
                }
            break;
            case 4:
                imprimeLista(lst);
            break;
            case 5:
                limpaLista(lst);
                printf("Lista limpa\n");
            break;
        }

    }while(operador != 6);

    printf("Operacao Finalizada\nFim do Programa\n");

    free(lst);

    return 0;
}