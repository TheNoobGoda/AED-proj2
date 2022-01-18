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

void Path::mapping() {
    int num=0;
    string n;
    ifstream f("../Source/dataset/stops.csv");
    list<string>l;
    while(f.is_open()){
        getline(f,n);
        while(f.peek() != EOF){
            getline(f,n);
            l = stringSplit(n);
            mapStops.insert(pair<int,list<string>>(num,l));
            num ++;
        }
        f.close();
    }
}

int Path::getMapSize() {
    return mapStops.size();
}

list<string> Path::stringSplit(string n) {
    list<string> l;
    char c = 'q';
    int num = 0;
    for (int i=0;i<5;i++){
        c=n.at(num);
        c=n.at(num);
        string str;
        while(c !=','){
            str.push_back(c);
            num++;
            c=n.at(num);
        }
        l.push_back(str);
        num++;
    }
}
