#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
    double media;
    int faltas;
    char nome[50];
};

void selectionSort(struct aluno *v, int n){
    int i, j, menor;
    struct aluno troca;
    for(i = 0; i < n; i++){
        menor = i;
        for(j = i + 1; j < n; j++){
            if(v[j].media < v[menor].media){
                menor = j;
            }
        }
        if(i != menor){
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }
}

int main(){
    int qtdAlunos, i;

    do{
        printf("Digite a quantidade de alunos na turma (qtd > 0): ");
        scanf("%d", &qtdAlunos);
    }while(qtdAlunos < 1);

    struct aluno *turma = (struct aluno *) calloc(qtdAlunos, sizeof(struct aluno));
    
    for(i = 0; i < qtdAlunos; i++){
        printf("Insira o nome do %do aluno: ", i+1);
        setbuf(stdin, NULL);
        fgets(turma[i].nome, 50, stdin);
        if(turma[i].nome[strlen(turma[i].nome) - 1] == '\n'){
            turma[i].nome[strlen(turma[i].nome) - 1] = '\0';
        }

        do{
            printf("Insira a media do %do aluno: ", i+1);
            scanf("%lf", &turma[i].media);
        }while(turma[i].media < 0);

        do{
            printf("Insira a quantidade de faltas do %do aluno: ", i+1);
            scanf("%d", &turma[i].faltas);
        }while(turma[i].faltas < 0);
    }

    for(i = 0; i < qtdAlunos; i++){
        selectionSort(turma, qtdAlunos);
    }
    
    printf("\n");

    for(i = 0; i< qtdAlunos; i++){
        printf("Nome do %do aluno: %s\n", i+1, turma[i].nome);
        printf("Media do %do aluno: %.2lf\n", i+1, turma[i].media);
        printf("Quantidade de faltas do %do aluno: %d\n\n", i+1, turma[i].faltas);
    }

    free(turma);
    return 0;
}