#include <vector>
#include <list>

using namespace std;

#ifndef AED_PROJ2_GRAPH_H
#define AED_PROJ2_GRAPH_H
#include <string>

using namespace std;


class Graph {
    struct Edge {
        int dest;
        int weight;
    };

    struct Node{
        list<Edge> adj;
    };

    int size;
    bool hasDir;
    vector<Node> nodes;

public:
    Graph(int nodes, bool dir = false);

    void addEdge(int src, int dest, int weight = 1);
    int graphSize();

};


#endif //AED_PROJ2_GRAPH_H
