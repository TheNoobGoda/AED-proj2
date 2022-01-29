#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include "Source/Path.h"
#include <fstream>

int main() {
    Path path;
    path.mapping();
    std::cout << path.getGraph().dijkstra(100,200) << endl;
    std::cout << path.getClosestStop(41.17524520,-8.586118070) << endl;

    // Colocar no menu:
    int opcao, opcao2;
    string codigo, codigo2;
    cout << "-----Deseja:-----\n  [1]-Indicar a paragem onde pretende apanhar o transporte.\n  [2]-Indicar a sua localizacao." << endl;
    cin >> opcao;
    double latitude, longitude, latitude2, longitude2;
    if(opcao == 2) {
        cout << "-----Insira a latitude onde se encontra no momento:-----" << endl;
        cin >> latitude;
        cout << "-----Insira a longitude onde se encontra no momento:-----" << endl;
        cin >> longitude;
        string a = path.getClosestStop(latitude, longitude);
        for (int i = 0; i < path.getMapStops().size(); i++) {
            if (path.getMapStops().at(i).at(0) == a) {
                cout << "Paragem mais proxima do local onde se encontra: " << a << " --> " << path.getMapStops().at(i).at(1) << endl;
                break;
            }
        }
    }
    else if (opcao == 1) {
        cout << "-----Insira o código da paragem desejada: -----" << endl;
        cin >> codigo;
        for (int i = 0; i < path.getMapStops().size(); i++) {
            if (path.getMapStops().at(i).at(0) == codigo) {
                cout << "Escolheu a paragem " << codigo << " --> " << path.getMapStops().at(i).at(1) << endl;
                break;
            }
        }
        cout << "Paragem inexistente." << endl;
        return 0;
    }
    else{
        cout << "Inválido." << endl;
        return 0;
    }
    cout << "-----Para onde deseja ir:-----\n  [1]-Inserir paragem.\n  [2]-Inserir localizacao do destino pretendido." << endl;
    cin >> opcao2;
    if(opcao2 == 2) {
        cout << "-----Insira a latitude do destino:-----" << endl;
        cin >> latitude2;
        cout << "-----Insira a longitude do destino:-----" << endl;
        cin >> longitude2;
        string b = path.getClosestStop(latitude2, longitude2);
        for (int i = 0; i < path.getMapStops().size(); i++) {
            if (path.getMapStops().at(i).at(0) == b) {
                cout << "Paragem mais proxima do destino pretendido: " << b << " --> " << path.getMapStops().at(i).at(1) << endl;
                break;
            }
        }
    }
    else if (opcao2 == 1) {
        cout << "-----Insira o código da paragem de destino desejada: -----" << endl;
        cin >> codigo2;
        for (int i = 0; i < path.getMapStops().size(); i++) {
            if (path.getMapStops().at(i).at(0) == codigo2) {
                cout << "Escolheu a paragem " << codigo2 << " --> " << path.getMapStops().at(i).at(1) << endl;
                break;
            }
        }
        cout << "Paragem inexistente." << endl;
        return 0;
    }
    else{
        cout << "Inválido." << endl;
        return 0;
    }
}