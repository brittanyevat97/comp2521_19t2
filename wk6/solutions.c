#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct graphRep *Graph;
typedef int Vertex;
typedef struct vNode *List;

// representation of a node used in adjacency list representation
struct vNode {
    Vertex v;
    struct vNode *next;
};

// Adjacency matrix graph representation
struct graphRep {
    int nV;         // number of vertices
    int nE;         // number of edges
    int **edges;    // matrix of booleans (0 or 1)
};

// Adjacency list graph representation
struct graphRep {
    int nV;         // number of vertices
    int nE;         // number of edges
    List *edges;    // array of Vertex lists
};

// alter the DFS from the tute so that no vertex is put in the
// stack more than once
void depthFirst(Graph g, Vertex v) {
    int *visited = calloc(g->nV, sizeof(int));
    Stack s = newStack();
    // note that now we mark a vertex as visited when we push
    // it onto the stack (instead of when we pop it)
    StackPush(s, v);
    visited[v] = 1;
    while (!StackIsEmpty (s)) {
        Vertex x = StackPop (s);
        printf ("%d\n", x);
        for (Vertex y = g->nV - 1; y >= 0; y--) {
            if (!g->edges[x][y])
                continue;
            if (!visited[y]) {
                StackPush (s, y);
                visited[y] = 1;
            }
        }
    }
}
