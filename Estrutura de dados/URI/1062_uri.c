#include <stdio.h>
int main(){
	int A[1000], B[1000]; //Direções
	int maior; //identificar o maior número que o vagão pode assumir
	int N; //quantidade de vagões
	int num;//numeração do vagão
	int i, j = 0;

	while (1) {
		scanf ("%d", &N);//lê a quantidade de vagões
		if(N == 0){// se 0 encerra
            break;
		}

		while (1) {
			maior = N;//maior número que o vagão pode assumir
			j = 0;

			for (i = 0; i < N; i++) {
				scanf("%d", &num); //recebe a numeração dos vagões
				if(num == 0) { //o número do vagão não pode ser 0
					break;
				}else{
                    A[i] = num; //armazena o número dos vagões chegando na direção A.
				}
			}
			if(num == 0) { // linha em branco que o uri pede ;-;
				printf("\n");
				break;
			}

			for (i = N-1; i >= 0; i--) { //deslocar para direção B
				 if(A[i] == maior) {//se o primeiro da fila é igual ao maior número do vagão decrementa o maior
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
