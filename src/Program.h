#ifndef PROJECT_RAILWAY_PROGRAM_H
#define PROJECT_RAILWAY_PROGRAM_H

#include "Graph.h"
#include "Menu.h"
#include <string>
#include <vector>
#include <iostream>
#include "MinCostMaxFlow.h"

using namespace std;

class Program
{
private:
    /** @var menu page we are currently in */
    int currMenuPage;

    /** @var vector of all the program's menus */
    vector<Menu> menus;

    /** @var program's database where airports, airlines and the flights graph are stored*/
    Graph railway;

    void createMainMenu();
    void createMenu1();
    void createMenu2();

public:
    Program(Graph &railway);
    void run();
    bool getMenuOption(int &option, int nButtons);
    void cleanMenus();
};

#endif //PROJECT_RAILWAY_PROGRAM_H
