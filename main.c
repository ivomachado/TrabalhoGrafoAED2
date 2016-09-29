#include "grafomatriz.h"
#include "listaencadeada.h"
#include <stdio.h>

typedef struct aresta {
    int u;
    int v;
}TAresta;

int main() {
    int n, m;
    int a, b;
    int c, maior;
    int i, j, *arestas;
    TLista *arestas_remover;
    TAresta *aresta;


    //fila de arestas a serem removidas caminhos == maior
    TGrafo *g;
    scanf("%d%d", &n, &m);
    g = criarGrafoAdjacencia(n);
    for(i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        g->addArestaPonderada(g, a, b, c);
    }
    arestas = g->repeticoesArestasCaminhosMinimos(g);

    
    arestas_remover = CriarLista();
    maior = 0;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(arestas[n*i + j] > maior){
                // esvaziar fila
                arestas_remover->esvaziar(arestas_remover);
                
                //inserir (i+1)->(j+1)
                aresta = (TAresta*)malloc(sizeof(TAresta));
                aresta->u = i+1;
                aresta->v = j+1;
                arestas_remover->inserir(l, aresta);
            }
            else{
                //igual a maior
                if(arestas[n*i + j] == maior){
                    maior = arestas[n*i + j];
                    //inserir (i+1)->(j+1)
                    aresta = (TAresta*)malloc(sizeof(TAresta));
                    aresta->u = i+1;
                    aresta->v = j+1;
                    arestas_remover->inserir(l, aresta);
                }
            }
                printf("(%d, %d): %d\n", i + 1, j + 1, arestas[n*i + j]);
        }
    }
    //para cada aresta na fila, remove-a do grafo
    for(i= 0; i < arestas_remover->tamanho(arestas_remover); i++){
        aresta = arestas_remover->removerInicio(arestas_remover);
        g->removerAresta(g, aresta->u, aresta->v);
    }
    return 0;
}
