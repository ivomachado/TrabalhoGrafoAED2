#include "grafo.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

static void dijkstra(TGrafo *g, int s, int *dist, int *predecessor)
{
    int i, visitados = 0, tam = g->quantidadeVertices(g);
    int *adjacentes;
    int *visitado = (int *)(calloc(tam, sizeof(int)));
    for (i = 0; i < tam; i++)
    {
        dist[i] = INT_MAX;
        predecessor[i] = -1;
    }
    dist[s - 1] = 0;

    while (visitados < tam)
    {
        s = 0;
        while(visitado[s] && s < tam) {
            s++;
        }
        s++;
        for (i = s; i <= tam; i++)
        {
            if (!visitado[i - 1] && dist[s - 1] > dist[i - 1])
            {
                s = i;
            }
        }
        visitado[s - 1] = 1;
        visitados++;
        adjacentes = g->adjacentes(g, s);
        i = 1;
        while (adjacentes[i - 1] != -1)
        {
            if (dist[adjacentes[i - 1] - 1] > dist[s - 1] + g->valorAresta(g, s, adjacentes[i - 1]))
            {
                dist[adjacentes[i - 1] - 1] = dist[s - 1] + g->valorAresta(g, s, adjacentes[i - 1]);
                predecessor[adjacentes[i - 1] - 1] = s;
            }
            i++;
        }
        free(adjacentes);
    }
    free(visitado);
}

static int menorDistancia(TGrafo *g, int s, int dest)
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

static int *todasMenoresDistancias(TGrafo *g, int s)
{
    int *predecessor = (int *)(calloc(g->quantidadeVertices(g), sizeof(int)));
    int *dist = (int *)(calloc(g->quantidadeVertices(g), sizeof(int)));
    dijkstra(g, s, dist, predecessor);
    free(predecessor);
    return dist;
}

static int *caminhoMenorDistanciaComPredecessor(TGrafo *g, int s, int dest, int *predecessor)
{
    int *caminho = (int *)malloc((g->quantidadeVertices(g) * sizeof(int)));
    int i = dest, nArestas = 0;
    while (predecessor[i - 1] != -1)
    {
        nArestas++;
        i = predecessor[i - 1];
    }
    if(i == s) {
        i = dest;
        caminho[nArestas + 1] = -1;
        caminho[nArestas--] = dest;
        for (; nArestas >= 0; nArestas--)
        {
            i = caminho[nArestas] = predecessor[i - 1];
        }

    } else {
        caminho[0] = -1;
        caminho[1] = -1;
    }
    return caminho;
}

static int *caminhoMenorDistancia(TGrafo *g, int s, int dest)
{
    int *predecessor = (int *)(calloc(g->quantidadeVertices(g), sizeof(int)));
    int *dist = (int *)(calloc(g->quantidadeVertices(g), sizeof(int)));
    int *caminho;
    dijkstra(g, s, dist, predecessor);
    caminho = caminhoMenorDistanciaComPredecessor(g, s, dest, predecessor);
    free(predecessor);
    free(dist);
    return caminho;
}

static int *repeticoesArestasCaminhosMinimos(TGrafo *g)
{
    int i, j, k, tam = g->quantidadeVertices(g);
    int *predecessor = (int *)(calloc(tam, sizeof(int)));
    int *dist = (int *)(calloc(tam, sizeof(int)));
    int *arestas = (int *)calloc(tam * tam, sizeof(int));
    int *caminho;
    for (i = 1; i <= tam; i++)
    {
        dijkstra(g, i, dist, predecessor);
        printf("calculado os caminhos do vertice %d\n", i);
        for (j = 1; j <= tam; j++)
        {
            caminho = caminhoMenorDistanciaComPredecessor(g, i, j, predecessor);
            k = 0;
            while (caminho[k + 1] != -1)
            {
                arestas[(caminho[k] - 1)*tam + caminho[k + 1] -1 ]++;
                k++;
            }
            free(caminho);
        }
    }
    free(predecessor);
    free(dist);
    return arestas;
}

static void removerAresta(TGrafo *g, int u, int v)
{
    g->addArestaPonderada(g, u, v, 0);
}

TGrafo *criarGrafo()
{
    TGrafo *g = (TGrafo *)malloc(sizeof(TGrafo));
    g->menorDistancia = menorDistancia;
    g->caminhoMenorDistancia = caminhoMenorDistancia;
    g->todasMenoresDistancias = todasMenoresDistancias;
    g->removerAresta = removerAresta;
    g->repeticoesArestasCaminhosMinimos = repeticoesArestasCaminhosMinimos;
    return g;
}
