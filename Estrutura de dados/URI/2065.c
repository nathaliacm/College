#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario{
		int processamento;
		int tempo;
		int id;
} funcionario;

typedef struct {
	funcionario * A;
	int tamanhoAtual;
} ARVORE;


void inicializarArvore(ARVORE * h, int tamanhoMax){
	h->A = (funcionario*) malloc(sizeof(funcionario)*(tamanhoMax+1));
	h->tamanhoAtual = 0;
}

int filhoEsquerda(int i){
	return 2*i;
}

int filhoDireita(int i){
	return 2*i + 1;
}

void minArvore(ARVORE * h, int i){
	int esq = filhoEsquerda(i);
	int dir = filhoDireita(i);
	int aux[3];
	int menor = i;
	if (((esq <= h->tamanhoAtual) && (h->A[esq].tempo < h->A[i].tempo)) || ((esq <= h->tamanhoAtual) && (h->A[esq].tempo == h->A[i].tempo) && (h->A[esq].id < h->A[i].id)))
		menor = esq;
	if (((dir <= h->tamanhoAtual) && (h->A[dir].tempo < h->A[menor].tempo)) || ((dir <= h->tamanhoAtual) && (h->A[dir].tempo == h->A[menor].tempo) && (h->A[dir].id < h->A[menor].id)))
		menor = dir;
	if (menor != i) {
		aux[0] = h->A[i].tempo;
		aux[1] = h->A[i].processamento;
		aux[2] = h->A[i].id;
		h->A[i].tempo = h->A[menor].tempo;
		h->A[i].processamento = h->A[menor].processamento;
		h->A[i].id = h->A[menor].id;
		h->A[menor].tempo = aux[0];
		h->A[menor].processamento = aux[1];
		h->A[menor].id = aux[2];
		minArvore(h,menor);
	}
}

void inserir(ARVORE * h, int id,int processamento){
		(h->tamanhoAtual)++;
		h->A[h->tamanhoAtual].tempo = 0;
		h->A[h->tamanhoAtual].id = id;
		h->A[h->tamanhoAtual].processamento = processamento;
		return;
}

void atendimento(ARVORE *h, int i)
{
	h->A[1].tempo =(h->A[1].processamento * i) + h->A[1].tempo;
	minArvore(h,1);
}

void tempo(ARVORE h)
{
	int i, maior=0;
	for (i=1; i<=h.tamanhoAtual; i++) {
		if(h.A[i].tempo>maior)
			maior=h.A[i].tempo;
	}
	printf("%i\n", maior);
}

int main(){

	int n, m, k, i;
	scanf("%i %i", &n, &m);

	ARVORE arvore;
	inicializarArvore(&arvore, n);

	for(i=1; i<n+1; i++) {
		scanf("%i",&k);
		inserir(&arvore, i, k);
	}

	for(i=1; i<m+1; i++) {
		scanf("%i",&k);
		atendimento(&arvore, k);
	}

	tempo(arvore);
}
