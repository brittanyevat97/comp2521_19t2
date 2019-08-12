#include <stdio.h>
#include <stdlib.h>

int *visited;  // array of booleans, indexed by vertex 0..V-1

int hasCycle(Graph g) {
    visited = calloc(g->nV, sizeof(int));
    return dfsCycleCheck(g, 0, -1);
}

int dfsCycleCheck(Graph g, Vertex v, Vertex prev) {
    visited[v] = 1;
    Vertex w;
    for (w = 0; w < g->nV; w++) {
        if (g->edges[v][w] && visited[w] && w != prev) {
            return 1; // found cycle
        }
        if (g->edges[v][w] && !visited[w]) {
            if (dfsCycleCheck(g, w, v)) {
                return 1;
            }
        }
    }
    return 0; // no cycle at v
}
