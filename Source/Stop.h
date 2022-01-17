#include "string"

#ifndef AED_PROJ2_STOP_H
#define AED_PROJ2_STOP_H

using namespace std;

class Stop {
    string code;
    string name;
    string zone;
    float lat;
    float lon;

public:
    Stop(string code, string name, string zone, float lat, float lon);

};


#endif //AED_PROJ2_STOP_H
