//
// Created by GODA on 18/01/2022.
//
#include <string>
#include <iostream>
#include <sstream>
#include "Path.h"
#include <fstream>
#include <cmath>

using namespace std;

//Path::Path() {
//    //this->graphStop = graphStops();
//    mapping();
//}

Graph Path::graphStops() {

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
                double n1 = atof(mapStops.at(src).at(3).c_str());
                double n2 = atof(mapStops.at(src).at(4).c_str());
                double n3 = atof(mapStops.at(dest).at(3).c_str());
                double n4 = atof(mapStops.at(dest).at(4).c_str());
                double weight = haversine(n1,n2,n3,n4);
                stops.addEdge(src,dest, to_string(i)+"_0",weight);
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
                double n1 = atof(mapStops.at(src).at(3).c_str());
                double n2 = atof(mapStops.at(src).at(4).c_str());
                double n3 = atof(mapStops.at(dest).at(3).c_str());
                double n4 = atof(mapStops.at(dest).at(4).c_str());
                double weight = haversine(n1,n2,n3,n4);
                stops.addEdge(src,dest,to_string(i)+"_1",weight);
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
            double n1 = atof(mapStops.at(src).at(3).c_str());
            double n2 = atof(mapStops.at(src).at(4).c_str());
            double n3 = atof(mapStops.at(dest).at(3).c_str());
            double n4 = atof(mapStops.at(dest).at(4).c_str());
            double weight = haversine(n1,n2,n3,n4);
            stops.addEdge(src,dest,"1M_0",weight);
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
            double n1 = atof(mapStops.at(src).at(3).c_str());
            double n2 = atof(mapStops.at(src).at(4).c_str());
            double n3 = atof(mapStops.at(dest).at(3).c_str());
            double n4 = atof(mapStops.at(dest).at(4).c_str());
            double weight = haversine(n1,n2,n3,n4);
            stops.addEdge(src,dest,"1M_1",weight);
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
            double n1 = atof(mapStops.at(src).at(3).c_str());
            double n2 = atof(mapStops.at(src).at(4).c_str());
            double n3 = atof(mapStops.at(dest).at(3).c_str());
            double n4 = atof(mapStops.at(dest).at(4).c_str());
            double weight = haversine(n1,n2,n3,n4);
            stops.addEdge(src,dest,"3M_0",weight);
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
            double n1 = atof(mapStops.at(src).at(3).c_str());
            double n2 = atof(mapStops.at(src).at(4).c_str());
            double n3 = atof(mapStops.at(dest).at(3).c_str());
            double n4 = atof(mapStops.at(dest).at(4).c_str());
            double weight = haversine(n1,n2,n3,n4);
            stops.addEdge(src,dest,"3M_1",weight);
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
            double n1 = atof(mapStops.at(src).at(3).c_str());
            double n2 = atof(mapStops.at(src).at(4).c_str());
            double n3 = atof(mapStops.at(dest).at(3).c_str());
            double n4 = atof(mapStops.at(dest).at(4).c_str());
            double weight = haversine(n1,n2,n3,n4);
            stops.addEdge(src,dest,"4M_0",weight);
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
            double n1 = atof(mapStops.at(src).at(3).c_str());
            double n2 = atof(mapStops.at(src).at(4).c_str());
            double n3 = atof(mapStops.at(dest).at(3).c_str());
            double n4 = atof(mapStops.at(dest).at(4).c_str());
            double weight = haversine(n1,n2,n3,n4);
            stops.addEdge(src,dest,"4M_1",weight);
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
            double n1 = atof(mapStops.at(src).at(3).c_str());
            double n2 = atof(mapStops.at(src).at(4).c_str());
            double n3 = atof(mapStops.at(dest).at(3).c_str());
            double n4 = atof(mapStops.at(dest).at(4).c_str());
            double weight = haversine(n1,n2,n3,n4);
            stops.addEdge(src,dest,"5M_0",weight);
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
            double n1 = atof(mapStops.at(src).at(3).c_str());
            double n2 = atof(mapStops.at(src).at(4).c_str());
            double n3 = atof(mapStops.at(dest).at(3).c_str());
            double n4 = atof(mapStops.at(dest).at(4).c_str());
            double weight = haversine(n1,n2,n3,n4);
            stops.addEdge(src,dest,"5M_1",weight);
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
            double n1 = atof(mapStops.at(src).at(3).c_str());
            double n2 = atof(mapStops.at(src).at(4).c_str());
            double n3 = atof(mapStops.at(dest).at(3).c_str());
            double n4 = atof(mapStops.at(dest).at(4).c_str());
            double weight = haversine(n1,n2,n3,n4);
            stops.addEdge(src,dest,"7M_0",weight);
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
            double n1 = atof(mapStops.at(src).at(3).c_str());
            double n2 = atof(mapStops.at(src).at(4).c_str());
            double n3 = atof(mapStops.at(dest).at(3).c_str());
            double n4 = atof(mapStops.at(dest).at(4).c_str());
            double weight = haversine(n1,n2,n3,n4);
            stops.addEdge(src,dest,"7M_1",weight);
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
            double n1 = atof(mapStops.at(src).at(3).c_str());
            double n2 = atof(mapStops.at(src).at(4).c_str());
            double n3 = atof(mapStops.at(dest).at(3).c_str());
            double n4 = atof(mapStops.at(dest).at(4).c_str());
            double weight = haversine(n1,n2,n3,n4);
            stops.addEdge(src,dest,"8M_0",weight);
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
            double n1 = atof(mapStops.at(src).at(3).c_str());
            double n2 = atof(mapStops.at(src).at(4).c_str());
            double n3 = atof(mapStops.at(dest).at(3).c_str());
            double n4 = atof(mapStops.at(dest).at(4).c_str());
            double weight = haversine(n1,n2,n3,n4);
            stops.addEdge(src,dest,"8M_1",weight);
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
            double n1 = atof(mapStops.at(src).at(3).c_str());
            double n2 = atof(mapStops.at(src).at(4).c_str());
            double n3 = atof(mapStops.at(dest).at(3).c_str());
            double n4 = atof(mapStops.at(dest).at(4).c_str());
            double weight = haversine(n1,n2,n3,n4);
            stops.addEdge(src,dest,"9M_0",weight);
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
            double n1 = atof(mapStops.at(src).at(3).c_str());
            double n2 = atof(mapStops.at(src).at(4).c_str());
            double n3 = atof(mapStops.at(dest).at(3).c_str());
            double n4 = atof(mapStops.at(dest).at(4).c_str());
            double weight = haversine(n1,n2,n3,n4);
            stops.addEdge(src,dest,"9M_1",weight);
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
            double n1 = atof(mapStops.at(src).at(3).c_str());
            double n2 = atof(mapStops.at(src).at(4).c_str());
            double n3 = atof(mapStops.at(dest).at(3).c_str());
            double n4 = atof(mapStops.at(dest).at(4).c_str());
            double weight = haversine(n1,n2,n3,n4);
            stops.addEdge(src,dest,"10M_0",weight);
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
            double n1 = atof(mapStops.at(src).at(3).c_str());
            double n2 = atof(mapStops.at(src).at(4).c_str());
            double n3 = atof(mapStops.at(dest).at(3).c_str());
            double n4 = atof(mapStops.at(dest).at(4).c_str());
            double weight = haversine(n1,n2,n3,n4);
            stops.addEdge(src,dest,"10M_1",weight);
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
            double n1 = atof(mapStops.at(src).at(3).c_str());
            double n2 = atof(mapStops.at(src).at(4).c_str());
            double n3 = atof(mapStops.at(dest).at(3).c_str());
            double n4 = atof(mapStops.at(dest).at(4).c_str());
            double weight = haversine(n1,n2,n3,n4);
            stops.addEdge(src,dest,"11M_0",weight);
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
            double n1 = atof(mapStops.at(src).at(3).c_str());
            double n2 = atof(mapStops.at(src).at(4).c_str());
            double n3 = atof(mapStops.at(dest).at(3).c_str());
            double n4 = atof(mapStops.at(dest).at(4).c_str());
            double weight = haversine(n1,n2,n3,n4);
            stops.addEdge(src,dest,"11M_1",weight);
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
            double n1 = atof(mapStops.at(src).at(3).c_str());
            double n2 = atof(mapStops.at(src).at(4).c_str());
            double n3 = atof(mapStops.at(dest).at(3).c_str());
            double n4 = atof(mapStops.at(dest).at(4).c_str());
            double weight = haversine(n1,n2,n3,n4);
            stops.addEdge(src,dest,"12M_0",weight);
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
            double n1 = atof(mapStops.at(src).at(3).c_str());
            double n2 = atof(mapStops.at(src).at(4).c_str());
            double n3 = atof(mapStops.at(dest).at(3).c_str());
            double n4 = atof(mapStops.at(dest).at(4).c_str());
            double weight = haversine(n1,n2,n3,n4);
            stops.addEdge(src,dest,"12M_1",weight);
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
            double n1 = atof(mapStops.at(src).at(3).c_str());
            double n2 = atof(mapStops.at(src).at(4).c_str());
            double n3 = atof(mapStops.at(dest).at(3).c_str());
            double n4 = atof(mapStops.at(dest).at(4).c_str());
            double weight = haversine(n1,n2,n3,n4);
            stops.addEdge(src,dest,"13M_0",weight);
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
            double n1 = atof(mapStops.at(src).at(3).c_str());
            double n2 = atof(mapStops.at(src).at(4).c_str());
            double n3 = atof(mapStops.at(dest).at(3).c_str());
            double n4 = atof(mapStops.at(dest).at(4).c_str());
            double weight = haversine(n1,n2,n3,n4);
            stops.addEdge(src,dest,"13M_1",weight);
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
    l.push_back(temp);
    return l;
}

vector<string> Path::getStop(int n) {
    return mapStops.at(n);
}

map<int, vector<string>> Path::getMapStops() {
    return mapStops;
}

double Path::haversine(double lat1, double lon1, double lat2, double lon2) {
    // distance between latitudes
    // and longitudes
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    // convert to radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    // apply formulae
    double a = pow(sin(dLat / 2), 2) +
               pow(sin(dLon / 2), 2) *
               cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}

void Path::bfs(int v) {
}

string Path::getClosestStop(double lat, double longi) {
    double dist = haversine(lat,longi,atof(mapStops.at(0).at(3).c_str()),atof(mapStops.at(0).at(4).c_str()));
    int n = 0;
    for (int i = 1;i<mapStops.size();i++){
        double dist2 = haversine(lat,longi,atof(mapStops.at(i).at(3).c_str()),atof(mapStops.at(i).at(4).c_str()));
        if (dist>dist2){
            dist = dist2;
            n =i;
        }
    }

    return mapStops.at(n).at(0);
}

int Path::leastChangesPath() {
    mapping();
    Graph stops = graphStops();
    for (int i=0;i<stops.graphSize();i++){

    }
}