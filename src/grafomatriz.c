#include "grafo.h"
#include <stdlib.h>

typedef struct dadoGrafo TDadoGrafoAdjacencia;

struct dadoGrafo
{
    unsigned int tam;
    int **matriz;
    int nVertices;
    int nArestas;
};

static short verificaAdjacencia(TGrafo *g, unsigned int u, unsigned int v)
{
    TDadoGrafoAdjacencia *d = (TDadoGrafoAdjacencia *)g->dado;
    return d->matriz[(u - 1) * d->tam + v - 1] != 0;
}

static void addAresta(TGrafo *g, unsigned int u, unsigned int v)
{
    TDadoGrafoAdjacencia *d = (TDadoGrafoAdjacencia *)g->dado;
    d->matriz[(u - 1) * d->tam + v - 1] = 1;
}

static void addArestaPonderada(TGrafo *g, unsigned int u, unsigned int v, int peso)
{
    TDadoGrafoAdjacencia *d = (TDadoGrafoAdjacencia *)g->dado;
    d->matriz[(u - 1) * d->tam + v - 1] = peso;
}

static TDadoGrafoAdjacencia *criarDado(int tam)
{
    TDadoGrafoAdjacencia *d = (TDadoGrafoAdjacencia *)malloc(sizeof(TDadoGrafoAdjacencia));
    d->matriz = (int **)calloc(tam * tam, sizeof(int));
    d->tam = tam;
    d->nArestas = 0;
    d->nVertices = 0;
    return d;
}

TGrafo *criarGrafoAdjacencia(int tam)
{
    TGrafo *g = (TGrafo *)malloc(sizeof(TGrafo));
    g->dado = criarDado(tam);
    g->addAresta = addAresta;
    g->addArestaPonderada = addArestaPonderada;
    g->verificaAdjacencia = verificaAdjacencia;
    return g;
}
