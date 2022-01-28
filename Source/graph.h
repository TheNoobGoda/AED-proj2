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
        bool visited;
        double dist;
        int origin;
        bool operator<(const Node node) const{
            if (this->dist==node.dist){
                return true;
            }else if(this->dist<node.dist){
                return true;
            }else{
                return false;
            }
        }
        bool operator==(const Node node) const{
            if (this->dist==node.dist && this->visited==node.visited && this->origin==node.origin){
                return true;
            }else{
                return false;
            }
        }
    };

    int size;
    bool hasDir;
    vector<Node> nodes;
    vector<Node> djk;

public:
    Graph(int nodes, bool dir = false);

    void addEdge(int src, int dest, string line, double weight = 1);
    int graphSize();
    int getEdge();
    void bfs(int v);
    int dijkstra(int a,int b);

};


#endif //AED_PROJ2_GRAPH_H
