#include "grafo.h"
#include <stdlib.h>
#include <limits.h>

static void dijkstra(TGrafo *g, unsigned int s, int *dist, int *predecessor)
{
    int i, visitados = 0;
    int *adjacentes;
    int inf = INT_MAX;
    int *visitado = (int *)(calloc(g->quantidadeVertices(g), sizeof(int)));
    for (i = 0; i < g->quantidadeVertices(g); i++)
    {
        dist[i] = inf;
        predecessor[i] = -1;
    }
    dist[s - 1] = 0;

    while (visitados < g->quantidadeVertices(g))
    {
        s = 1;
        for (i = 0; i < g->quantidadeVertices(g); i++)
        {
            if (visitado[s - 1] || (!visitado[i] && dist[s - 1] > dist[i]))
            {
                s = i + 1;
            }
        }
        visitado[s - 1] = 1;
        visitados++;
        adjacentes = g->adjacentes(g, s);
        i = 0;
        while (adjacentes[i] > 0)
        {
            if (dist[adjacentes[i] - 1] > dist[s - 1] + g->valorAresta(g, s, adjacentes[i]))
            {
                dist[adjacentes[i] - 1] = dist[s - 1] + g->valorAresta(g, s, adjacentes[i]);
                predecessor[adjacentes[i] - 1] = s;
            }
            i++;
        }
        free(adjacentes);
    }
    free(visitado);
}

static int menorDistancia(TGrafo *g, unsigned int s, unsigned int dest)
{
    int *predecessor = (int *)(calloc(g->quantidadeVertices(g), sizeof(int)));
    int *dist = (int *)(calloc(g->quantidadeVertices(g), sizeof(int)));
    int result;
    dijkstra(g, s, dist, predecessor);
    result = dist[dest - 1];
    free(predecessor);
    free(dist);
    return result;
}

static int * todasMenoresDistancias(TGrafo *g, unsigned int s) {
    int *predecessor = (int *)(calloc(g->quantidadeVertices(g), sizeof(int)));
    int *dist = (int *)(calloc(g->quantidadeVertices(g), sizeof(int)));
    dijkstra(g, s, dist, predecessor);
    free(predecessor);
    return dist;
}

static int * menorCaminhoDistanciaComPredecessor(TGrafo *g, unsigned int s, unsigned dest, int * predecessor) {
    int *caminho = (int *)malloc((g->quantidadeVertices(g) * sizeof(int)));
    int i = dest, nArestas = 0;
    while (predecessor[i - 1] != -1)
    {
        nArestas++;
        i = predecessor[i - 1];
    }
    i = dest;
    caminho[nArestas + 1] = -1;
    caminho[nArestas--] = dest;
    for (; nArestas >= 0; nArestas--)
    {
        i = caminho[nArestas] = predecessor[i - 1];
    }
    return caminho;
}

static int *caminhoMenorDistancia(TGrafo *g, unsigned int s, unsigned dest)
{
    int *predecessor = (int *)(calloc(g->quantidadeVertices(g), sizeof(int)));
    int *dist = (int *)(calloc(g->quantidadeVertices(g), sizeof(int)));
    int *caminho;
    dijkstra(g, s, dist, predecessor);
    caminho = menorCaminhoDistanciaComPredecessor(g,s,dest,predecessor);
    free(predecessor);
    free(dist);
    return caminho;
}

TGrafo *criarGrafo()
{
    TGrafo *g = (TGrafo *)malloc(sizeof(TGrafo));
    g->menorDistancia = menorDistancia;
    g->caminhoMenorDistancia = caminhoMenorDistancia;
    g->todasMenoresDistancias = todasMenoresDistancias;
    return g;
}
