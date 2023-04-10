#ifndef PROJECT_RAILWAY_CHANGEMENU_H
#define PROJECT_RAILWAY_CHANGEMENU_H

#include "MenuItem.h"
#include "utils.h"

using namespace std;

class ChangeMenu : public MenuItem
{
private:
    /** @var Menu to change to */
    int nextMenu;

    /**
     * Let's the user choose the edges that he wants to disable in the whole graph for future algorithms of reduced
     * connectivity
     */
    void pickEdgesToDisable();

    /**
     * Enables all edges of the graph
     */
    void enableAllEdges();

public:
    /**
     * Constructor of ChangeMenu a class that extends MenuItem
     * @param currMenuPage current page of the menu
     * @param database database that stores all the information
     * @param nextMenu the page we want to change to
     */
    ChangeMenu(int &currMenuPage, Graph &railway, int nextMenu);

    /**
     * Changes to the menu of the value nextMenu. If it corresponds to the menu of reduced connectivity then maximum
     * flow that reaches each station is calculated beforehand
     */
    void execute() override;
};

#endif //PROJECT_RAILWAY_CHANGEMENU_H
