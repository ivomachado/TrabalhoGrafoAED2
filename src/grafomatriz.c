#include "grafomatriz.h"
#include <stdlib.h>

typedef struct dadoGrafo TDadoGrafoAdjacencia;

struct dadoGrafo
{
    int *matriz;
    unsigned int nVertices;
    unsigned int nArestas;
};

static short verificaAdjacencia(TGrafo *g, unsigned int u, unsigned int v)
{
    TDadoGrafoAdjacencia *d = (TDadoGrafoAdjacencia *)g->dado;
    return d->matriz[(u - 1) * d->nVertices + v - 1] != 0;
}

static void addAresta(TGrafo *g, unsigned int u, unsigned int v)
{
    TDadoGrafoAdjacencia *d = (TDadoGrafoAdjacencia *)g->dado;
    d->nArestas++;
    d->matriz[(u - 1) * d->nVertices + v - 1] = 1;
}

static void addArestaPonderada(TGrafo *g, unsigned int u, unsigned int v, int peso)
{
    TDadoGrafoAdjacencia *d = (TDadoGrafoAdjacencia *)g->dado;
    if(peso != 0) {
        if(g->valorAresta(g, u, v) == 0) {
            d->nArestas++;
        }
    } else {
        if(g->valorAresta(g, u, v) != 0) {
            d->nArestas--;
        }
    }
    d->matriz[(u - 1) * d->nVertices + v - 1] = peso;
}

static int valorAresta(TGrafo *g, unsigned int u, unsigned int v) {
    TDadoGrafoAdjacencia *d = (TDadoGrafoAdjacencia *)g->dado;
    return d->matriz[(u - 1) * d->nVertices + v - 1];
}

static int quantidadeArestas(TGrafo *g) {
    TDadoGrafoAdjacencia *d = (TDadoGrafoAdjacencia *)g->dado;
    return d->nArestas;
}

static int quantidadeVertices(TGrafo *g) {
    TDadoGrafoAdjacencia *d = (TDadoGrafoAdjacencia *)g->dado;
    return d->nVertices;
}

static int quantidadeAdjacentes(TGrafo *g, unsigned int u) {
    TDadoGrafoAdjacencia *d = (TDadoGrafoAdjacencia *)g->dado;
    int i, nAdjacentes = 0;
    for(i = 0; i < d->nVertices; i++) {
        if(d->matriz[(u-1)*d->nVertices + i] != 0) nAdjacentes++;
    }
    return nAdjacentes;
}

static int * adjacentes(TGrafo *g, unsigned int u) {
    TDadoGrafoAdjacencia *d = (TDadoGrafoAdjacencia *)g->dado;
    int i, *adjacentes = (int*)malloc(d->nVertices*sizeof(int) + 1);
    int k = 0;
    for(i = 0; i < d->nVertices; i++) {
        if(d->matriz[(u-1)*d->nVertices + i] != 0) adjacentes[k++] = i + 1;
    }
    adjacentes[k] = -1;
    return adjacentes; 
}

static TDadoGrafoAdjacencia *criarDado(int nVertices)
{
    TDadoGrafoAdjacencia *d = (TDadoGrafoAdjacencia *)malloc(sizeof(TDadoGrafoAdjacencia));
    d->matriz = (int *)calloc(nVertices * nVertices, sizeof(int));
    d->nVertices = nVertices;
    d->nArestas = 0;
    d->nVertices = nVertices;
    return d;
}

TGrafo *criarGrafoAdjacencia(int nVertices)
{
    TGrafo *g = criarGrafo();
    g->dado = criarDado(nVertices);
    g->addAresta = addAresta;
    g->addArestaPonderada = addArestaPonderada;
    g->verificaAdjacencia = verificaAdjacencia;
    g->valorAresta = valorAresta;
    g->adjacentes = adjacentes;
    g->quantidadeAdjacentes = quantidadeAdjacentes;
    g->quantidadeArestas = quantidadeArestas;
    g->quantidadeVertices = quantidadeVertices;
    return g;
}
