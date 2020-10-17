#include <stdio.h>
#include <stdlib.h>

struct Cartas {
    char carta;
    struct Cartas *prox;
};
typedef struct Cartas TCartas;

struct Fila {
    TCartas *topo, *final;
    int qtd;
};
typedef struct Fila DFila;

int main() {
	int descart[55], N, c = 0, k = 0;
	DFila f;
	TCartas *aux;

	while (scanf("%d", &N) && N != 0){
		k = 0;

		f.topo = NULL;
		f.qtd = 0;

		for(c = N; c > 0; c--){
			aux = (TCartas *) malloc(sizeof(TCartas));

			if(aux == NULL)
				break;

			aux->carta = c;
			aux->prox = f.topo;

			f.topo = aux;
			f.qtd++;

			if(c == N)
				f.final = aux;
		}

		while (f.qtd >= 2)
		{
			aux = f.topo;
			f.topo = aux->prox;
			descart[k] = aux->carta;
			free(aux);
			f.qtd--;
			k++;
			aux = f.topo->prox;
			f.final->prox = f.topo;
			f.final = f.topo;
			f.topo = aux;
		}

		printf("Discarded cards:");
		for(c=0; c < k; c++)
		{
			printf(" %d", descart[c]);
			if(c != k-1)
				printf(",");
		}
		printf("\nRemaining card: %d\n", f.final->carta);
	}

	return 0;
}
