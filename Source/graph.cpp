//
// Created by david on 17/01/2022.
//

#include "graph.h"
#include "Path.h"
#include <queue>
#include <algorithm>

Graph::Graph(int num, bool dir) : size(num), hasDir(dir), nodes(num + 1){}

void Graph::addEdge(int src, int dest, string line, double weight) {
    if (src<0 || src>size || dest<0 || dest>size) return;
    nodes[src].adj.push_back({dest, weight,line});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}


int Graph::graphSize() {
    return nodes.size();
}

vector<int> Graph::bfs(int v,int b) {
    for (int i=0; i<size; i++){
        nodes.at(i).visited = false;
        nodes.at(i).origin = -1;
    }
    queue<int> q;
    q.push(v);
    nodes.at(v).visited = true;
    nodes.at(v).origin = v;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                nodes.at(w).origin = u;
            }
        }
    }

    int stop = b;
    vector<int> ve;
    while (stop != v){
        ve.push_back(stop);
        stop = nodes.at(stop).origin;
        if (stop == -1) {
            return ve;
        }
    }

    return ve;
}

vector<int> Graph::dijkstra(int a, int b) {
    vector<int> v;
    for (int i =0; i<=size; i++){
        nodes.at(i).origin =-1;
        nodes.at(i).visited = false;
        nodes.at(i).dist = INT_MAX;

    }
    nodes.at(a).dist =0;
    nodes.at(a).origin = a;
    v.push_back(a);
    while (!v.empty()){
        v = sortVector2(v);
        int j = v.at(0);
        nodes.at(j).visited = true;
        for (auto it : nodes.at(j).adj){
            if (!nodes.at(it.dest).visited){
                bool bo = false;
                int k =it.dest;
                for (auto &n : v){
                    if (k == n){
                        bo = true;
                    }
                }
                if (!bo) {
                    v.push_back(k);
                }

                double dist;
                if (nodes.at(k).dist == INT_MAX){
                    nodes.at(k).dist = 0;
                }
                dist = it.weight + nodes.at(0).dist;
                if(dist< nodes.at(k).dist){

                    nodes.at(k).dist = dist;
                    nodes.at(k).origin = j;
                }
            }
        }
        v.erase(v.begin());
    }
    int stop = b;
    vector<int> ve;
    while (stop != a){
        ve.push_back(stop);
        stop = nodes.at(stop).origin;
        if (stop == -1) {
            return ve;
        }
    }

    return ve;

}

vector<int> Graph::leastChange(int a, int b) {
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


    int stop = b;
    vector<int> ve;
    while (stop != a){
        ve.push_back(stop);
        stop = nodes.at(stop).origin;
        if (stop == -1) {
            return ve;
        }
    }

    return ve;
}

vector<int> Graph::leastZones(int a, int b) {
    Path path;
    path.mapping();
    vector<int> v ;
    for (int i =1; i<=size; i++){
        nodes.at(i).origin =-1;
        nodes.at(i).visited = false;
        nodes.at(i).zone = "-1";
        nodes.at(i).zoneb = false;

    }
    nodes.at(a).dist =0;
    nodes.at(a).zoneb = true;
    for (auto &it : nodes.at(a).adj){
        v.push_back(it.dest);
        nodes.at(it.dest).origin = a;
        nodes.at(it.dest).zoneb = true;
        nodes.at(it.dest).zone = it.line;
    }
    while (!v.empty()){
        v = sortVector3(v);
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
                if (!nodes.at(it.dest).zoneb){
                    nodes.at(it.dest).origin = v.at(0);
                    if (it.line == nodes.at(v.at(0)).zone){
                        nodes.at(it.dest).zone = path.getMapStops().at(it.dest).at(2);
                        nodes.at(it.dest).zoneb = true;
                    }
                }
            }
        }
        v.erase(v.begin());
    }


    int stop = b;
    vector<int> ve;
    while (stop != a){
        ve.push_back(stop);
        stop = nodes.at(stop).origin;
        if (stop == -1) {
            return ve;
        }
    }

    return ve;
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

vector<int> Graph::sortVector2(vector<int> v) {
    vector<int> res;
    int max = INT_MAX;
    int num =-1;
    while (!v.empty()){
        for (int i=0;i<v.size();i++){
            if (nodes.at(v.at(i)).dist<max){
                max =nodes.at(v.at(i)).dist;
                num = i;
            }
        }
        res.push_back(v.at(num));
        v.erase(v.begin()+num);
    }
    return res;
}

vector<int> Graph::sortVector3(vector<int> v) {
    vector<int> res;
    while (!v.empty()){
        int num = -1;

        for (int i =0;i<v.size();i++){
            if (nodes.at(v.at(i)).zoneb){
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






