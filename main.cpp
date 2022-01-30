#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include "Source/Path.h"
#include "Source/Menu.h"
#include <fstream>

int main() {
    Path path;
    path.mapping();
    //std::cout << path.getGraph().dijkstra(100,200) << endl;
    //std::cout << path.getClosestStop(41.17524520,-8.586118070) << endl;
    //std::cout << path.getGraph().leastChange(100, 200);

    Menu menu;
    menu.mainMenu();

}