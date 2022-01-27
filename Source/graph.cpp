//
// Created by david on 17/01/2022.
//

#include "graph.h"

Graph::Graph(int num, bool dir) : size(num), hasDir(dir), nodes(num + 1){}

void Graph::addEdge(int src, int dest, int line, int weight) {
    if (src<1 || src>size || dest<1 || dest>size) return;
    nodes[src].adj.push_back({dest, weight,line});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}


int Graph::graphSize() {
    return nodes.size();
}

int Graph::getEdge() {
    //1176

    return nodes.at(0).adj.size();
}