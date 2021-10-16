#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct ponto{
    float x,y;
};

Ponto* pto_cria(float x, float y){
    Ponto *p = (Ponto *) malloc(sizeof(Ponto));
    if(p != NULL){
        p->x = x;
        p->y = y;
    }
    return p;
}

void pto_libera(Ponto *p){
    free(p);
}


float pto_dis(Ponto *p1, Ponto *p2){
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    return sqrt(dx*dx + dy*dy);
}