#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bebida{
    float preco;
    int volume;
    char nome[20];
};

void insereRegistro(struct bebida *vetor[], int i){
    vetor[i] = (struct bebida *) malloc(1*sizeof(struct bebida *));
    printf("Digitar o nome da %da bebida: ", i+1);
    setbuf(stdin, NULL);
    fgets(vetor[i]->nome, 20, stdin);
    vetor[i]->nome[strlen(vetor[i]->nome) - 1] = '\0';
    printf("Digitar o volume da %da bebida: ", i+1);
    // inserir um if para verificar se o volume não é negativo
    scanf("%d", &vetor[i]->volume);
    printf("Digitar o preco da %da bebida: ", i+1);
    // inserir um if para verificar se o preço não e negativo
    scanf("%f", &vetor[i]->preco);
    // Deveria ter inserido uma verificação se o vetor está cheio e mensagens de erro
}

void apagaUltimo(struct bebida *vetor[], int i){
    free(vetor[i]);
    vetor[i] = NULL;
    // Deveria ter inserido uma verificação se o vetor está vazio e mensagens de erro e de apagar
}

void imprimeTabela(struct bebida *vetor[], int i){
    int j;
    for(j = 0; j < i; j++){
        printf("Posicao %d da tabela\n", j+1);
        printf("Nome da bebida: %s\n", vetor[j]->nome);
        printf("Volume da bebida: %d mL\n", vetor[j]->volume);
        printf("Preco da bebida: %.2f\n\n", vetor[j]->preco);
    }
}



int main(){
    struct bebida *registroTabela[20];
    int i, indOperador, j;

    for(i = 0; i < 20; i++){
        registroTabela[i] = NULL;
    }

    i = 0;

    printf("Digite o indice da operacao desejada:\n\n[1] Inserir registro\n[2] Apagar ultimo registro\n[3] Imprimir tabela\n[4] Saida\n");

    do{
        printf("\nIndice: ");
        setbuf(stdin, NULL);
        scanf("%d", &indOperador);
        printf("\n");
        if(indOperador == 1){
            if(i < 19){ // deveria ser <= e ficar dentro da função insereRegistro
                insereRegistro(registroTabela, i);
                i++;
            }
        }
        else if(indOperador == 2){
            if(i > 0){ // deveria ser >= e ficar dentro da função apagaUltimo, assim como meu i--
                i--;
                apagaUltimo(registroTabela, i);
            }
        }
        else if(indOperador == 3){
            imprimeTabela(registroTabela, i);
        }

    }while(indOperador != 4);

    printf("Saida requisitada\nFim do Programa\n");

    for(j = 0; j < i; j++){
        free(registroTabela[j]);
    }

    return 0;
}