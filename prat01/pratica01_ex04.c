#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fatorial(int n){
    if(n == 0){
        return 1;
    }
    else return n*fatorial(n-1);
}

int combMPaP(int m, int p){
    int resComb = fatorial(m)/(fatorial(p)*fatorial(m-p));
    return resComb;
}

int main(){
    int m, p, resComb;
    printf("Digite M e P para o calc da combinacao de M elementos tomados P a P: ");
    scanf("%d %d", &m, &p);
    resComb = combMPaP(m,p);
    printf("Resultado da Comb: %d\n", resComb);

    return 0;
}