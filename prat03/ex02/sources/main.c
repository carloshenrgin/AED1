#include <stdio.h>
#include <stdlib.h>
#include "..\headers\pontoEsp.h"

int main(){
    float x, y, z, distancia;
    ponto *p[2];
    int i;

    for(i = 0; i < 2; i++){
        printf("Insira (x,y,z) do %do ponto: ", i + 1);
        scanf("%f %f %f", &x, &y, &z);
        p[i] = criaPonto(x, y, z);
    }

    distancia = distPontoTri(p[0], p[1]);

    printf("Distancia entre os pontos: %.2f\n", distancia);

    for(i = 0; i < 2; i++){
        liberaPonto(p[i]);
    }

    return 0;
}