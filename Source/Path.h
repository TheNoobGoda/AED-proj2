//
// Created by GODA on 18/01/2022.
//

#ifndef AED_PROJ2_PATH_H
#define AED_PROJ2_PATH_H
#include "graph.h"
#include "Stop.h"
#include <map>
#include <vector>


class Path {
    map<int,vector<string>> mapStops;
    static Graph graphStop;

public:
    //Path();
    Graph getGraph();
    map<int,vector<string>> getMapStops();
    Graph graphStops();
    void mapping();
    int getMapSize();
    vector<string> getStop(int n);
    vector<string> stringSplit(string n,char c);

    static double haversine(double lat1, double lon1,double lat2, double lon2);
    void bfs(int v);

    string getClosestStop(double lat,double longi);

    int leastChangesPath();



};


#endif //AED_PROJ2_PATH_H
