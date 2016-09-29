#include "grafomatriz.h"
#include <stdio.h>

int main() {
    int n, m;
    int a, b;
    int c, maior;
    int i, j, *arestas;
    //fila de arestas a serem removidas caminhos == maior
    TGrafo *g;
    scanf("%d%d", &n, &m);
    g = criarGrafoAdjacencia(n);
    for(i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        g->addArestaPonderada(g, a, b, c);
    }
    arestas = g->repeticoesArestasCaminhosMinimos(g);
    maior = 0;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(arestas[n*i + j] > maior)
                // esvaziar fila
                //inserir (i+1)->(j+1)
            else
                //igual a maior
                // //inserir (i+1)->(j+1)
                printf("(%d, %d): %d\n", i + 1, j + 1, arestas[n*i + j]);
        }
    }
    //para cada aresta na fila, remove-a do grafo
    return 0;
}
