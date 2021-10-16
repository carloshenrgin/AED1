#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "..\headers\bebida-ordenada.h"

int main(){
    list lst = NULL;
    char nome[21];
    float preco;
    int operador, retorno, volume, i;

    printf("Insira a operacao desejada:\n[1] Inicializar Lista\n[2] Inserir Elemento\n[3] Remover Elemento\n[4] Imprimir Lista\n[5] Finalizar Operacao\n");

    do{
        printf("\nInsira o operador: ");
        scanf("%d", &operador);

        switch(operador){
        case 1:
            printf("Inicializacao requisitada\n");
            lst = criaLista();
        break;

        case 2:
            if(lst == NULL || listaCheia(lst) == 1){
                printf("Lista Cheia ou Nao Inicializada\nImpossivel Realizar Operacao\n");
                break;
            }

            printf("Digite o nome da bebida a ser listada: ");
            setbuf(stdin, NULL);
            fgets(nome, 21, stdin);
            nome[strlen(nome) - 1]  = '\0';

            do{
                printf("Digite o volume da bebida a ser listada: ");
                scanf("%d", &volume);
            }while(volume < 0);

            do{
                printf("Digite o preco da bebida a ser listada: ");
                scanf("%f", &preco);
            }while(preco < 0);

            retorno = insereOrd(lst, nome, volume, preco);

            if(retorno == 0)
                printf("Lista Cheia ou Nao Inicializada\nImpossivel Inserir Elemento\n");
            else if(retorno == 1)
                printf("Elemento inserido com sucesso\n");
        break;

        case 3:
            if(lst == NULL || listaVazia(lst) == 1){
                printf("Lista Vazia ou Nao Inicializada\nImpossivel Remover Elemento\n");
                break;
            }
            else{
                printf("Insira o nome da bebida a ser removida: ");
                setbuf(stdin, NULL);
                fgets(nome, 21, stdin);
                nome[strlen(nome) - 1]  = '\0';

                do{
                    printf("Digite o volume da bebida a ser removida: ");
                    scanf("%d", &volume);
                }while(volume < 0);

                do{
                    printf("Digite o preco da bebida a ser removida: ");
                    scanf("%f", &preco);
                }while(preco < 0);

                retorno = removeOrd(lst, nome, volume, preco);
                if(retorno == 0)
                    printf("Lista Cheia, Nao Inicializada ou Elemento Nao Presente\nImpossivel Remover Elemento\n");
                else if(retorno == 1)
                    printf("Elemento removido com sucesso\n");
                }
        break;

        case 4:
            if(lst == NULL || listaVazia(lst) == 1){
                printf("Lista Vazia ou Nao Inicializada\nImpossivel Imprimir Lista\n");
                break;
            }
            for(i = 0; i < tamanhoLista(lst); i++){
                getElem(lst, i+1);
            }
        break;
    }
    }while(operador != 5);

    printf("Saida requisitada\nFim do programa\n");

    limpaLista(lst);
    
    return 0;
}
