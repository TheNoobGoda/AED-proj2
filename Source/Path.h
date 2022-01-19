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

public:
    Path()=default;
    Graph getGraph();
    static Graph graphStops();
    void mapping();
    int getMapSize();
    vector<string> getStop(int n);
    vector<string> stringSplit(string n,char c);



};


#endif //AED_PROJ2_PATH_H
