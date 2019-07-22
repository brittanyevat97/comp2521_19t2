#include <stdio.h>
#include <stdlib.h>

typedef struct graphRep *Graph;
typedef int Vertex;

struct graphRep { 
    int nV;
    int nE;
    int **edges;
}; 

// implement DFS recursively
// psuedocode:
//      mark v as visited
//      for each w in neighbours of v
//          if w has not been visited
//              dfs(g, w)
void dfs(Graph g, Vertex v) {

}
