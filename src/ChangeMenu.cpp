#include "ChangeMenu.h"

/**
 * Constructor of ChangeMenu a class that extends MenuItem
 * @param currMenuPage current page of the menu
 * @param database database that stores all the information
 * @param nextMenu the page we want to change to
 */
ChangeMenu::ChangeMenu(int &currMenuPage, Graph &railway, int nextMenu) : MenuItem(currMenuPage, railway)
{
    this->nextMenu = nextMenu;
}

void ChangeMenu::pickEdgesToDisable() {
    system("clear");

    Vertex *orig, *dest;
    cin.ignore(2000, '\n');

    while(true){
        orig = dest = nullptr;

        cout << "\033[33mWhen you are done, insert d/D on any of the stations!\033[0m";

        cout << endl;
        cout << "\033[34mInsert the name of the origin station: \033[0m";
        if (!fetchStation(&orig, railway, 'd'))
            return;

        cout << "\033[34mInsert the name of the destination station: \033[0m";
        if (!fetchStation(&dest, railway, 'd'))
            return;

        bool not_found = true;
        for (Edge *e: orig->getAdj()){
            if (e->getDest() == dest){
                e->setDisabled(true);
                e->getReverse()->setDisabled(true);
                not_found = false;
                break;
            }
        }

        if (not_found){
            cout << "\033[31mThere is no edge between the two stations\033[0m"  << endl;
            cout << endl;
            continue;
        }
    }
}

void ChangeMenu::enableAllEdges() {
    for (const auto& v: railway->getVertexSet()) {
        for (Edge *e: v.second->getAdj()) {
            e->setDisabled(false);
        }
    }
}

void ChangeMenu::execute() {
    if (nextMenu == 3) pickEdgesToDisable();
    if (*currMenuPage == 3) enableAllEdges();
    *(this->currMenuPage) = nextMenu;
}