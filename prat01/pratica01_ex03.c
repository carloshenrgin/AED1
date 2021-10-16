#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mediaMax(int *valores){
    int qtd;
    int i;
    double media = 0;
    int numAcima = 0;
    printf("Insira a quantidade de valores: ");
    scanf("%d", &qtd);
    if(qtd <= 15){
        valores = (int *) calloc(qtd, sizeof(int));
        printf("Insira os valores:\n");
        for(i = 0; i<qtd; i++){
            scanf("%d", &(*(valores + i)));
            media = media + *(valores + i);
        }
        media = media/((double) qtd);
        for(i = 0; i<qtd; i++){
            if(*(valores+i)>media){
                numAcima++;
            }
        }
        printf("Dentre os %d numeros digitados existem %d acima da media\n", qtd, numAcima);
    }

}

int main(){
    int *vetor;
    mediaMax(vetor);    

    return 0;
}