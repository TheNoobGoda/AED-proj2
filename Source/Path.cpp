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
    mapping();
    Graph stops(2487,true);
    string line;
    int src;
    int dest;

    for (int i =0;i<999;i++){
        string filename ="../Source/dataset/line_"+ to_string(i)+"_0.csv";
        ifstream f(filename);
        while (f.is_open()){
            getline(f,line);
            getline(f,line);
            for (int i = 0;i<mapStops.size();i++){
                if (line == mapStops.at(i).at(0)){
                    src = i;
                    break;
                }
            }
            while(f.peek() !=EOF){
                getline(f,line);
                for (int i = 0;i<mapStops.size();i++){
                    if (line == mapStops.at(i).at(0)){
                        dest = i;
                        break;
                    }
                }
                stops.addEdge(src,dest,1);
                src = dest;
            }
            f.close();

        }
        filename = "../Source/dataset/line_"+ to_string(i)+"_1.csv";
        f=ifstream (filename);
        while (f.is_open()){
            getline(f,line);
            getline(f,line);
            for (int i = 0;i<mapStops.size();i++){
                if (line == mapStops.at(i).at(0)){
                    src = i;
                    break;
                }
            }
            while(f.peek() !=EOF){
                getline(f,line);
                for (int i = 0;i<mapStops.size();i++){
                    if (line == mapStops.at(i).at(0)){
                        dest = i;
                        break;
                    }
                }
                stops.addEdge(src,dest,1);
                src = dest;
            }
            f.close();

        }
    }

    ifstream f("../Source/dataset/line_1M_0.csv");
    while (f.is_open()){
        getline(f,line);
        getline(f,line);
        for (int i = 0;i<mapStops.size();i++){
            if (line == mapStops.at(i).at(0)){
                src = i;
                break;
            }
        }
        while(f.peek() !=EOF){
            getline(f,line);
            for (int i = 0;i<mapStops.size();i++){
                if (line == mapStops.at(i).at(0)){
                    dest = i;
                    break;
                }
            }
            stops.addEdge(src,dest,1);
            src = dest;
        }
        f.close();

    }

    f=ifstream ("../Source/dataset/line_1M_1.csv");
    while (f.is_open()){
        getline(f,line);
        getline(f,line);
        for (int i = 0;i<mapStops.size();i++){
            if (line == mapStops.at(i).at(0)){
                src = i;
                break;
            }
        }
        while(f.peek() !=EOF){
            getline(f,line);
            for (int i = 0;i<mapStops.size();i++){
                if (line == mapStops.at(i).at(0)){
                    dest = i;
                    break;
                }
            }
            stops.addEdge(src,dest,1);
            src = dest;
        }
        f.close();

    }

    f=ifstream ("../Source/dataset/line_3M_0.csv");
    while (f.is_open()){
        getline(f,line);
        getline(f,line);
        for (int i = 0;i<mapStops.size();i++){
            if (line == mapStops.at(i).at(0)){
                src = i;
                break;
            }
        }
        while(f.peek() !=EOF){
            getline(f,line);
            for (int i = 0;i<mapStops.size();i++){
                if (line == mapStops.at(i).at(0)){
                    dest = i;
                    break;
                }
            }
            stops.addEdge(src,dest,1);
            src = dest;
        }
        f.close();

    }
    f=ifstream ("../Source/dataset/line_3M_1.csv");
    while (f.is_open()){
        getline(f,line);
        getline(f,line);
        for (int i = 0;i<mapStops.size();i++){
            if (line == mapStops.at(i).at(0)){
                src = i;
                break;
            }
        }
        while(f.peek() !=EOF){
            getline(f,line);
            for (int i = 0;i<mapStops.size();i++){
                if (line == mapStops.at(i).at(0)){
                    dest = i;
                    break;
                }
            }
            stops.addEdge(src,dest,1);
            src = dest;
        }
        f.close();

    }

    f=ifstream ("../Source/dataset/line_4M_0.csv");
    while (f.is_open()){
        getline(f,line);
        getline(f,line);
        for (int i = 0;i<mapStops.size();i++){
            if (line == mapStops.at(i).at(0)){
                src = i;
                break;
            }
        }
        while(f.peek() !=EOF){
            getline(f,line);
            for (int i = 0;i<mapStops.size();i++){
                if (line == mapStops.at(i).at(0)){
                    dest = i;
                    break;
                }
            }
            stops.addEdge(src,dest,1);
            src = dest;
        }
        f.close();

    }

    f=ifstream ("../Source/dataset/line_4M_1.csv");
    while (f.is_open()){
        getline(f,line);
        getline(f,line);
        for (int i = 0;i<mapStops.size();i++){
            if (line == mapStops.at(i).at(0)){
                src = i;
                break;
            }
        }
        while(f.peek() !=EOF){
            getline(f,line);
            for (int i = 0;i<mapStops.size();i++){
                if (line == mapStops.at(i).at(0)){
                    dest = i;
                    break;
                }
            }
            stops.addEdge(src,dest,1);
            src = dest;
        }
        f.close();

    }

    f=ifstream ("../Source/dataset/line_5M_0.csv");
    while (f.is_open()){
        getline(f,line);
        getline(f,line);
        for (int i = 0;i<mapStops.size();i++){
            if (line == mapStops.at(i).at(0)){
                src = i;
                break;
            }
        }
        while(f.peek() !=EOF){
            getline(f,line);
            for (int i = 0;i<mapStops.size();i++){
                if (line == mapStops.at(i).at(0)){
                    dest = i;
                    break;
                }
            }
            stops.addEdge(src,dest,1);
            src = dest;
        }
        f.close();

    }

    f=ifstream ("../Source/dataset/line_5M_1.csv");
    while (f.is_open()){
        getline(f,line);
        getline(f,line);
        for (int i = 0;i<mapStops.size();i++){
            if (line == mapStops.at(i).at(0)){
                src = i;
                break;
            }
        }
        while(f.peek() !=EOF){
            getline(f,line);
            for (int i = 0;i<mapStops.size();i++){
                if (line == mapStops.at(i).at(0)){
                    dest = i;
                    break;
                }
            }
            stops.addEdge(src,dest,1);
            src = dest;
        }
        f.close();

    }

    f=ifstream ("../Source/dataset/line_7M_0.csv");
    while (f.is_open()){
        getline(f,line);
        getline(f,line);
        for (int i = 0;i<mapStops.size();i++){
            if (line == mapStops.at(i).at(0)){
                src = i;
                break;
            }
        }
        while(f.peek() !=EOF){
            getline(f,line);
            for (int i = 0;i<mapStops.size();i++){
                if (line == mapStops.at(i).at(0)){
                    dest = i;
                    break;
                }
            }
            stops.addEdge(src,dest,1);
            src = dest;
        }
        f.close();

    }

    f=ifstream ("../Source/dataset/line_7M_1.csv");
    while (f.is_open()){
        getline(f,line);
        getline(f,line);
        for (int i = 0;i<mapStops.size();i++){
            if (line == mapStops.at(i).at(0)){
                src = i;
                break;
            }
        }
        while(f.peek() !=EOF){
            getline(f,line);
            for (int i = 0;i<mapStops.size();i++){
                if (line == mapStops.at(i).at(0)){
                    dest = i;
                    break;
                }
            }
            stops.addEdge(src,dest,1);
            src = dest;
        }
        f.close();

    }

    f=ifstream ("../Source/dataset/line_8M_0.csv");
    while (f.is_open()){
        getline(f,line);
        getline(f,line);
        for (int i = 0;i<mapStops.size();i++){
            if (line == mapStops.at(i).at(0)){
                src = i;
                break;
            }
        }
        while(f.peek() !=EOF){
            getline(f,line);
            for (int i = 0;i<mapStops.size();i++){
                if (line == mapStops.at(i).at(0)){
                    dest = i;
                    break;
                }
            }
            stops.addEdge(src,dest,1);
            src = dest;
        }
        f.close();

    }

    f=ifstream ("../Source/dataset/line_8M_1.csv");
    while (f.is_open()){
        getline(f,line);
        getline(f,line);
        for (int i = 0;i<mapStops.size();i++){
            if (line == mapStops.at(i).at(0)){
                src = i;
                break;
            }
        }
        while(f.peek() !=EOF){
            getline(f,line);
            for (int i = 0;i<mapStops.size();i++){
                if (line == mapStops.at(i).at(0)){
                    dest = i;
                    break;
                }
            }
            stops.addEdge(src,dest,1);
            src = dest;
        }
        f.close();

    }

    f=ifstream ("../Source/dataset/line_9M_0.csv");
    while (f.is_open()){
        getline(f,line);
        getline(f,line);
        for (int i = 0;i<mapStops.size();i++){
            if (line == mapStops.at(i).at(0)){
                src = i;
                break;
            }
        }
        while(f.peek() !=EOF){
            getline(f,line);
            for (int i = 0;i<mapStops.size();i++){
                if (line == mapStops.at(i).at(0)){
                    dest = i;
                    break;
                }
            }
            stops.addEdge(src,dest,1);
            src = dest;
        }
        f.close();

    }

    f=ifstream ("../Source/dataset/line_9M_1.csv");
    while (f.is_open()){
        getline(f,line);
        getline(f,line);
        for (int i = 0;i<mapStops.size();i++){
            if (line == mapStops.at(i).at(0)){
                src = i;
                break;
            }
        }
        while(f.peek() !=EOF){
            getline(f,line);
            for (int i = 0;i<mapStops.size();i++){
                if (line == mapStops.at(i).at(0)){
                    dest = i;
                    break;
                }
            }
            stops.addEdge(src,dest,1);
            src = dest;
        }
        f.close();

    }

    f=ifstream ("../Source/dataset/line_10M_0.csv");
    while (f.is_open()){
        getline(f,line);
        getline(f,line);
        for (int i = 0;i<mapStops.size();i++){
            if (line == mapStops.at(i).at(0)){
                src = i;
                break;
            }
        }
        while(f.peek() !=EOF){
            getline(f,line);
            for (int i = 0;i<mapStops.size();i++){
                if (line == mapStops.at(i).at(0)){
                    dest = i;
                    break;
                }
            }
            stops.addEdge(src,dest,1);
            src = dest;
        }
        f.close();

    }

    f=ifstream ("../Source/dataset/line_10M_1.csv");
    while (f.is_open()){
        getline(f,line);
        getline(f,line);
        for (int i = 0;i<mapStops.size();i++){
            if (line == mapStops.at(i).at(0)){
                src = i;
                break;
            }
        }
        while(f.peek() !=EOF){
            getline(f,line);
            for (int i = 0;i<mapStops.size();i++){
                if (line == mapStops.at(i).at(0)){
                    dest = i;
                    break;
                }
            }
            stops.addEdge(src,dest,1);
            src = dest;
        }
        f.close();

    }

    f=ifstream ("../Source/dataset/line_11M_0.csv");
    while (f.is_open()){
        getline(f,line);
        getline(f,line);
        for (int i = 0;i<mapStops.size();i++){
            if (line == mapStops.at(i).at(0)){
                src = i;
                break;
            }
        }
        while(f.peek() !=EOF){
            getline(f,line);
            for (int i = 0;i<mapStops.size();i++){
                if (line == mapStops.at(i).at(0)){
                    dest = i;
                    break;
                }
            }
            stops.addEdge(src,dest,1);
            src = dest;
        }
        f.close();

    }

    f=ifstream ("../Source/dataset/line_11M_1.csv");
    while (f.is_open()){
        getline(f,line);
        getline(f,line);
        for (int i = 0;i<mapStops.size();i++){
            if (line == mapStops.at(i).at(0)){
                src = i;
                break;
            }
        }
        while(f.peek() !=EOF){
            getline(f,line);
            for (int i = 0;i<mapStops.size();i++){
                if (line == mapStops.at(i).at(0)){
                    dest = i;
                    break;
                }
            }
            stops.addEdge(src,dest,1);
            src = dest;
        }
        f.close();

    }

    f=ifstream ("../Source/dataset/line_12M_0.csv");
    while (f.is_open()){
        getline(f,line);
        getline(f,line);
        for (int i = 0;i<mapStops.size();i++){
            if (line == mapStops.at(i).at(0)){
                src = i;
                break;
            }
        }
        while(f.peek() !=EOF){
            getline(f,line);
            for (int i = 0;i<mapStops.size();i++){
                if (line == mapStops.at(i).at(0)){
                    dest = i;
                    break;
                }
            }
            stops.addEdge(src,dest,1);
            src = dest;
        }
        f.close();

    }

    f=ifstream ("../Source/dataset/line_12M_1.csv");
    while (f.is_open()){
        getline(f,line);
        getline(f,line);
        for (int i = 0;i<mapStops.size();i++){
            if (line == mapStops.at(i).at(0)){
                src = i;
                break;
            }
        }
        while(f.peek() !=EOF){
            getline(f,line);
            for (int i = 0;i<mapStops.size();i++){
                if (line == mapStops.at(i).at(0)){
                    dest = i;
                    break;
                }
            }
            stops.addEdge(src,dest,1);
            src = dest;
        }
        f.close();

    }

    f=ifstream ("../Source/dataset/line_13M_0.csv");
    while (f.is_open()){
        getline(f,line);
        getline(f,line);
        for (int i = 0;i<mapStops.size();i++){
            if (line == mapStops.at(i).at(0)){
                src = i;
                break;
            }
        }
        while(f.peek() !=EOF){
            getline(f,line);
            for (int i = 0;i<mapStops.size();i++){
                if (line == mapStops.at(i).at(0)){
                    dest = i;
                    break;
                }
            }
            stops.addEdge(src,dest,1);
            src = dest;
        }
        f.close();

    }

    f=ifstream ("../Source/dataset/line_13M_1.csv");
    while (f.is_open()){
        getline(f,line);
        getline(f,line);
        for (int i = 0;i<mapStops.size();i++){
            if (line == mapStops.at(i).at(0)){
                src = i;
                break;
            }
        }
        while(f.peek() !=EOF){
            getline(f,line);
            for (int i = 0;i<mapStops.size();i++){
                if (line == mapStops.at(i).at(0)){
                    dest = i;
                    break;
                }
            }
            stops.addEdge(src,dest,1);
            src = dest;
        }
        f.close();

    }

    return stops;
}

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

map<int, vector<string>> Path::getMapStops() {
    return mapStops;
}

