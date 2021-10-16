#include <stdio.h>
#include <stdlib.h>

void ordenarVetor(int *vetor){
    int qtd;
    int i;
    printf("Insira a quantidade de numeros (menor igual a 30) do vetor: ");
    scanf("%d", &qtd);
    if(qtd<=30){
        vetor = calloc(qtd, sizeof(int));
        printf("Insira os valores a serem guardados no vetor:\n");
        for(i = 0; i<qtd; i++){
            scanf("%d", &(*(vetor + i)));
        }
        int temp, j;
        for(j = 0; j < qtd; j++){
            for(i = 0; i<qtd-1; i++){
                if(*(vetor+i) > *(vetor+i+1)){
                    temp = *(vetor+i);
                    *(vetor+i) = *(vetor+i+1);
                    *(vetor+i+1) = temp;
                }
            }
        }
        printf("Vetor Ordenado: ");
        for(i = 0; i<qtd; i++){
            printf("%d ", *(vetor + i));
        }
        printf("\n");
    }
}

int main(){
    int *vetorOrdenado;
    ordenarVetor(vetorOrdenado);

    return 0;
}