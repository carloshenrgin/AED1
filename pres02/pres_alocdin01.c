#include <stdio.h>
#include <stdlib.h>

int main(){
    int tamanhoVet, i, somaImpar = 0;
    printf("Digite quantas casas serao alocadas para o vetor: ");
    scanf("%d", &tamanhoVet);
    int *vet = (int *) calloc(tamanhoVet, sizeof(int));
    for(i = 0; i < tamanhoVet; i++){
        printf("Digite o %do elemento do vetor: ", i+1);
        scanf("%d", &vet[i]);
        if(vet[i]%2 != 0){
            somaImpar += vet[i];
        }
    }

    printf("\n");

    for(i = 0; i < tamanhoVet; i++){
        printf("%do elemento do vetor: %d\n", i+1, vet[i]);
        if(i == tamanhoVet - 1){
            printf("\nSoma dos elementos impares do vetor: %d\n", somaImpar);
        }
    }

    free(vet);

    return 0;
}