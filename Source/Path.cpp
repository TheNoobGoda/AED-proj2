//
// Created by GODA on 18/01/2022.
//
#include <string>
#include <iostream>
#include <sstream>
#include "Path.h"
#include <fstream>

using namespace std;

Graph Path::graphStops() {
    Graph stops(2487);
    return stops;
};

Graph Path::getGraph() {
    return graphStops();
}
