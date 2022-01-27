#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include "Source/Path.h"
#include <fstream>

int main() {
    Path path;
    //std::cout << path.getGraph().dijkstra(100,200);
    path.mapping();
    std::cout << path.getClosestStop(41.17524520,-8.586118070);

}
