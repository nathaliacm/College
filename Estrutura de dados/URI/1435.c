#include <stdio.h>

#define LINHAS 100
#define COLUNAS 100

void montaMatriz(int matriz[][COLUNAS], int N);

int main (){

    int i, j, N, matriz[LINHAS][COLUNAS];

    while(scanf("%d", &N), N != 0) {

        montaMatriz(matriz, N);

        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (matriz[i][j] >= 100) {
                    printf("%d", matriz[i][j]);
                }else {
                    printf("% 3d", matriz[i][j]);
                }

                if (j < N - 1) {
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}

void montaMatriz(int matriz[][COLUNAS], int N) {

	    int i,j,k,l=0;
        int valor=1,aux=N;

        for(k = 0; k<N; k++){
            for (i = l; i<aux; i++){
                for (j=l; j<aux; j++){
                    matriz[i][j] = valor;
                }
            }
            valor++;
            l++;
            aux--;
        }
}
