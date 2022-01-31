#include <vector>
#include <list>

using namespace std;

#ifndef AED_PROJ2_GRAPH_H
#define AED_PROJ2_GRAPH_H
#include <string>
#include <bits/stdc++.h>

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
        string line;
        bool lineb;
        string zone;
        bool zoneb;
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

    /// Construtor recebe o numero de nodes e direçao do grafo (por deafualt direçao é falso)
    Graph(int nodes, bool dir = false);
    Graph()=default;

    /// Retorna um vetor com todos os nos do grafo
    vector<Node> getNodes(){
        return nodes;
    }

    /// Adiciona uma edge ao grafo desde a source ate a destination, recebendo tambem que linha liga essas duas paragens e a distancia entre elas (por default a distancia é 1)
    void addEdge(int src, int dest, string line, double weight = 1);
    /// retorna o numero de nos do grafo
    int graphSize();

    /// Usa o algoritmo de bfs para retornar um vetor com todas as paragens da paragem v a b sendo este caminho que tem menos paragens intremedias
    vector<int> bfs(int v,int b);
    /// Usa o algoritmo de dijkstra para retornar um vetor com todas as paragens da paragem v a b sendo este o caminho com a menor distancia
    vector<int> dijkstra(int a,int b);
    ///Usa o algoritmo de dijkstra para retornar um vetor com todas as paragens da paragem v a b sendo este o caminho com o menor numero de trocas de autocarros
    vector<int> leastChange(int a,int b);
    ///Usa o algoritmo de dijkstra para retornar um vetor com todas as paragens da paragem v a b sendo este o caminho com o menor numero de trocas de zonas
    vector<int> leastZones(int a,int b);

    ///Funca auxiliar que da sort um vetor pondo primeiro os que tem a linha em comum com a sua origem usada na funcao leastChange
    vector<int> sortVector(vector<int> v);
    ///Funca auxiliar que da sort um vetor pela ordem crescente da dist usada na funcao dijkstra
    vector<int> sortVector2(vector<int> v);
    ///Funca auxiliar que da sort um vetor pondo primeiro os que tem a zona em comum com a sua origem usada na funcao leastZones
    vector<int> sortVector3(vector<int> v);
};


#endif //AED_PROJ2_GRAPH_H
