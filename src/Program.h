#ifndef PROJECT_RAILWAY_PROGRAM_H
#define PROJECT_RAILWAY_PROGRAM_H

#include "Graph.h"
#include "Menu.h"
#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include <set>
#include "ExampleGraphs.h"
#include "Menu.h"
#include "MenuItem.h"
#include "ChangeMenu.h"
#include "PairsMaxFlow.h"
#include "MaxFlowUserInput.h"
#include "SinglePointMaxFlow.h"
#include "ReducedConnectivityMaxFlow.h"
#include "TopSegmentFailure.h"
#include "Scraper.h"
#include "Municipalities.h"
#include "utils.h"

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
    void createMenu3();

public:
    Program();
    void run();
    bool getMenuOption(int &option, int nButtons);
    void cleanMenus();
};

#endif //PROJECT_RAILWAY_PROGRAM_H
