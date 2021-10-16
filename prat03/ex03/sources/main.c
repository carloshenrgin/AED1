#include <stdio.h>
#include "..\headers\pontoEsp.h"
#include "..\headers\esfera.h"

int main(){
    float x, y, z;
    int i;
    ponto *p[2];
    esfera *esf;

    printf("Digite as coordenadas do centro e de um ponto qualquer na superficie da esfera\n");
    for(i = 0; i < 2; i++){
        printf("Inserir: ");
        scanf("%f %f %f", &x, &y, &z);
        p[i] = criaPonto(x,y,z);
    }

    esf = criaEsfera(p[0], p[1]);

    float raio, area, volume;

    raio =  raioEsfera(esf);
    area = areaEsfera(esf, raio);
    volume = volumeEsfera(esf, raio);

    printf("Raio da esfera: %.2f\n", raio);
    printf("Area da esfera: %.2f\n", area);
    printf("Volume da esfera: %.2f\n", volume);

    for(i = 0; i < 2; i++){
        liberaPonto(p[i]);
    }

    liberaEsfera(esf);

    return 0;
}