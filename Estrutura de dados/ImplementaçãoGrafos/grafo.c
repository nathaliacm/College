#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

struct grafo {
    int ePonderado;
    int nVertices;
    int grauMax;
    int** arestas;
    float** pesos;
    int* grau;
};

Grafo* criaGrafo(int nVertices, int grauMax, int ePonderado) {
    Grafo *gr = (Grafo*) malloc(sizeof(struct grafo));
    if(gr!=NULL) { // se n�o houve erro na aloca��o
        int i;
        //pegando os paramentros e guardando na estrutura
        gr->nVertices = nVertices;
        gr->grauMax = grauMax;
        gr->ePonderado = (ePonderado!=0)?1:0; // se � ponderado faz uma verfica��o pra garantir valores sempre 0 e 1
        gr->grau = (int*)calloc(nVertices, sizeof(int)); //criando vetor de grau calloc pois inicialmente cada vertice tem grau 0
        //criando a matriz de arestas
        gr->arestas = (int**)malloc(nVertices*sizeof(int*));
        for(i=0; i<nVertices; i++)
            gr->arestas[i] = (int*)malloc(grauMax*sizeof(int)); // para cada vertice criando o grau maximo dele
            if (gr->ePonderado) { // se o grafo for ponderado faz a mesma coisa pra matriz de pesos
                gr->pesos = (float**)malloc(nVertices*sizeof(float*));
                for(i=0; i<nVertices; i++)
                    gr->pesos[i] = (float*)malloc(grauMax*sizeof(float));
            }
    }
    return gr;
}

void liberaGrafo(Grafo* gr) {
    if(gr!=NULL) {
        int i;
        //libera matriz de arestas
        for (i=0; i<gr->nVertices; i++)
            free(gr->arestas[i]);
        free(gr->arestas);
        //libera matriz de pesos
        if(gr->ePonderado) {
            for(i=0; i<gr->nVertices; i++)
                free(gr->pesos[i]);
        }
        free(gr->grau);
        free(gr);
    }
}

int insereAresta(Grafo* gr, int origem, int destino, int eDigrafo, float peso) {
    if(gr == NULL)
        return 0;
    //verfica se v�rtice existe
    if(origem < 0 || origem >= gr->nVertices)
        return 0;
    if(destino < 0 || destino >= gr->nVertices)
        return 0;

    gr->arestas[origem][gr->grau[origem]] = destino;
    if (gr->ePonderado)
        gr->pesos[origem][gr->grau[origem]] = peso;
    gr->grau[origem]++;

    if(eDigrafo == 0) //insere outra aresta se n�o for digrafo
        insereAresta(gr,destino,origem,1,peso);
    return 1;
}

int removeAresta(Grafo* gr, int origem, int destino, int eDigrafo) {
    if(gr == NULL)
        return 0;
    //verifica se o v�rtice existe
    if(origem < 0 || origem >= gr->nVertices)
        return 0;
    if(destino < 0 || destino >= gr->nVertices)
        return 0;

    //procura aresta
    int i = 0;
    //dentro da quantidade de arestas no vertice origem
    //se existe na posi��o i
    //se a iesima aresta � igual ao destino
    //enquanto for diferente avan�a arestas
    while(i < gr->grau[origem] && gr->arestas[origem][i] != destino)
        i++;

    if(i == gr->grau[origem]) //elemento n�o encontrado
        return 0;

    gr->grau[origem]--; //decremento aresta
    gr->arestas[origem][i] = gr->arestas[origem][gr->grau[origem]]; //coloca a ultima aresta na posi��o i
    if(gr->ePonderado)
        gr->pesos[origem][i] = gr->pesos[origem][gr->grau[origem]];
    if(eDigrafo == 0) //remove outra aresta se n�o for digrafo
        removeAresta(gr, destino, origem, 1);
    return 1;
}

//Arvore Geradora Minima
//Consiste em encontrar o conjuto de arestas de menor custo que conecte todos os v�rtices
//de um grafo
//� a menor estrutura que conecta todos os vertices do grafo.

//Algoritmo de kruskal
//calcula a arvore geradora minima de um grafo
void algoritmoKruskal(Grafo *gr, int origem, int *pai) {
    int i,j,dest,primeiro,nVertices = gr->nVertices;
    double menorPeso;
    int *arvore = (int*)malloc(nVertices * sizeof(int));
    for(i=0; i < nVertices; i++) {
        arvore[i] = i;
        pai[i] = -1;//sem pai
    }
    pai[origem] = origem;
    while(1) {
        primeiro = 1;
        for(i=0; i<nVertices; i++) {//percorre os vertices
            for(j=0; j<gr->grau[i]; j++) { //arestas
                //procura vertice menor peso
                if(arvore[i] != arvore[gr->arestas[i][j]]) {
                    if(primeiro) {
                        menorPeso = gr->pesos[i][j];
                        origem = i;
                        dest = gr->arestas[i][j];
                        primeiro = 0;
                    } else {
                        if(menorPeso > gr->pesos[i][j]) {
                            menorPeso = gr->pesos[i][j];
                            origem = i;
                            dest = gr->arestas[i][j];
                        }
                    }
                }
            }
        }
        if(primeiro == 1) {
            break;
        }
        if(pai[origem] == -1){
            pai[origem] = dest;
        } else {
            pai[dest] = origem;
        }
        //todo mundo parte da mesma arvore
        for(i=0; i<nVertices; i++) {
            if(arvore[i] == arvore[dest]) { //toda arvore i = dest passa a fazer parte da origem
                arvore[i] = arvore[origem];
            }
        }
    }
}

