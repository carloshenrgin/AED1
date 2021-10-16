#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dadosAlunos{
    int matricula, nota;
    char nome[50];
};

int lerDados(struct dadosAlunos *p){
    int qtdAlunos, i;
    printf("Digite o numero de alunos: ");
    scanf("%d", &qtdAlunos);
    p = calloc(qtdAlunos, sizeof(struct dadosAlunos));
    for(i = 0; i<qtdAlunos; i++){
        printf("Digite o numero da matricula do %do aluno: ", i+1);
        scanf("%d", &(*(p + i)).matricula);
        printf("Digite o nome do %do aluno: ", i+1);
        setbuf(stdin, NULL);
        fgets((*(p+i)).nome, 50, stdin);
        (*(p+i)).nome[strlen((*(p+i)).nome) - 1] = '\0';
        setbuf(stdin, NULL);
        printf("Digite a nota final do %do aluno (0 a 100): ", i+1);
        scanf("%d", &(*(p+i)).nota);
        setbuf(stdin, NULL);
    }
    
    for(i = 0; i<qtdAlunos; i++){
        printf("%d\n", (*(p+i)).matricula);
        printf("%s\n", (*(p+i)).nome);
        printf("%d\n", (*(p+i)).nota);
    }

    return qtdAlunos;
}

void gravarDados(struct dadosAlunos *p, int qtdAlunos, FILE *arquivo){
    int i;
    char nomeArq[50];
    printf("Digite o nome do arquivo a ser criado: ");
    setbuf(stdin, NULL);
    fgets(nomeArq, 50, stdin);
    nomeArq[strlen(nomeArq) - 1] = '\0';
    arquivo = fopen(nomeArq,"w+");

    for(i = 0; i<qtdAlunos; i++){
        printf("%d\n", (*(p+i)).matricula);
        fprintf(arquivo, "%d", (*(p+i)).matricula);
        printf("%s\n", (*(p+i)).nome);
        fprintf(arquivo, "%s", (*(p+i)).nome);
        printf("%d\n", (*(p+i)).nota);
        fprintf(arquivo, "%d", (*(p+i)).nota);
        rewind(arquivo);
    }

    fclose(arquivo);
}


int main(){
    FILE *arqEX6;
    /* char nomeArq[50];

    printf("Digite o nome do arquivo a ser criado: ");
    setbuf(stdin, NULL);
    fgets(nomeArq, 50, stdin);
    nomeArq[strlen(nomeArq) - 1] = '\0';
    arqEX6 = fopen(nomeArq,"w+"); */

    int qtdAlunos;
    struct dadosAlunos *dados;
    
    qtdAlunos = lerDados(dados);
    gravarDados(dados, qtdAlunos, arqEX6);


    
    return 0;
}