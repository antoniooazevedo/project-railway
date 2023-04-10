#ifndef PROJECT_RAILWAY_PROGRAM_H
#define PROJECT_RAILWAY_PROGRAM_H

#include "graph/Graph.h"
#include "menuItems/general/Menu.h"
#include <string>
#include <vector>
#include <iostream>
#include "menuItems/costOptimization/MinCostMaxFlow.h"
#include <limits>
#include <set>
#include "ExampleGraphs.h"
#include "menuItems/general/Menu.h"
#include "menuItems/general/MenuItem.h"
#include "menuItems/general/ChangeMenu.h"
#include "menuItems/basicServices/PairsMaxFlow.h"
#include "menuItems/basicServices/MaxFlowUserInput.h"
#include "menuItems/basicServices/SinglePointMaxFlow.h"
#include "menuItems/reliabilityAndSensivity/ReducedConnectivityMaxFlow.h"
#include "menuItems/reliabilityAndSensivity/TopSegmentFailure.h"
#include "Scraper.h"
#include "menuItems/basicServices/Municipalities.h"
#include "utils.h"
#include "menuItems/basicServices/District.h"


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
    void createMenu4();
    void createMenu5();
    void createMenuReducedConnectivity();

public:
    Program();
    void run();
    bool getMenuOption(int &option, int nButtons);
    void cleanMenus();
};

#endif //PROJECT_RAILWAY_PROGRAM_H
