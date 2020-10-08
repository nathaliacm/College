#include <stdio.h>

int main() {

    double M[12][12];
    int C;
    int i,j;
    char T[5];
    double soma = 0.0;

    scanf("%d",&C);
    scanf("%s",&T);

    for (i=0;i<12;i++){
        for(j=0;j<12;j++){
            scanf("%lf",&M[i][j]);
        }
    }
    for (i=0;i<12;i++){
        soma+=M[i][C];
    }
    if (T[0] == 'M'){
        soma = soma/12.0;
    }
    printf("%.1lf\n",soma);

    return 0;
}
