#include <stdio.h>
#include <stdlib.h>
#include "..\header\complexos.h"

int main(){
    float a, b;
    numComplexo *num[3], *resultado;
    int i;

    for(i = 0; i < 3; i++){
        printf("Digite a parte real e a parte imaginaria do %do numero complexo: ", i+1);
        scanf("%f %f", &a, &b);
        num[i] = cria_nro(a, b);
    }

    printf("\n");

    resultado = mult(sub(num[0], num[2]), num[1]);

    printf("Resultado da expressao (C1 - C3)*C2: ");
    mostrarComplexo(resultado);

    for(i = 0; i < 3; i++){
        libera_nro(num[i]);
    }

    libera_nro(resultado);

    return 0;
}