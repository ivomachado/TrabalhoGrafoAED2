#include "grafomatriz.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    TGrafo *g = criarGrafoAdjacencia(9);
    int i, j, k, *caminho;
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
    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= 9; j++)
        {
            printf("Menor distancia de %d ao %d eh %d com caminho:\n", i, j, g->menorDistancia(g, i, j));
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
    }
    return 0;
}
