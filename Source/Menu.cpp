#include "Menu.h"

void Menu::mainMenu() {
    cout << "=====================================" << endl;
    cout << "               AED - G70             " << endl;
    cout << "=====================================" << endl;
    cout << " [1] - Origem/Destino                " << endl;
    cout << " [2] - Escolha de melhor caminho     " << endl;
    cout << " [3] - Mudança de autocarro          " << endl;
    cout << " [4] - Sair                          " << endl;
    clearBuffer();
    cin >> choice;
    while(choice < 1 || choice > 4) {
        cout << "Comando inexistente, usar um novo valor: "; clearBuffer(); cin >> choice;
    }
    switch(choice){
        case 1:
            originDestiny();
            break;
        case 2:
            bestPath();
            break;
        case 3:
            busChange();
            break;
        default:
            cout << "Programa encerrado!" << endl;
            break;
    }
}

Menu::Menu() {
    this->actualPath.mapping();
    this->grafo = actualPath.getGraph();
}

void Menu::clearBuffer() {
    cin.ignore(9999999999,'\n');
    cin.clear();
}