//Parte do modelo de grafos n�o utilizada na implementa��o

//----------------------------------------------------------------------------------

//Busca em profundidade
//Partindo de um v�rtice inicial, ela explora o m�ximo possivel
//cada um dos seus ramos antes de retorceder
//realiza o calculo
void buscaProfundidade(Grafo *gr, int inicial, int *visitado, int cont) {
    int i;
    visitado[inicial] = cont; //marca o vertice como visitado
    //marca o v�rtice como visitado. Visita os vizinhos ainda n�o visitados
    for(i=0; i<gr->grau[inicial]; i++) {
        if(!visitado[gr->arestas[inicial][i]])
            buscaProfundidade(gr, gr->arestas[inicial][i], visitado, cont+1);
    }
}
//Faz a interface com o usu�rio
void buscaProfundidadeGrafo(Grafo *gr, int inicial, int *visitado) {
    int i, cont = 1;
    //marca v�rtices como n�o visitados
    for(i=0; i<gr->nVertices; i++)
        visitado[i] = 0;
    buscaProfundidade(gr, inicial, visitado, cont);
}

//busca em largura
//Psrtindo de um v�rtice inicial, ela explora todos os v�rtices vizinhos.
//Em seguida, para cada v�rtice vizinho, ela repete esse processo,
//visitando os v�rtices ainda inexplorados
// pode ser usado para achar o menor caminho entre dois v�rtices

void buscaLarguraGrafo(Grafo *gr, int inicial, int *visitado) {
    int i, vertice, nVertices, cont = 1, *fila, inicioFila = 0, finalFila = 0;
    //Marca v�rtices como n�o visitados
    for(i=0; i<gr->nVertices; i++)
        visitado[i] = 0;
    nVertices = gr->nVertices;
    //fila pra guardar a ordem que visitei os vertices
    fila = (int*)malloc(nVertices *sizeof(int));
    finalFila++;//incrementa 1 no final da fila
    fila[finalFila] = inicial; //coloca o vertice inicial no final da fila
    visitado[inicial] = cont; // e marca o vertice inicial como visitado
    while(inicioFila != finalFila) { //enquanto a fila n�o estiver vazia
        //pega o primeiro da fila
        inicioFila = (inicioFila + 1) % nVertices;
        vertice = fila[inicioFila];
        cont++;
    //visita os vizinhos ainda n�o visitados e coloca na fila
        for(i=0; i<gr->grau[vertice]; i++) {
            if(!visitado[gr->arestas[vertice][i]]) {
                finalFila = (finalFila + 1) % nVertices;
                fila[finalFila] = gr->arestas[vertice][i];
                visitado[gr->arestas[vertice][i]] = cont;
            }
        }
    }
    //libera o espa�o do auxiliar criado pra fila
    free(fila);
}

//Busca pelo menor caminho
//Partindo de um vertice inicial, calcula a menor distancia
//desse vertice a todos os demais (desde que exista um caminho entre eles)
int procuraMenorDistancia(float *distancia, int *visitado, int nVertices) {
    int i, menor = -1, primeiro = 1;
    for(i=0; i<nVertices; i++) {
        //procura vertice com maior distancia que n�o tenha sido visitado
        if(distancia[i] >= 0 && visitado[i] == 0) {
            if(primeiro) {
                menor = i;
                primeiro = 0;
            } else {
                if(distancia[menor] > distancia[i])
                    menor = i;
            }
        }
    }
    return menor;
}

void menorCaminhoGrafo(Grafo *gr, int inicial, int *anterior, float *distancia) {
    int i, cont, nVertices, ind, *visitado, u;
    cont = nVertices = gr->nVertices;
    //cria vetor auxiliar. Inicializa distancia e anteriores
    visitado = (int*)malloc(nVertices * sizeof(int));
    for(i=0; i<nVertices; i++) {
        anterior[i] = -1;
        distancia[i] = -1;
        visitado[i] = 0;
    }
    distancia[inicial] = 0;
    while(cont > 0) {
        //procura vertice com menor distancia e marca como visitado
        u = procuraMenorDistancia(distancia,visitado,nVertices);
        if(u == -1) {
            break;
        }
        visitado[u] = 1;
        cont--;
        for(i=0; i<gr->grau[u]; i++) { //para cada vertice sozinho
            ind = gr->arestas[u][i];
            //atualizar distancia dos vizinhos
            if(distancia[ind] < 0) { //considerando a distancia o numero de vertices pra passa por alguem
                distancia[ind] = distancia[u] + 1;
                //ou peso da aresta
                //dist[ind] = dist[u] + gr->pesos[u][i];
                anterior[ind] = u;
            } else {
                if(distancia[ind] > distancia[u] +1) {
                //ou peso da aresta
                    distancia[ind] = distancia[u] + 1;
                    anterior[ind] = u;
                }
            }
        }
    }
    free(visitado);
}






