// Dijkstra's single-source shortest-path algorithm

Dijkstra(Graph g, Vertex s) {
    // set of seen vertices
    VertexSet vSet = newSet();
    // priority queue of vertices, ordered by dist[] value
    PQueue pq = newPQueue();

    // initialise dist[] to all infinity
    int dist[g->nV] = {inf}; 

    // initialise dist[s] to 0
    // (shortest path from s to s is of length 0)
    dist[s] = 0; 

    // initialise pred[] to all -1
    // (found no predecessors yet)
    Vertex pred[g->nV] = {-1}; 
    
    // add source vertex to priority queue
    PQueueJoin(pq, s, dist[s]);

    Vertex v, w;
    while (SetSize(vSet) < g->nV) {
        // take vertex with minimum dist[] value off PQ
        v = PQueueLeave(pq);
        SetInclude(vSet, v);
        for (each Vertex w adjacent to v) {
            if (isElem(vSet, w)) continue;
            // check if we have found a shorter path to w
            if (dist[v] + weight(v, w) < dist[w]) {
                dist[w] = dist[v] + weight(v, w);
                pred[w] = v;
                PQueueJoin(pq, w, dist[w]);
            }
        }
    }
}
