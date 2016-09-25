#include "grafomatriz.h"
#include <stdio.h>

int main() {
    int n, m;
    int a, b;
    int c;
    int i, j, *arestas;
    TGrafo *g;
    scanf("%d%d", &n, &m);
    printf("n: %d, m: %d",n,m);
    g = criarGrafoAdjacencia(n);
    for(i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        g->addArestaPonderada(g, a, b, c);
    }
    printf("montou o grafo\n");
    arestas = g->repeticoesArestasCaminhosMinimos(g);
    printf("      ");
    for(i = 1; i <= n; i++) {
        printf("%5d ", i);
    }
    printf("\n");
    for(i = 0; i < n; i++) {
        printf("%5d ", i + 1);
        for(j = 0; j < n; j++) {
            printf("%05d ", arestas[n*i + j]);
        }
        printf("\n");
    }
    return 0;
}
