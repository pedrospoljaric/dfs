#include <stdio.h>
#include <stdlib.h>
#define MAX 500

#define BRANCO 1
#define CINZA 2
#define PRETO 3
#define INFINITO 999999

typedef struct Vertice
{
    int id;
    char tipo;
    int nArestas;
    int d, f;
    int cor;
    struct Vertice *ant;
}Vertice;

typedef struct Grafo
{
    int M[MAX][MAX];
    Vertice *V;
    int nArestas;
    int nVertices;
}Grafo;

typedef struct Pilha
{
    Vertice *topo;
}Fila;

Vertice novoVert(int id, char tipo, int i, int j);
void InserirAresta(Grafo *grafo, Vertice u, Vertice v);
void DFS(Grafo *g);
void DFS_visit(Grafo *g, int v, int *tempo);

int main()
{
    return 0;
}

void DFS(Grafo *g)
{
    int i, tempo = 0;

    for (i = 0; i < g->nVertices; i++)
        g->V[i].cor = BRANCO;

    for (i = 0; i < g->nVertices; i++)
        if (g->V[i].cor == BRANCO)
            DFS_visit(g, i, &tempo);
}

void DFS_visit(Grafo *g, int v, int *tempo)
{
    int i;

    g->V[v].cor = CINZA;
    *tempo = *tempo + 1;
    g->V[v].d = *tempo;

    for (i = 0; i < g->nVertices; i++)
        if (g->M[v][i] != INFINITO && g->V[i].cor == BRANCO)
            DFS_visit(g, i, tempo);

    g->V[v].cor = PRETO;
    g->V[v].f = *tempo + 1;
}

Vertice novoVert(int id, char tipo, int i, int j)
{
    Vertice v;
    v.id = id;
    v.tipo = tipo;
    v.nArestas = 0;

    return v;
}

void InserirAresta(Grafo *grafo, Vertice u, Vertice v)
{
    if (grafo->M[u.id][v.id] != 1)
    {
        grafo->M[u.id][v.id] = 1;
        u.nArestas++;
        v.nArestas++;
    }
}

