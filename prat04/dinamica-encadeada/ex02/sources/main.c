#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\headers\nao-ordenada.h"

int main(){
    list lst;
    dados leitura;
    int operador, retorno, i, flag = 0;


    printf("Insira a operacao desejada:\n[1] Inicializar Lista\n[2] Inserir Elemento\n[3] Remover Elemento\n[4] Imprimir Lista\n[5] Encerrar Operacao\n");
    do{
        printf("\nOperacao: ");
        scanf("%d", &operador);
        
        switch(operador){
            case 1:
                printf("Inicializacao Requisitada\n");
                lst = criaLista();
                flag = 1;
            break;

            case 2:
                if(flag == 0){
                    printf("Lista Nao Inicializada\nImpossivel Inserir Dados\n");
                    break;
                }
                printf("Digite o numero de matricula do aluno a ser listado (OBS: O numero deve ser positivo): ");
                scanf("%u", &leitura.matricula);

                printf("Digite o nome do aluno a ser listado: ");
                setbuf(stdin, NULL);
                fgets(leitura.nome, 21, stdin);
                leitura.nome[strlen(leitura.nome) - 1] = '\0';

                printf("Digite a media do aluno a ser listado (OBS: O valor deve ser positivo e menor ou igual a 100): ");
                do{
                    scanf("%f", &leitura.media);
                    if(leitura.media < 0  || leitura.media > 100)
                        printf("Valor Invalido\nPor favor, digite novamente: ");
                }while(leitura.media < 0 || leitura.media > 100);

                printf("Digite o numero de faltas do aluno a ser listado (OBS: O valor deve ser positivo): ");
                do{
                    scanf("%d", &leitura.faltas);
                    if(leitura.faltas < 0)
                        printf("Valor Invalido\nPor favor, digite novamente: ");
                }while(leitura.faltas < 0);

                retorno = insereElem(&lst, leitura);
                if(retorno == 1)
                    printf("Sucesso ao inserir os dados do aluno\n");
                if(retorno == 0)
                    printf("Falha ao inserir os dados do aluno\n");
            break;
            case 3:
                if(flag == 0){
                    printf("Lista Nao Inicializada\nImpossivel Remover Dados\n");
                    break;
                }
                if(listaVazia(&lst) == 1){
                    printf("Lista vazia\nImpossivel remover dados\n");
                    break;
                }
                
                printf("Digite o numero de matricula do aluno a ser removido (OBS: O numero deve ser positivo): ");
                scanf("%u", &leitura.matricula);

                printf("Digite o nome do aluno a ser removido: ");
                setbuf(stdin, NULL);
                fgets(leitura.nome, 21, stdin);
                leitura.nome[strlen(leitura.nome) - 1] = '\0';

                printf("Digite a media do aluno a ser removido (OBS: O valor deve ser positivo e menor ou igual a 100): ");
                
                do{
                    scanf("%f", &leitura.media);
                    if(leitura.media < 0  || leitura.media > 100)
                        printf("Valor Invalido\nPor favor, digite novamente: ");
                }while(leitura.media < 0 || leitura.media > 100);

                printf("Digite o numero de faltas do aluno a ser removido (OBS: O valor deve ser positivo): ");
                
                do{
                    scanf("%d", &leitura.faltas);
                    if(leitura.faltas < 0)
                        printf("Valor Invalido\nPor favor, digite novamente: ");
                }while(leitura.faltas < 0);

                retorno = removeElem(&lst, leitura);
                if(retorno == 1)
                    printf("Sucesso ao remover os dados do aluno\n");
                if(retorno == 0)
                    printf("Falha ao remover os dados do aluno\n");
            break;
            case 4:
                if(flag == 0){
                    printf("Lista Nao Inicializada\nImpossivel Mostrar Dados\n");
                    break;
                }
                if(listaVazia(&lst) == 1){
                    printf("Lista Vazia\nImpossivel Mostrar Dados\n");
                    break;
                }

                for(i = 0; i < tamanhoLista(&lst); i++){
                    retorno = getPos(&lst, i+1);
                    if(retorno == 0){
                        printf("Erro na impressao\nLista Vazia ou Posicao Passada Nao Presente\n");
                        break;
                    }
                }

            break;
        }
    }while(operador != 5);

    printf("Encerramento da operacao requisitado\nFim do programa\n");

    if(flag == 1)
        limpaLista(&lst);

    return 0;
}