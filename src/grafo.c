#include "grafo.h"
#include <stdlib.h>
#include <limits.h>

static int menorDistancia(TGrafo *g, unsigned int s, unsigned int dest)
{
    int i, tam = g->quantidadeVertices(g), visitados = 0;
    int *adjacentes;
    int inf = INT_MAX;
    int *visitado = (int*)(calloc(tam, sizeof(int)));
    int *dist = (int*)(calloc(tam, sizeof(int)));
    int *predecessor = (int*)(calloc(tam, sizeof(int)));
    int result;
    for(i = 0; i < tam; i++) {
        dist[i] = inf;
    }
    dist[s - 1] = 0;
    
    while(visitados < tam) {
        s = 1;
        for(i = 0; i < tam; i++) {
            if(visitado[s - 1] || (!visitado[i] && dist[s - 1] > dist[i])) {
                s = i + 1;
            }
        }
        visitado[s - 1] = 1;
        visitados++;
        adjacentes = g->adjacentes(g, s);
        i = 0;
        while(adjacentes[i] > 0) {
            if (dist[adjacentes[i] - 1] > dist[s - 1] + g->valorAresta(g, s, adjacentes[i])) {
                dist[adjacentes[i] - 1] = dist[s - 1] + g->valorAresta(g, s, adjacentes[i]);
                predecessor[adjacentes[i] - 1] = s;
            }
            i++;
        }
    }
    result = dist[dest - 1];
    free(dist);
    free(visitado);
    free(predecessor);
    return result;
}

TGrafo *criarGrafo()
{
    TGrafo *g = (TGrafo *)malloc(sizeof(TGrafo));
    g->menorDistancia = menorDistancia;
    return g;
}
