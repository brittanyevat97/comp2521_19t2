#include <stdio.h>
#include <stdlib.h>

typedef struct graphRep *Graph;

struct graphRep {
    int nV;
    int nE;
    int **edges;
};

typedef struct edge {
    Vertex v;
    Vertex w;
} Edge;

// write a function to check whether a path, given as an
// array of Edges, is an Euler path
int isEulerPath(Graph g, Edge e[], int nE) {
    if (nE != g->nE)
        return 0;

    int i, j;
    for (i = 0; i < nE - 1; i++) {
        if (e[i].w != e[i+1].v)
            return 0;
    }

    for (i = 0; i < nE; i++) {
        for (j = i + 1; j < nE; j++) {
            if (e[i].v == e[j].v && e[i].w == e[j].w)
                return 0;
        }
    }
    return 1;
}
