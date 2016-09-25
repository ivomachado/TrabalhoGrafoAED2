typedef struct grafo TGrafo;

typedef short (*TVerificaAdjacencia)(TGrafo *, unsigned int, unsigned int);
typedef int (*TDistancia2Vertices)(TGrafo *, unsigned int, unsigned int);
typedef int * (*TCaminho2Vertices)(TGrafo *, unsigned int, unsigned int);
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
    TDistancia2Vertices valorAresta;
    TDistancia2Vertices menorDistancia;
    TCaminho2Vertices caminhoMenorDistancia;
    TEstaticaGrafo quantidadeVertices;
    TEstaticaGrafo quantidadeArestas;
    TAdjacentes adjacentes;
    TAdjacentes todasMenoresDistancias;
    TAddAresta removerAresta;
    TEstatisticaVertice quantidadeAdjacentes;
};
