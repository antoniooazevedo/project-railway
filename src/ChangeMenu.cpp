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

/**
 * @brief Changes the current menu page to another page
 * complexity O(1)
 */

void ChangeMenu::pickEdgesToDisable() {
    Vertex *orig, *dest;
    cout << "When you are done, insert 'd' as the origin or destination station" << endl;
    cin.ignore(2000, '\n');

    while(true){
        orig = dest = nullptr;

        cout << "Insert the name of the origin station: ";
        if (!fetchStation(&orig, railway, 'd'))
            return;

        cout << "\nInsert the name of the destination station: ";
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
            cout << "There is no edge between the two stations" << endl;
            continue;
        }
    }
}

void ChangeMenu::execute()
{
    *(this->currMenuPage) = nextMenu;
    if (*currMenuPage == 3) pickEdgesToDisable();
}