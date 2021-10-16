#ifndef PONTO
#define PONTO
typedef struct pontoEsp ponto;

ponto* criaPonto(float x, float y, float z);

void liberaPonto(ponto *p);

float distPontoTri(ponto *p1, ponto *p2);

#endif