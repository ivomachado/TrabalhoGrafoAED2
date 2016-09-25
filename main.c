#include "grafomatriz.h"
#include <stdio.h>

int main() {
    int n, m;
    int a, b;
    int c;
    int i, j, *arestas;
    TGrafo *g;
    scanf("%d%d", &n, &m);
    g = criarGrafoAdjacencia(n);
    for(i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        g->addArestaPonderada(g, a, b, c);
    }
    arestas = g->repeticoesArestasCaminhosMinimos(g);
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(arestas[n*i + j] != 0)
                printf("(%d, %d): %d\n", i + 1, j + 1, arestas[n*i + j]);
        }
    }
    return 0;
}
