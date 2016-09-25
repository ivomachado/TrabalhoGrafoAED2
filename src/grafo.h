typedef struct grafo TGrafo;

typedef short (*TVerificaAdjacencia)(TGrafo *, int, int);
typedef int (*TDistancia2Vertices)(TGrafo *, int, int);
typedef int * (*TCaminho2Vertices)(TGrafo *, int, int);
typedef void (*TAddAresta)(TGrafo *, int, int);
typedef int (*TEstaticaGrafo)(TGrafo *);
typedef int * (*TAdjacentes)(TGrafo *, int);
typedef int * (*TArestas)(TGrafo *);
typedef int (*TEstatisticaVertice)(TGrafo *, int);
typedef void (*TAddArestaPonderada)(TGrafo *, int, int, int);

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
    TArestas repeticoesArestasCaminhosMinimos;
};
