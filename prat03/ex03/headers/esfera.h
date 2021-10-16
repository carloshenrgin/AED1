#ifndef ESFERA
#define ESFERA
typedef struct esfera esfera;

esfera* criaEsfera(ponto *p1, ponto *p2);

void liberaEsfera(esfera *esf);

float raioEsfera(esfera *esf);

float areaEsfera(esfera *esf, float raio);

float volumeEsfera(esfera *esf, float raio);

#endif