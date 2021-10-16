typedef struct ponto Ponto;

Ponto* pto_cria(float x, float y);

void pto_libera(Ponto *p);

float pto_dis(Ponto *p1, Ponto *p2);