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
    vector<string> l ={};
    while(f.is_open()){
        getline(f,n);
        while(f.peek() != EOF){
            getline(f,n);
            l = stringSplit(n,',');
            mapStops.insert(pair<int,vector<string>>(num,l));
            num ++;
        }
        f.close();
    }
}

int Path::getMapSize() {
    return mapStops.size();
}

vector<string> Path::stringSplit(string n,char c) {
    string temp ="";
    vector<string> l;

    for(int i=0; i<(int)n.size(); i++){
        if(n[i] != c){
            temp += n[i];
        }
        else{
            l.push_back(temp);
            temp = "";
        }
    }
    return l;
}

vector<string> Path::getStop(int n) {
    return mapStops.at(n);
}

Graph Path::lineGraph(string str) {
    ifstream f (str);
    string n ;
    while (f.is_open()){
        getline(f,n);
        Graph g(int(n));
        while (f.peek() !=EOF){

        }
    }
}
