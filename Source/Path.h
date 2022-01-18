//
// Created by GODA on 18/01/2022.
//

#ifndef AED_PROJ2_PATH_H
#define AED_PROJ2_PATH_H
#include "graph.h"
#include "Stop.h"
#include <map>


class Path {
    map<int,list<string>> mapStops;

public:
    Path()=default;
    Graph getGraph();
    static Graph graphStops();
    void mapping();
    int getMapSize();
    list<string> stringSplit(string n);



};


#endif //AED_PROJ2_PATH_H
