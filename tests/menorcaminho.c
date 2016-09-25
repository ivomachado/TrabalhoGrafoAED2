#include "grafomatriz.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM 9

int main()
{
    TGrafo *g = criarGrafoAdjacencia(TAM);
    int i, j, k, *caminho, *dist, *arestas;
    g->addArestaPonderada(g, 1, 2, 5);
    g->addArestaPonderada(g, 1, 4, 10);
    g->addArestaPonderada(g, 1, 8, 10);
    g->addArestaPonderada(g, 2, 6, 5);
    g->addArestaPonderada(g, 3, 4, 5);
    g->addArestaPonderada(g, 4, 5, 5);
    g->addArestaPonderada(g, 4, 7, 10);
    g->addArestaPonderada(g, 5, 1, 5);
    g->addArestaPonderada(g, 5, 3, 10);
    g->addArestaPonderada(g, 5, 9, 10);
    g->addArestaPonderada(g, 6, 7, 15);
    g->addArestaPonderada(g, 7, 1, 10);
    g->addArestaPonderada(g, 7, 3, 5);
    g->addArestaPonderada(g, 8, 2, 5);
    g->addArestaPonderada(g, 8, 9, 20);
    g->addArestaPonderada(g, 9, 2, 10);
    for (i = 1; i <= TAM; i++)
    {
        dist = g->todasMenoresDistancias(g, i);
        for (j = 1; j <= TAM; j++)
        {
            printf("Menor distancia de %d ao %d eh %d (%d) com caminho:\n", i, j, g->menorDistancia(g, i, j), dist[j - 1]);
            k = 0;
            caminho = g->caminhoMenorDistancia(g, i, j);
            while (caminho[k] != -1)
            {
                printf("%d ",caminho[k]);
                k++;
            }
            printf("\n");
            free(caminho);
        }
        free(dist);
    }
    arestas = g->repeticoesArestasCaminhosMinimos(g);
    printf("    ");
    for(i = 1; i <= TAM; i++) {
        printf("%3d ", i);
    }
    printf("\n");
    for(i = 0; i < TAM; i++) {
        printf("%3d ", i + 1);
        for(j = 0; j < TAM; j++) {
            printf("%03d ", arestas[TAM*i + j]);
        }
        printf("\n");
    }
    return 0;
}
