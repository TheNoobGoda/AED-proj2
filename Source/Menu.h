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

    /// função que inicia o menu é chamada no main.cpp
    void mainMenu();

    ///função que pede todos os inputs necessarios do utilizador e devolve o melhor caminho baseado nisso
    void originDestiny();
    void bestPath();
    void busChange();
};


#endif //AED_PROJ2_MENU_H
