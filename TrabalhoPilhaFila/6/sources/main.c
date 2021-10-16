#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\headers\fpd-encadin.h"
#include "..\headers\donation-register.h"

int main(){
    pQueue heartQ, liverQ, eyeQ, lungQ, kidneyQ, aux;
    list donRegister, heartDisp = initList(), liverDisp = initList(), eyeDisp = initList(), lungDisp = initList(), kidneyDisp = initList();
    int idade, gravidade;
    char *nome = (char *) malloc(sizeof(char)*20), *orgao = (char*) malloc(sizeof(char)*10);
    char **receiver = (char **) malloc(5*sizeof(char*));
    int i;
    for(i = 0; i < 5; i++){
        receiver[i] = (char *) malloc(20*sizeof(char));
    }


    char *nomeAux = (char *) malloc(sizeof(char)*20);


    int operador, flagIni[6] = {0,0,0,0,0,0}, retorno, *flagOrg = (int *) malloc(sizeof(int));

    printf("------------------Tabela------------------\n");
    printf("[1].......................Inicializar Fila\n");
    printf("[2].Inserir Paciente na Fila de Prioridade\n");
    printf("[3].............Imprimir Fila de Pacientes\n");
    printf("[4]..........Inicializar Lista de Doadores\n");
    printf("[5].........................Inserir Doador\n");
    printf("[6].............Imprimir Lista de Doadores\n");
    printf("[7]............Esvaziar Fila de Prioridade\n");
    printf("[8]......................Encerrar Operacao\n");

    do{
        printf("\nInput: ");
        scanf("%d", &operador);
        switch(operador){
            case 1:
                printf("Digite a fila de prioridade a ser inicializada\n");
                printf("[1].............Fila de Transplante de Coracao\n");
                printf("[2]..............Fila de Transplante de Figado\n");
                printf("[3]..............Fila de Transplante de Cornea\n");
                printf("[4]..............Fila de Transplante de Pulmao\n");
                printf("[5]..................Fila de Translante de Rim\n");
                do{
                    printf("\n   Input: ");
                    scanf("%d", &operador);
                }while(operador < 1 || operador > 5);

                if(flagIni[operador - 1] == 1){
                    printf("Fila em questao ja inicializada\nRequisicao Cancelada\n");
                    break;
                }
                flagIni[operador - 1] = 1;
                switch(operador){
                    case 1:
                        heartQ = initQueue();
                        printf("Fila de Transplante de Coracao Inicializada\n");
                        break;
                    case 2:
                        liverQ = initQueue();
                        printf("Fila de Transplante de Figado Inicializada\n");
                        break;
                    case 3:
                        eyeQ = initQueue();
                        printf("Fila de Transplante de Cornea Inicializada\n");
                        break;
                    case 4:
                        lungQ = initQueue();
                        printf("Fila de Transplante de Pulmao Inicializada\n");
                        break;
                    case 5:
                        kidneyQ = initQueue();
                        printf("Fila de Transplante de Rim Inicializada\n");
                        break;
                }

                break;

            case 2:
                printf("Digite a fila de prioridade onde o paciente sera inserido\n");
                printf("[1]........................Fila de Transplante de Coracao\n");
                printf("[2].........................Fila de Transplante de Figado\n");
                printf("[3].........................Fila de Transplante de Cornea\n");
                printf("[4].........................Fila de Transplante de Pulmao\n");
                printf("[5].............................Fila de Translante de Rim\n");

                do{
                    printf("\n   Input: ");
                    scanf("%d", &operador);
                }while(operador < 1 || operador > 5);

                if(flagIni[operador - 1] == 0){
                    printf("Fila em questao ainda nao inicializada\nRequisicao Cancelada\n");
                    break;
                }

                printf("Digite o nome do paciente a ser inserido: ");
                setbuf(stdin, NULL);
                fgets(nome, 10, stdin);
                nome[strlen(nome) - 1] = '\0';

                do{
                    printf("Digite a idade do paciente: ");
                    scanf("%d", &idade);
                }while(idade < 0);

                do{
                    printf("Digite o grau de gravidade da doença: ");
                    scanf("%d", &gravidade);
                }while(gravidade < 0);

                switch(operador){
                    case 1:
                        // Toda vez que tem orgao novo rola verificaçao se tem alguem na lista de espera
                        // Se tem orgao disponivel ja significa que a lista foi esgotada e o orgao so ta
                        // esperando um paciente para ser repassado
                        if(emptyList(heartDisp) == 0 && flagIni[5] == 1){
                            removeFst(&heartDisp, &nomeAux, &receiver ,&flagOrg); // remove da lista de disp
                            removeNode(&donRegister, nomeAux, flagOrg, receiver); // remove do cadastro
                            strcpy(receiver[0], nome); // atualiza dados
                            flagOrg[0] = 1;
                            insertNode(&donRegister, nomeAux, flagOrg, receiver); // reinsere
                            break;
                        }


                        printf("Inserindo na Fila de Transplante de Coracao\n");
                        retorno = insertSort(&heartQ, gravidade, idade, nome, "Coracao\0");
                        if(retorno == 0)
                            printf("Falha ao inserir\n");
                        else
                            printf("Sucesso ao inserir\n");
                        break;

                    case 2:
                        if(emptyList(liverDisp) == 0 && flagIni[5] == 1){
                            removeFst(&liverDisp, &nomeAux, &receiver ,&flagOrg); // remove da lista de disp
                            removeNode(&donRegister, nomeAux, flagOrg, receiver); // remove do cadastro
                            strcpy(receiver[1], nome); // atualiza dados
                            flagOrg[1] = 1;
                            insertNode(&donRegister, nomeAux, flagOrg, receiver); // reinsere no cadastro
                            break;
                        }

                        printf("Inserindo na Fila de Transplante de Figado\n");
                        retorno = insertSort(&liverQ, gravidade, idade, nome, "Figado\0");
                        if(retorno == 0)
                            printf("Falha ao inserir\n");
                        else
                            printf("Sucesso ao inserir\n");
                        break;

                    case 3:
                        if(emptyList(eyeDisp) == 0 && flagIni[5] == 1){
                            removeFst(&eyeDisp, &nomeAux, &receiver ,&flagOrg); // remove da lista de disp
                            removeNode(&donRegister, nomeAux, flagOrg, receiver); // remove do cadastro
                            strcpy(receiver[2], nome); // atualiza dados
                            flagOrg[2] = 1;
                            insertNode(&donRegister, nomeAux, flagOrg, receiver); // reinsere no cadastro
                            break;
                        }

                        printf("Inserindo na Fila de Transplante de Cornea\n");
                        retorno = insertSort(&eyeQ, gravidade, idade, nome, "Cornea\0");
                        if(retorno == 0)
                            printf("Falha ao inserir\n");
                        else
                            printf("Sucesso ao inserir\n");
                        break;

                    case 4:
                        if(emptyList(lungDisp) == 0 && flagIni[5] == 1){
                            removeFst(&lungDisp, &nomeAux, &receiver ,&flagOrg); // remove da lista de disp
                            removeNode(&donRegister, nomeAux, flagOrg, receiver); // remove do cadastro
                            strcpy(receiver[3], nome); // atualiza dados
                            flagOrg[3] = 1;
                            insertNode(&donRegister, nomeAux, flagOrg, receiver); // reinsere no cadastro
                            break;
                        }

                        printf("Inserindo na Fila de Transplante de Pulmao\n");
                        retorno = insertSort(&lungQ, gravidade, idade, nome, "Pulmao\0");
                        if(retorno == 0)
                            printf("Falha ao inserir\n");
                        else
                            printf("Sucesso ao inserir\n");
                        break;

                    case 5:
                        if(emptyList(kidneyDisp) == 0 && flagIni[5] == 1){
                            removeFst(&kidneyDisp, &nomeAux, &receiver ,&flagOrg); // remove da lista de disp
                            removeNode(&donRegister, nomeAux, flagOrg, receiver); // remove do cadastro
                            strcpy(receiver[4], nome); // atualiza dados
                            flagOrg[4] = 1;
                            insertNode(&donRegister, nomeAux, flagOrg, receiver); // reinsere no cadastro
                            break;
                        }

                        printf("Inserindo na Fila de Transplante de Rim\n");
                        retorno = insertSort(&kidneyQ, gravidade, idade, nome, "Rim\0");
                        if(retorno == 0)
                            printf("Falha ao inserir\n");
                        else
                            printf("Sucesso ao inserir\n");
                        break;
                        

                }

                break;

            case 3:
                printf("Digite a fila de prioridade a ser impressa\n");
                printf("[1].........Fila de Transplante de Coracao\n");
                printf("[2]..........Fila de Transplante de Figado\n");
                printf("[3]..........Fila de Transplante de Cornea\n");
                printf("[4]..........Fila de Transplante de Pulmao\n");
                printf("[5]..............Fila de Translante de Rim\n");

                do{
                    printf("\n   Input: ");
                    scanf("%d", &operador);
                }while(operador < 1 || operador > 5);

                if(flagIni[operador - 1] == 0){
                    printf("Fila em questao ainda nao inicializada\nRequisicao Cancelada\n");
                    break;
                }

                aux = initQueue();

                switch(operador){
                    case 1:
                        if(emptyQueue(heartQ) == 1){
                            printf("Fila Vazia\nRequisicao Cancelada\n");
                            break;
                        }
                        printf("Fila de Transplante de Coracao\n");
                        while(emptyQueue(heartQ) == 0){
                            removeBeg(&heartQ, &gravidade, &idade, &nome, &orgao);
                            retorno = insertSort(&aux, idade, gravidade, nome, orgao);
                            if(retorno == 0){
                                printf("Falta de memoria\n");
                                break;
                            }

                            printf("\nPaciente: %s, %d\nOrgao: %s\nGravidade: %d\n", nome, idade, orgao, gravidade);
                        }
                        
                        while(emptyQueue(aux) == 0){
                            removeBeg(&aux, &gravidade, &idade, &nome, &orgao);
                            retorno = insertSort(&heartQ, idade, gravidade, nome, orgao);
                            if(retorno == 0){
                                printf("Falta de memoria\n");
                                break;
                            }
                        }

                        break;
                    case 2:
                        if(emptyQueue(liverQ) == 1){
                            printf("Fila Vazia\nRequisicao Cancelada\n");
                            break;
                        }
                        printf("Fila de Transplante de Figado\n");
                        while(emptyQueue(liverQ) == 0){
                            removeBeg(&liverQ, &gravidade, &idade, &nome, &orgao);
                            retorno = insertSort(&aux, idade, gravidade, nome, orgao);
                            if(retorno == 0){
                                printf("Falta de memoria\n");
                                break;
                            }

                            printf("\nPaciente: %s, %d\nOrgao: %s\nGravidade: %d\n", nome, idade, orgao, gravidade);
                        }
                        
                        while(emptyQueue(aux) == 0){
                            removeBeg(&aux, &gravidade, &idade, &nome, &orgao);
                            retorno = insertSort(&liverQ, idade, gravidade, nome, orgao);
                            if(retorno == 0){
                                printf("Falta de memoria\n");
                                break;
                            }
                        }

                        break;
                    case 3:
                        if(emptyQueue(eyeQ) == 1){
                            printf("Fila Vazia\nRequisicao Cancelada\n");
                            break;
                        }
                        printf("Fila de Transplante de Cornea\n");
                        while(emptyQueue(eyeQ) == 0){
                            removeBeg(&eyeQ, &gravidade, &idade, &nome, &orgao);
                            retorno = insertSort(&aux, idade, gravidade, nome, orgao);
                            if(retorno == 0){
                                printf("Falta de memoria\n");
                                break;
                            }

                            printf("\nPaciente: %s, %d\nOrgao: %s\nGravidade: %d\n", nome, idade, orgao, gravidade);
                        }
                        
                        while(emptyQueue(aux) == 0){
                            removeBeg(&aux, &gravidade, &idade, &nome, &orgao);
                            retorno = insertSort(&eyeQ, idade, gravidade, nome, orgao);
                            if(retorno == 0){
                                printf("Falta de memoria\n");
                                break;
                            }
                        }

                        break;
                    case 4:
                        if(emptyQueue(lungQ) == 1){
                            printf("Fila Vazia\nRequisicao Cancelada\n");
                            break;
                        }
                        printf("Fila de Transplante de Pulmao\n");
                        while(emptyQueue(lungQ) == 0){
                            removeBeg(&lungQ, &gravidade, &idade, &nome, &orgao);
                            retorno = insertSort(&aux, idade, gravidade, nome, orgao);
                            if(retorno == 0){
                                printf("Falta de memoria\n");
                                break;
                            }

                            printf("\nPaciente: %s, %d\nOrgao: %s\nGravidade: %d\n", nome, idade, orgao, gravidade);
                        }
                        
                        while(emptyQueue(aux) == 0){
                            removeBeg(&aux, &gravidade, &idade, &nome, &orgao);
                            retorno = insertSort(&lungQ, idade, gravidade, nome, orgao);
                            if(retorno == 0){
                                printf("Falta de memoria\n");
                                break;
                            }
                        }

                        break;
                    case 5:
                        if(emptyQueue(kidneyQ) == 1){
                            printf("Fila Vazia\nRequisicao Cancelada\n");
                            break;
                        }
                        printf("Fila de Transplante de Rim\n");
                        while(emptyQueue(kidneyQ) == 0){
                            removeBeg(&kidneyQ, &gravidade, &idade, &nome, &orgao);
                            retorno = insertSort(&aux, idade, gravidade, nome, orgao);
                            if(retorno == 0){
                                printf("Falta de memoria\n");
                                break;
                            }

                            printf("\nPaciente: %s, %d\nOrgao: %s\nGravidade: %d\n", nome, idade, orgao, gravidade);
                        }
                        
                        while(emptyQueue(aux) == 0){
                            removeBeg(&aux, &gravidade, &idade, &nome, &orgao);
                            retorno = insertSort(&kidneyQ, idade, gravidade, nome, orgao);
                            if(retorno == 0){
                                printf("Falta de memoria\n");
                                break;
                            }
                        }

                        break;
                }

                break;

            case 4:
                if(flagIni[5] == 1){
                    printf("Lista de Doadores ja inicializada\nRequisicao Cancelada\n");
                    break;
                }

                flagIni[5] = 1;
                donRegister = initList();
                printf("Lista de Doadores Inicializada\n");

                break;

            case 5:
                if(flagIni[5] == 0){
                    printf("Lista de Doadores ainda nao inicializada\nRequisicao Cancelada\n");
                    break;
                }

                printf("Digite o nome do doador: ");
                setbuf(stdin, NULL);
                fgets(nome, 10, stdin);
                nome[strlen(nome) - 1] = '\0';

                printf("Assinale quais orgaos esse doador disponbilizou\n");
                printf("OBS: 1 para verdadeiro e 0 para falso\n");
                printf("[1] Coracao: \n");
                scanf("%d", &flagOrg[0]);
                printf("[2] Figado: \n");
                scanf("%d", &flagOrg[1]);
                printf("[3] Cornea: \n");
                scanf("%d", &flagOrg[2]);
                printf("[4] Pulmao: \n");
                scanf("%d", &flagOrg[3]);
                printf("[5] Rim: \n");
                scanf("%d", &flagOrg[4]);

                for(i = 0; i < 5; i++){
                    strcpy(*(receiver + i), "Nenhum");
                }

                if(emptyQueue(heartQ) == 1){
                    retorno = insertNode(&heartDisp, nome, flagOrg, receiver);
                    if(retorno == 0)
                        printf("Falta de memoria\n");
                }

                if(emptyQueue(liverQ) == 1){
                    retorno = insertNode(&liverDisp, nome, flagOrg, receiver);
                    if(retorno == 0)
                        printf("Falta de memoria\n");
                }

                if(emptyQueue(eyeQ) == 1){
                    retorno = insertNode(&eyeDisp, nome, flagOrg, receiver);
                    if(retorno == 0)
                        printf("Falta de memoria\n");
                }

                if(emptyQueue(lungQ) == 1){
                    retorno = insertNode(&lungDisp, nome, flagOrg, receiver);
                    if(retorno == 0)
                        printf("Falta de memoria\n");
                }

                if(emptyQueue(kidneyQ) == 1){
                    retorno = insertNode(&kidneyDisp, nome, flagOrg, receiver);
                    if(retorno == 0)
                        printf("Falta de memoria\n");
                }

                if(flagIni[0] == 1 && emptyQueue(heartQ) == 0 && flagOrg[0] == 1){
                    removeBeg(&heartQ, &gravidade, &idade, &receiver[0], &orgao);
                    printf("O paciente %s recebeu um transplante de coracao de %s\n", receiver[0], nome);
                }

                if(flagIni[1] == 1 && emptyQueue(liverQ) == 0 && flagOrg[1] == 1){
                    removeBeg(&liverQ, &gravidade, &idade, &receiver[1], &orgao);
                    printf("O paciente %s recebeu um transplante de figado de %s\n", receiver[1], nome);
                }

                if(flagIni[2] == 1 && emptyQueue(eyeQ) == 0 && flagOrg[2] == 1){
                    removeBeg(&eyeQ, &gravidade, &idade, &receiver[2], &orgao);
                    printf("O paciente %s recebeu um transplante de cornea de %s\n", receiver[2], nome);
                }

                if(flagIni[3] == 1 && emptyQueue(lungQ) == 0 && flagOrg[3] == 1){
                    removeBeg(&lungQ, &gravidade, &idade, &receiver[3], &orgao);
                    printf("O paciente %s recebeu um transplante de pulmao de %s\n", receiver[3], nome);
                }

                if(flagIni[4] == 1 && emptyQueue(kidneyQ) == 0 && flagOrg[4] == 1){
                    removeBeg(&kidneyQ, &gravidade, &idade, &receiver[4], &orgao);
                    printf("O paciente %s recebeu um transplante de rim de %s\n", receiver[4], nome);
                }

                retorno = insertNode(&donRegister, nome, flagOrg, receiver);
                if(retorno == 0)
                    printf("Falha ao inserir doador\n");
                else
                    printf("Sucesso ao inserir doador\n");
            
            break;

            case 6:
                if(emptyList(donRegister) == 1 || flagIni[5] == 0){
                    printf("Lista Vazia ou Nao Inicializada\nRequisicao Cancelada\n");
                    break;
                }

                i = 1;
                do{
                    retorno = getDatabyPos(donRegister, i, &nomeAux, &receiver, &flagOrg);
                    if(retorno == 1){
                        printf("Nome do Doador: %s\n", nomeAux);
                        printf("Orgaos doados:\n");
                        if(flagOrg[0] == 1){
                            printf("- Coracao\n");
                            printf("Recebedor: %s\n", receiver[0]);
                        }
                        if(flagOrg[1] == 1){
                            printf("- Figado\n");
                            printf("Recebedor: %s\n", receiver[1]);
                        }
                        if(flagOrg[2] == 1){
                            printf("- Cornea\n");
                            printf("Recebedor: %s\n", receiver[2]);
                        }
                        if(flagOrg[3] == 1){
                            printf("- Pulmao\n");
                            printf("Recebedor: %s\n", receiver[3]);
                        }
                        if(flagOrg[4] == 1){
                            printf("- Rim\n");
                            printf("Recebedor: %s\n", receiver[4]);
                        }
                    }
                    i++;
                }while(retorno != 0);
                break;

            case 7:
                printf("Digite a fila de prioridade a ser esvaziada\n");
                printf("[1]..........Fila de Transplante de Coracao\n");
                printf("[2]...........Fila de Transplante de Figado\n");
                printf("[3]...........Fila de Transplante de Cornea\n");
                printf("[4]...........Fila de Transplante de Pulmao\n");
                printf("[5]...............Fila de Translante de Rim\n");
                do{
                    printf("\n   Input: ");
                    scanf("%d", &operador);
                }while(operador < 1 || operador > 5);

                if(flagIni[operador - 1] == 0){
                    printf("Fila Nao Inicializada\nRequisicao Cancelada\n");
                    break;
                }

                switch(operador){
                    case 1:
                        back2Empty(&heartQ);
                        break;
                    case 2:
                        back2Empty(&liverQ);
                        break;
                    case 3:
                        back2Empty(&eyeQ);
                        break;
                    case 4:
                        back2Empty(&lungQ);
                        break;
                    case 5:
                        back2Empty(&kidneyQ);
                        break;
                }

                printf("Fila Esvaziada\n");

                break;


            
        }
    }while(operador != 8);
 
    printf("Encerramento Requisitado\nFim da Execucao\n");


    return 0;
}

