#ifndef PROJECT_RAILWAY_MENUITEM_H
#define PROJECT_RAILWAY_MENUITEM_H

#include "graph/Graph.h"

using namespace std;

class MenuItem
{
protected:
    /** @var menu we are currently in*/
    int *currMenuPage;
    /** @var pointer to the program's database*/
    Graph *railway;

public:
    MenuItem(int &currMenuPage, Graph &railway);
    virtual void execute() = 0;
};

#endif //PROJECT_RAILWAY_MENUITEM_H
