#include <stdio.h>
int main(){
	int A[1000], B[1000]; //Dire��es
	int maior; //identificar o maior n�mero que o vag�o pode assumir
	int N; //quantidade de vag�es
	int num;//numera��o do vag�o
	int i, j = 0;

	while (1) {
		scanf ("%d", &N);//l� a quantidade de vag�es
		if(N == 0){// se 0 encerra
            break;
		}

		while (1) {
			maior = N;//maior n�mero que o vag�o pode assumir
			j = 0;

			for (i = 0; i < N; i++) {
				scanf("%d", &num); //recebe a numera��o dos vag�es
				if(num == 0) { //o n�mero do vag�o n�o pode ser 0
					break;
				}else{
                    A[i] = num; //armazena o n�mero dos vag�es chegando na dire��o A.
				}
			}
			if(num == 0) { // linha em branco que o uri pede ;-;
				printf("\n");
				break;
			}

			for (i = N-1; i >= 0; i--) { //deslocar para dire��o B
				 if(A[i] == maior) {//se o primeiro da fila � igual ao maior n�mero do vag�o decrementa o maior
				 	maior--;
				 }else{
				 	B[j++] = A[i];
				 }
				while (j > 0) {
				 	if(B[j-1] == maior) {
				 		j--;
				 		maior--;
				 	}else{
				 		break;
				 	}
				}
			}

			if (maior == 0) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
		}
	}
	return 0;
}
