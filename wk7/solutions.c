#include <stdio.h>
#include <stdlib.h>

typedef struct graphRep *Graph;
typedef int Vertex;

struct graphRep { 
    int nV;
    int nE;
    int **edges;
}; 

void dfsHelper(Graph g, Vertex v, int *visited) {
    visited[v] = 1;
    printf("%d ", v);
    for (Vertex y = 0; y < g->nV; y++) {
        if (g->edges[v][y] && !visited[y])
            dfsHelper(g, y, visited);
    }
}

void dfs(Graph g, Vertex v) {
    int *visited = calloc(g->nV, sizeof(int));
    dfsHelper(g, v, visited);
}
