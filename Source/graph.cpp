//
// Created by david on 17/01/2022.
//

#include "graph.h"
#include <queue>
#include <algorithm>

Graph::Graph(int num, bool dir) : size(num), hasDir(dir), nodes(num + 1){}

void Graph::addEdge(int src, int dest, string line, double weight) {
    if (src<1 || src>size || dest<1 || dest>size) return;
    nodes[src].adj.push_back({dest, weight,line});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}


int Graph::graphSize() {
    return nodes.size();
}

int Graph::getEdge() {
    //1176

    return nodes.at(1176).adj.size();
}

void Graph::bfs(int v) {
    for (int v=1; v<=size; v++) nodes[v].visited = false;
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v]. visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        //cout << u << " "; // show node order
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
            }
        }
    }
}

//int Graph::dijkstra(int a, int b) {
//    vector<Node> v;
//    for (int i =1; i<=size; i++){
//        nodes.at(i).origin =-1;
//        nodes.at(i).visited = false;
//        nodes.at(i).dist = INT_MAX;
//
//    }
//    nodes.at(a).dist =0;
//    v.push_back(nodes.at(0));
//    while (!v.empty()){
//        sort(v.begin(),v.end());
//        int j = find(nodes.begin(),nodes.end(),v.at(0))-nodes.begin();
//        nodes.at(j).visited = true;
//        for (auto &it : v.at(0).adj){
//            if (!nodes.at(it.dest).visited){
//                double dist;
//                if (nodes.at(it.dest).dist == INT_MAX){
//                    nodes.at(it.dest).dist = 0;
//                }
//                dist = it.weight + nodes.at(0).dist;
//                if(dist< nodes.at(it.dest).dist){
//                    int i = find(nodes.begin(),nodes.end(),nodes.at(it.dest))-nodes.begin();
//                    nodes.at(it.dest).dist = dist;
//                    nodes.at(it.dest).origin = i;
//                }
//            }
//        }
//        v.erase(v.begin());
//    }
//    return nodes.at(b).dist;
//
//}





