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

}
