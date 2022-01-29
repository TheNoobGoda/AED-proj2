#include <iostream>
#include "graph.h"
#include "Path.h"



#ifndef AED_PROJ2_MENU_H
#define AED_PROJ2_MENU_H

class Menu{
private:
    Graph grafo;
    Path actualPath;

    int choice = -1;
public:
    void clearBuffer();

    Menu();

    void mainMenu();

    void originDestiny();
    void bestPath();
    void busChange();
};


#endif //AED_PROJ2_MENU_H
