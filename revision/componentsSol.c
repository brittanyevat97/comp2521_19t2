#include <stdio.h>
#include <stdlib.h>

// use DFS to create vertex-indexed connected components array
int *createComponents(Graph g) {
    int *componentOf = malloc(g->nV * sizeof(int));
    memset(componentOf, -1, g->nV * sizeof(int));
    int c = 0;
    Vertex v;
    for (v = 0; v < g->nV; v++) {
        if (componentOf[v] == -1) {
            dfsComponents(g, componentOf, v, c);
            c++;
        }
    }
    return componentOf;
}

void dfsComponents(Graph g, int *componentOf, Vertex x, int c) {
    componentOf[x] = c;
    Vertex y;
    for (y = 0; y < g->nV; y++) {
        if (g->edges[x][y] && componentOf[y] == -1) {
            dfsComponents(g, componentOf, y, c);
        }
    }
}
