#include <stdio.h>

#define SIZE 1001

void imprimeArray(int arr[SIZE], int filaSize);
void selectionSort(int arr[SIZE], int nAlunos);
void swap(int *xp, int *yp);
void inverteVetor(int arr[], int n);

int main(){

	int N, nAlunos, i, flag;
	int notas[SIZE], posicaoInicial[SIZE], notasOrdenadas[SIZE];

	scanf("%d", &N);
	while(N-- > 0){

		scanf("%d", &nAlunos);

		for(i = 0; i < nAlunos; i++){
			scanf("%d", &notas[i]);
			posicaoInicial[i] = notas[i];
		}

		selectionSort(notas, nAlunos);
		inverteVetor(notas, nAlunos);
		//imprimeArray(notas, nAlunos);
		flag = 0;

		for(i = 0; i < nAlunos; i++){

			if(notas[i] == posicaoInicial[i])
				flag++;
		}
		printf("%d\n", flag);
	}
	return 0;
}

void imprimeArray(int arr[SIZE], int filaSize){

    int i;

	for(i = 0; i < filaSize; i++)
		printf("|%d| ", arr[i]);
}

void swap(int *xp, int *yp){
    int aux = *xp;
    *xp = *yp;
    *yp = aux;
}

void selectionSort(int arr[], int n){
    int i, j, posicaoMenorValor;

    for (i = 0; i < n-1; i++){

        posicaoMenorValor = i;

        for (j = i+1; j < n; j++)

        	if(arr[j] < arr[posicaoMenorValor])
        		posicaoMenorValor = j;

        swap(&arr[posicaoMenorValor], &arr[i]);
    }
}

void inverteVetor(int arr[], int n){

    int i, j, aux, inverso[n];

    for (i=0; i < n; i ++)
        inverso[n - i - 1] = arr[i];

    for(i = 0; i < n; i++)
        arr[i] = inverso[i];
}
