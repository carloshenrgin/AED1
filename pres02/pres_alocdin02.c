#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int tamanhoStg, i;

    printf("Digite o tamanho da string: ");
    scanf("%d", &tamanhoStg);
    char *contStg = (char *) calloc((tamanhoStg+1), sizeof(char));

    setbuf(stdin, NULL);
    printf("\nDigite o conteudo da string: ");
    fgets(contStg, tamanhoStg+1, stdin);
    if(contStg[strlen(contStg) - 1] == '\n'){
        contStg[strlen(contStg) - 1] = '\0';
    }
    setbuf(stdin, NULL); 
    
    printf("\nString sem as vogais: ");
    for(i = 0; i< tamanhoStg; i++){
        if((contStg[i] != 'a') && (contStg[i] != 'e') && (contStg[i] != 'i') && (contStg[i] != 'o') && (contStg[i] != 'u') && (contStg[i] != 'A') && (contStg[i] != 'E') && (contStg[i] != 'I') && (contStg[i] != 'O') && (contStg[i] != 'U')){
            printf("%c", contStg[i]);
        }
    }

    printf("\n");


    return 0;
}