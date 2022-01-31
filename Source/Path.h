//
// Created by GODA on 18/01/2022.
//

#ifndef AED_PROJ2_PATH_H
#define AED_PROJ2_PATH_H
#include "graph.h"
#include <map>
#include <vector>


class Path {
    map<int,vector<string>> mapStops;
    Graph graphStop;

public:
    /// construtor do Path ativa as funcoes getGraph e mapping guardando os sues returns respetivamente nas variaveis mapStops e graphStop
    Path();
    /// Retorna a variavel graphStop
    Graph getGraph();
    /// Retorna a variavel mapStops
    map<int,vector<string>> getMapStops();
    /// Constroi o grafo com todas as paragens e as suas ligações
    Graph graphStops();
    ///Mapeia todas as paragens a um numero de identificacao usando um mapa
    void mapping();
    ///Retorna o tamanho do mapa
    int getMapSize();
    ///Retorna as informaçoes da paragem n num veto de strings
    vector<string> getStop(int n);
    ///Funcao auxiliar que recebe uma string e um char e divide a string num vetor de strings usando como divisoria o char
    vector<string> stringSplit(string n,char c);

    ///Funçao com o algoritmo de haversine calcular a distancia entre dois pontos usando as suas latitudes e longitudes
    static double haversine(double lat1, double lon1,double lat2, double lon2);
    void bfs(int v);

    ///Funcao que recebe coordenadas e devolve a paragem mais proxima dessas coordenadas
    string getClosestStop(double lat,double longi);

    int leastChangesPath();



};


#endif //AED_PROJ2_PATH_H
