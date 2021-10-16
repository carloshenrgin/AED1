#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct agendaTel{
    char nome[50];
    int ddd, numTel;
    char tipoTel[10];
};


void cadastroAgenda(struct agendaTel *p, int i, int j){
    for(i = 0; i<20; i++){
        printf("Insira o nome a ser cadastrado: ");
        fgets((*(p+i)).nome, 50, stdin);
        (*(p+i)).nome[strlen((*(p+i)).nome) - 1] = '\0';
        setbuf(stdin, NULL);
        if(strcmp((*(p+i)).nome, "ACABOU") != 0){
            printf("Insira o DDD e o Numero de Telefone: ");
            scanf("%d %d", &(*(p+i)).ddd, &(*(p+i)).numTel);
            setbuf(stdin, NULL);
            printf("Insira o Tipo do Telefone (Fixo ou Celular): ");
            fgets((*(p+i)).tipoTel, 10, stdin);
            (*(p+i)).tipoTel[strlen((*(p+i)).tipoTel) - 1] = '\0';
            setbuf(stdin, NULL);
        }
        else if(strcmp((*(p+i)).nome, "ACABOU") == 0){
            break;
        }
    }
    for(j = 0; j<i+1; j++){
        if(strcmp((*(p+j)).nome, "ACABOU") == 0){
            break;
        }
        printf("Nome do %do contato: %s\n", j+1, (*(p+j)).nome);
        printf("Telefone do %do contato: %d %d\n", j+1, (*(p+j)).ddd, (*(p+j)).numTel);
        printf("Tipo do Telefone do %do contato: %s\n\n", j+1, (*(p+j)).tipoTel);
    }
}


int main(){
    struct agendaTel *cadastro = malloc(20*sizeof(struct agendaTel));
    int i, j;
    
    cadastroAgenda(cadastro, i, j);
    free(cadastro);

    return 0;
}