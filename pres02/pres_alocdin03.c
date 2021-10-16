#include <stdio.h>
#include <stdlib.h>

int main(){
    int numColuna, numFileira;
    int i, j;
    printf("Digite o numero de colunas e fileiras da matriz: ");
    scanf("%d %d", &numColuna, &numFileira);

    int **mat = (int **) calloc(numColuna, sizeof(int *));
    for(i = 0; i < numColuna; i++){
        mat[i] = (int *) calloc(numFileira, sizeof(int));
    }

    printf("\n");

    for(i = 0; i < numColuna; i++){
        for(j = 0; j < numFileira; j++){
            printf("Insira o elemento contido em mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    printf("\nDiagonal Superior: ");

    for(i = 0; i < numColuna; i++){
        printf("%d ", mat[i][i]);
    }

    printf("\n");

    return 0;
}