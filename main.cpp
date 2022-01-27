#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include "Source/Path.h"
#include <fstream>

int main() {
    Path path;
    path.graphStops();
    cout << path.getMapSize()<< "\n" << path.getStop(0).at(0) << "\n" << path.getGraph().getEdge();

}
