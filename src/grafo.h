typedef struct grafo TGrafo;

typedef short (*TVerificaAdjacencia)(TGrafo *, unsigned int, unsigned int);
typedef void (*TAddAresta)(TGrafo *, unsigned int, unsigned int);
typedef void (*TAddArestaPonderada)(TGrafo *, unsigned int, unsigned int, int);

struct grafo
{
    void *dado;
    TVerificaAdjacencia verificaAdjacencia;
    TAddAresta addAresta;
    TAddArestaPonderada addArestaPonderada;
};
