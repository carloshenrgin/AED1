#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main(){
    float distancia;
    float x1, x2, y1, y2;
    Ponto *p1, *p2;

    printf("Digite as coordenadas x e y do ponto P1: ");
    scanf("%f %f", &x1, &y1);

    printf("Digite as coordenadas x e y do ponto P2: ");
    scanf("%f %f", &x2, &y2);

    p1 = pto_cria(x1,y1);
    p2 = pto_cria(x2,y2);
    
    distancia = pto_dis(p1,p2);

    printf("Distancia entre os pontos p1 = (%.2f, %.2f) e p2 = (%.2f, %.2f): %.2f\n", x1, y1, x2, y2, distancia);
    pto_libera(p1);
    pto_libera(p2);

    return 0;
}