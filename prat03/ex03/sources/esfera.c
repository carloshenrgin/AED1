#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "..\headers\pontoEsp.h"
#include "..\headers\esfera.h"
#define PI 3.14;

struct esfera{
    ponto *p1, *p2;
};

esfera* criaEsfera(ponto *p1, ponto *p2){
    esfera *esf = (esfera *) malloc(sizeof(esfera));
    if(esf == NULL){
        printf("Falha ao criar esfera\n");
    }
    else{
        esf->p1 = p1;
        esf->p2 = p2;
    }
    return esf;
}

void liberaEsfera(esfera *esf){
    free(esf);
}

float raioEsfera(esfera *esf){
    return distPontoTri(esf->p1, esf->p2);
}

float areaEsfera(esfera *esf, float raio){
    return 4.0*(pow(raio,2))*PI;
}

float volumeEsfera(esfera *esf, float raio){
    return ((4.0*(pow(raio,3)))/3.0)*PI;
}