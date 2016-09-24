typedef struct grafo TGrafo;

typedef short (*TVerificaAdjacencia)(TGrafo *, unsigned int, unsigned int);
typedef int (*TRelacao2Vertices)(TGrafo *, unsigned int, unsigned int);
typedef void (*TAddAresta)(TGrafo *, unsigned int, unsigned int);
typedef int (*TEstaticaGrafo)(TGrafo *);
typedef int * (*TAdjacentes)(TGrafo *, unsigned int);
typedef int (*TEstatisticaVertice)(TGrafo *, unsigned int);
typedef void (*TAddArestaPonderada)(TGrafo *, unsigned int, unsigned int, int);

TGrafo *criarGrafo();

struct grafo
{
    void *dado;
    TVerificaAdjacencia verificaAdjacencia;
    TAddAresta addAresta;
    TAddArestaPonderada addArestaPonderada;
    TRelacao2Vertices valorAresta;
    TRelacao2Vertices menorDistancia;
    TEstaticaGrafo quantidadeVertices;
    TEstaticaGrafo quantidadeArestas;
    TAdjacentes adjacentes;
    TEstatisticaVertice quantidadeAdjacentes;
};
