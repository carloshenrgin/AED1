#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "..\headers\pontoEsp.h"

struct pontoEsp{
    float x, y, z;
};

ponto* criaPonto(float x, float y, float z){
    ponto *p = (ponto *) malloc(sizeof(ponto));
    if(p == NULL){
        printf("Falha na criacao do ponto\n");
    }
    else{
        p->x = x;
        p->y = y;
        p->z = z;
    }
    return p;
}

void liberaPonto(ponto *p){
    free(p);
}

float distPontoTri(ponto *p1, ponto *p2){
    return sqrt(pow((p1->x - p2->x),2) + pow((p1->y - p2->y),2) + pow((p1->z - p2->z),2));
}