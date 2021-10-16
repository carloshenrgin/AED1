#include <stdio.h>
#include <string.h>
#include "tad.h"

int main(){
    list lista = criaLista();

    struct bebida input;
    char nome[20];
    float p;
    int v;
    int retorno;

    int i;
    for(i = 0; i < 4; i++){
        setbuf(stdin, NULL);
        fgets(nome, 21, stdin);
        nome[strlen(nome) - 1] = '\0';
        strcpy(input.bebida, nome);
        scanf("%f", &p);
        input.preco = p;
        scanf("%d", &v);
        input.vol = v;
        retorno = insereBebida(lista, input);
        if(retorno == 0){
            printf("Falha\n");
        }
        else printf("Sucesso\n");
    }

    strcpy(input.bebida, "coca");
    input.vol = 2000;

    removeBebida(lista, input);

    for(i = 0; i < 4; i++){
        printf("%s, %d, %.2f\n", lista->bebidas[i].bebida, lista->bebidas[i].vol, lista->bebidas[i].preco);
    }

    return 0;
}