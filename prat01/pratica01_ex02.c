#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct agendaTel{
    char nome[50];
    int ddd, numTel;
    char tipoTel[10];
};


int cadastroAgenda(struct agendaTel *p, int i){
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

    return i;
}

void consultaAgenda(struct agendaTel *p, int j){
    char consulta[50];
    int i;
    printf("Insira o nome a ser consultado na agenda: ");
    fgets(consulta, 50, stdin);
    consulta[strlen(consulta) - 1] = '\0';
    setbuf(stdin, NULL);
    if(strcmp(consulta, "FIM") != 0){
        for(i = 0; i<j+1; i++){
            if(strcmp(consulta, (*(p+i)).nome) == 0){
                printf("DDD e Telefone de %s: %d %d\n\n", (*(p+i)).nome, (*(p+i)).ddd, (*(p+i)).numTel);
            }
        }
    }
    if(strcmp(consulta, "FIM") != 0) consultaAgenda(p,j);

} 



int main(){
    struct agendaTel *cadastro = malloc(20*sizeof(struct agendaTel));
    int i, tempConsulta;
    
    tempConsulta = cadastroAgenda(cadastro, i);
    consultaAgenda(cadastro, tempConsulta);
    free(cadastro);

    return 0;
}