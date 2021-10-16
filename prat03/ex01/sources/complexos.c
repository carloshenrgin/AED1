#include <stdlib.h>
#include <stdio.h>
#include "..\header\complexos.h"

struct complexo{
    float parteReal, parteImg;
};

numComplexo* cria_nro(float a, float b){
    numComplexo *i = (numComplexo*) malloc(sizeof(numComplexo));
    if(i == NULL){
        printf("Falha na criacao do numero complexo\n");
    }
    else{
        i->parteReal = a;
        i->parteImg = b;
    }
    return i;
}

void libera_nro(numComplexo *i){
    free(i);
}

numComplexo* soma(numComplexo *i1, numComplexo *i2){
    numComplexo *soma =  cria_nro(0,0);
    soma->parteReal = i1->parteReal + i2->parteReal;
    soma->parteImg = i1->parteImg + i2->parteImg;
    return soma;
}

numComplexo* sub(numComplexo *i1, numComplexo *i2){
    numComplexo *sub =  cria_nro(0,0);
    sub->parteReal = i1->parteReal - i2->parteReal;
    sub->parteImg = i1->parteImg - i2->parteImg;
    return sub;
}

numComplexo* mult(numComplexo *i1, numComplexo *i2){
    numComplexo *mult =  cria_nro(0,0);
    mult->parteReal = (i1->parteReal)*(i2->parteReal) + (i1->parteImg)*(i2->parteImg)*(-1);
    mult->parteImg = (i1->parteReal)*(i2->parteImg) + (i1->parteImg)*(i2->parteReal);
    return mult;
}

void mostrarComplexo(numComplexo *i){
    printf("%.2f + (%.2f)i\n", i->parteReal, i->parteImg);
}