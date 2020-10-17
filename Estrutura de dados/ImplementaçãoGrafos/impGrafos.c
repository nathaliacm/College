#include "grafo.c"

//traçar rota com menor kilometragem com o algoritmo de krussel

int main() {

  int eDigrafo = 0; //nao direcionado
  Grafo *gr;
  gr =  criaGrafo(6, 6, 1); // é ponderado

  insereAresta(gr, 0, 1, eDigrafo, 60);
  insereAresta(gr, 0, 2, eDigrafo, 160);
  insereAresta(gr, 0, 3, eDigrafo, 20);
  insereAresta(gr, 1, 2, eDigrafo, 30);
  insereAresta(gr, 1, 4, eDigrafo, 50);
  insereAresta(gr, 4, 2, eDigrafo, 10);
  insereAresta(gr, 3, 5, eDigrafo, 350);
  insereAresta(gr, 2, 5, eDigrafo, 40);

  int i, pai[6];
  algoritmoKruskal(gr,0,pai);
  printf(" Pai | Vertice\n");
  for(i=0; i<6; i++)
    printf("  %d  :  %d\n",pai[i],i);

  liberaGrafo(gr);

  return 0;
}
