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
        double weight;
        string line;
    };

    struct Node{
        list<Edge> adj;
    };

    int size;
    bool hasDir;
    vector<Node> nodes;

public:
    Graph(int nodes, bool dir = false);

    void addEdge(int src, int dest, string line, double weight = 1);
    int graphSize();
    int getEdge();

};


#endif //AED_PROJ2_GRAPH_H
