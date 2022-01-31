#include "Menu.h"

void Menu::mainMenu() {
    cout << "=====================================" << endl;
    cout << "               AED - G70             " << endl;
    cout << "=====================================" << endl;
    cout << " [1] - Procurar caminho              " << endl;
    cout << " [2] - Sair                          " << endl;
    clearBuffer();
    cin >> choice;
    while(choice < 1 || choice > 2) {
        cout << "Comando inexistente, usar um novo valor: "; clearBuffer(); cin >> choice;
    }
    switch(choice){
        case 1:
            choice = -1;
            originDestiny();
            break;
        case 2:
            cout << "Programa encerrado!" << endl;
            break;
//            choice = -1;
//            //bestPath();
//            break;
//        case 3:
//            //busChange();
//            break;
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
    //cin.ignore(9999999999,'\n');
    cin.clear();
}

void Menu::originDestiny() {
    cout << "=====================================" << endl;
    cout << "               AED - G70             " << endl;
    cout << "=====================================" << endl;
    clearBuffer();
    int opcao, opcao2,num,num2;
    string codigo, codigo2;
    bool find = false, find2 = false;
    cout << "-----Deseja:-----\n  [1]-Indicar a paragem onde pretende apanhar o transporte.\n  [2]-Indicar a sua localizacao." << endl;
    cin >> opcao;
    while(opcao < 1 || opcao > 2) {
    cout << "Comando inexistente, usar um novo valor: "; clearBuffer(); cin >> opcao;
    }
    clearBuffer();
    double latitude, longitude, latitude2, longitude2;
    if(opcao == 2) {
        cout << "-----Insira a latitude onde se encontra no momento:-----" << endl;
        cin >> latitude;
        clearBuffer();
        cout << "-----Insira a longitude onde se encontra no momento:-----" << endl;
        cin >> longitude;
        clearBuffer();
        string a = actualPath.getClosestStop(latitude, longitude);
        codigo = a;
        for (int i = 0; i < actualPath.getMapStops().size(); i++) {
            if (actualPath.getMapStops().at(i).at(0) == a) {
                cout << "Paragem mais proxima do local onde se encontra: " << a << " --> " << actualPath.getMapStops().at(i).at(1) << endl;
                num = i;
                break;
            }
        }
    }
    else if (opcao == 1) {
        cout << "-----Insira o codigo da paragem desejada: -----" << endl;
        cin >> codigo;
        clearBuffer();
        for (int i = 0; i < actualPath.getMapStops().size(); i++) {
            if (actualPath.getMapStops().at(i).at(0) == codigo) {
                cout << "Escolheu a paragem " << codigo << " --> " << actualPath.getMapStops().at(i).at(1) << endl;
                num = i;
                find = true;
                break;
            }
        }
        if (!find){
            cout << "Paragem inexistente." << endl;
            originDestiny();
        }
    }
    else{
        cout << "Invalido." << endl;
        originDestiny();
    }
    clearBuffer();
    cout << "-----Para onde deseja ir:-----\n  [1]-Inserir paragem.\n  [2]-Inserir localizacao do destino pretendido." << endl;
    cin >> opcao2;
    while(choice < 1 || choice > 2 || typeid(choice).name()!="i") {
        cout << "Comando inexistente, usar um novo valor: "; clearBuffer(); cin >> opcao2;
    }
    clearBuffer();
    if(opcao2 == 2) {
        cout << "-----Insira a latitude do destino:-----" << endl;
        cin >> latitude2;
        clearBuffer();
        cout << "-----Insira a longitude do destino:-----" << endl;
        cin >> longitude2;
        clearBuffer();
        string b = actualPath.getClosestStop(latitude2, longitude2);
        codigo2 = b;
        for (int i = 0; i < actualPath.getMapStops().size(); i++) {
            if (actualPath.getMapStops().at(i).at(0) == b) {
                cout << "Paragem mais proxima do destino pretendido: " << b << " --> " << actualPath.getMapStops().at(i).at(1) << endl;
                num2 = i;
                break;
            }
        }
    }
    else if (opcao2 == 1) {
        cout << "-----Insira o codigo da paragem de destino desejada: -----" << endl;
        cin >> codigo2;
        clearBuffer();
        for (int i = 0; i < actualPath.getMapStops().size(); i++) {
            if (actualPath.getMapStops().at(i).at(0) == codigo2) {
                cout << "Escolheu a paragem " << codigo2 << " --> " << actualPath.getMapStops().at(i).at(1) << endl;
                num2 = i;
                find2 = true;
                break;
            }
        }
        if(!find2){
            cout << "Paragem inexistente." << endl;
            originDestiny();
        }
    }
    else{
        cout << "Invalido." << endl;
        originDestiny();
    }
    //parte diferente

    cout << "=====================================" << endl;
    cout << "               AED - G70             " << endl;
    cout << "=====================================" << endl;
    cout << " [1] - Menor numero de paragens      " << endl;
    cout << " [2] - Menor distãncia               " << endl;
    cout << " [3] - Menor mudanca de linhas       " << endl;
    cout << " [4] - Menor mudanca de zonas        " << endl;
    clearBuffer();
    cin >> choice;
    while(choice < 1 || choice > 3 || typeid(choice).name()!="i") {
        cout << "Comando inexistente, usar um novo valor: ";
        clearBuffer();
        cin >> choice;
    }
    switch(choice){
        case 1: {
            choice = -1;
            string str;
            vector<int> v = grafo.bfs(num, num2);
            if (v.size() == 1){
                str = "Não existe um caminho possivel entre essas duas paragens";
            }else {
                str = "Tem que ir pelas segintes paragens: " + codigo;
                for (int i = v.size() - 1; i >= 0; i--) {
                    str += " " + actualPath.getMapStops().at(i).at(0);
                }
                str += " "+codigo2;
            }
            cout << str << endl;
            break;
        }
        case 2: {
            choice = -1;
            string str;
            vector<int> v = grafo.dijkstra(num, num2);
            if (v.size() == 1) {
                str = "Não existe um caminho possivel entre essas duas paragens";
            } else {
                str = "Tem que ir pelas segintes paragens: " + codigo;
                for (int i = v.size() - 1; i >= 0; i--) {
                    str += " " + actualPath.getMapStops().at(i).at(0);
                }
                str += " "+codigo2;
            }
            cout << str << endl;
            break;
        }
        case 3:{
            choice = -1;
            string str;
            vector<int> v = grafo.leastChange(num, num2);
            if (v.size() == 1) {
                str = "Não existe um caminho possivel entre essas duas paragens";
            } else {
                str = "Tem que ir pelas segintes paragens: " + codigo;
                for (int i = v.size() - 1; i >= 0; i--) {
                    str += " " + actualPath.getMapStops().at(i).at(0);
                }
                str += " "+codigo2;
            }
            cout << str << endl;
            break;
        }
        case 4 :{
            choice = -1;
            string str;
            vector<int> v = grafo.leastZones(num, num2);
            if (v.size() == 1) {
                str = "Não existe um caminho possivel entre essas duas paragens";
            } else {
                str = "Tem que ir pelas segintes paragens: " + codigo;
                for (int i = v.size() - 1; i >= 0; i--) {
                    str += " " + actualPath.getMapStops().at(i).at(0);
                }
                str += " "+codigo2;
            }
            cout << str << endl;
            break;
        }
        default:
            choice = -1;
            mainMenu();
            break;
    }

    mainMenu();
}

void Menu::bestPath() {
    cout << "=====================================" << endl;
    cout << "               AED - G70             " << endl;
    cout << "=====================================" << endl;
    cout << " [1] - Menor numero de paragens      " << endl;
    cout << " [2] - Menor mudanca de linhas       " << endl;
    cout << " [3] - Menor mudanca de zonas        " << endl;
    clearBuffer();
    cin >> choice;
    while(choice < 1 || choice > 3) {
        cout << "Comando inexistente, usar um novo valor: "; clearBuffer(); cin >> choice;
    }
    switch(choice){
        case 1:
            choice = -1;
            //grafo.bfs(21);
            break;
        case 2:
            choice = -1;
            //aqui metes a funcao com menor mudanca de linhas(dhristika com o nome das linhas)
            break;
        case 3:
            choice = -1;
            //aqui metes a funcao com menor mudanca de zonas(mesma cena da anterior so que relacionada a zona)
            break;
        default:
            choice = -1;
            mainMenu();
            break;
    }
}

