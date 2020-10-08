#include <stdio.h>

int main() {
    int N, menor, posicao;
    int cont;
    scanf("%d",&N);
    int X[N];
    scanf("%d",&X[0]);
    menor = X[0];
    posicao = 0;
    for(cont = 1;cont<N;cont++){
        scanf("%d",&X[cont]);
        if (X[cont]<menor){
            menor = X[cont];
            posicao = cont;
        }
    }
    printf("Menor valor: %d\n",menor);
    printf("Posicao: %d\n",posicao);

return 0;
}
