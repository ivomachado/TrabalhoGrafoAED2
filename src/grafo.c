#include "grafo.h"
#include <stdlib.h>
#include <limits.h>

static int dijkstra(TGrafo *g, unsigned int s, unsigned int dest, int *predecessor)
{
    int i, tam = g->quantidadeVertices(g), visitados = 0;
    int *adjacentes;
    int inf = INT_MAX;
    int *visitado = (int *)(calloc(tam, sizeof(int)));
    int *dist = (int *)(calloc(tam, sizeof(int)));
    int result;
    for (i = 0; i < tam; i++)
    {
        dist[i] = inf;
        predecessor[i] = -1;
    }
    dist[s - 1] = 0;

    while (visitados < tam)
    {
        s = 1;
        for (i = 0; i < tam; i++)
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
    result = dist[dest - 1];
    free(dist);
    free(visitado);
    return result;
}

static int menorDistancia(TGrafo *g, unsigned int s, unsigned int dest)
{
    int *predecessor = (int *)(calloc(g->quantidadeVertices(g), sizeof(int)));
    int result = dijkstra(g, s, dest, predecessor);
    free(predecessor);
    return result;
}

static int *caminhoMenorDistancia(TGrafo *g, unsigned int s, unsigned dest)
{
    int *predecessor = (int *)(calloc(g->quantidadeVertices(g), sizeof(int)));
    int *caminho = (int *)malloc((g->quantidadeVertices(g) * sizeof(int)));
    int i = dest, nArestas = 0;
    dijkstra(g, s, dest, predecessor);
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
    free(predecessor);
    return caminho;
}

TGrafo *criarGrafo()
{
    TGrafo *g = (TGrafo *)malloc(sizeof(TGrafo));
    g->menorDistancia = menorDistancia;
    g->caminhoMenorDistancia = caminhoMenorDistancia;
    return g;
}
