//
// Created by david on 17/01/2022.
//

#include "graph.h"
#include "Path.h"
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

int Graph::dijkstra(int a, int b) {
    vector<Node> v;
    for (int i =1; i<=size; i++){
        nodes.at(i).origin =-1;
        nodes.at(i).visited = false;
        nodes.at(i).dist = INT_MAX;

    }
    nodes.at(a).dist =0;
    v.push_back(nodes.at(a)); //verificar
    while (!v.empty()){
        sort(v.begin(),v.end());
        int j = find(nodes.begin(),nodes.end(),v.at(0))-nodes.begin();
        nodes.at(j).visited = true;
        for (auto &it : v.at(0).adj){
            if (!nodes.at(it.dest).visited){
                bool bo = false;
                for (auto &n : v){
                    if (nodes.at(it.dest) == n){
                        bo = true;
                    }
                }
                if (bo) {
                    v.push_back(nodes.at(it.dest));
                }
                int i = find(nodes.begin(),nodes.end(),nodes.at(it.dest))-nodes.begin();
                double dist;
                if (nodes.at(it.dest).dist == INT_MAX){
                    nodes.at(it.dest).dist = 0;
                }
                dist = it.weight + nodes.at(0).dist;
                if(dist< nodes.at(it.dest).dist){

                    nodes.at(it.dest).dist = dist;
                    nodes.at(it.dest).origin = i;
                }
            }
        }
        v.erase(v.begin());
    }
    return nodes.at(b).dist;

}

int Graph::leastChange(int a, int b) {
    vector<int> v ;
    for (int i =1; i<=size; i++){
        nodes.at(i).origin =-1;
        nodes.at(i).visited = false;
        nodes.at(i).line = "-1";
        nodes.at(i).lineb = false;

    }
    nodes.at(a).dist =0;
    nodes.at(a).lineb = true;
    for (auto &it : nodes.at(a).adj){
        v.push_back(it.dest);
        nodes.at(it.dest).origin = a;
        nodes.at(it.dest).lineb = true;
        nodes.at(it.dest).line = it.line;
    }
    while (!v.empty()){
        v = sortVector(v);
        nodes.at(v.at(0)).visited = true;
        for (auto &it : nodes.at(v.at(0)).adj){
            if (!nodes.at(it.dest).visited){
                bool bo = false;
                for (auto &n : v){
                    if (it.dest == n){
                        bo = true;
                    }
                }
                if (bo) {
                    v.push_back(it.dest);
                }
                if (!nodes.at(it.dest).lineb){
                    nodes.at(it.dest).origin = v.at(0);
                    if (it.line == nodes.at(v.at(0)).line){
                        nodes.at(it.dest).line = it.line;
                        nodes.at(it.dest).lineb = true;
                    }
                }
            }
        }
        v.erase(v.begin());
    }


    return 1;
}

vector<int> Graph::sortVector(vector<int> v) {
    vector<int> res;
    while (!v.empty()){
        int num = -1;

        for (int i =0;i<v.size();i++){
            if (nodes.at(v.at(i)).lineb){
                num = i;

                break;
            }
        }
        if (num !=-1) {
            res.push_back(v.at(num));
            v.erase(v.begin() + num);
        }else{
            res.push_back(v.at(0));
            v.erase(v.begin());
        }
    }
    return res;
}





