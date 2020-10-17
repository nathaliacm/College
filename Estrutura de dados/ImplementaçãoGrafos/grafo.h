typedef struct grafo Grafo;

Grafo *criaGrafo(int nVertices, int grauMax, int ePonderado);
void liberaGrafo(Grafo* gr);
int insereAresta(Grafo* gr, int origem, int destino,int eDigrafo, float peso);
int removeAresta(Grafo* gr, int origem, int destino, int eDigrafo);
void buscaProfundidadeGrafo(Grafo *gr, int inicial, int *visitado);
void buscaLarguraGrafo(Grafo *gr, int inicial, int *visitado);
void menorCaminhoGrafo(Grafo *qr, int inicial, int *anterior, float *distancia);
void algoritmoKruskal(Grafo *gr, int origem, int *pai);
