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

void pickEdgesToDisable(Graph &railway) {
    string orig, dest;
    bool control_ignore = true;
    cout << "When you are done, insert 'd' as the origin or destination station" << endl;
    cin.ignore(2000, '\n');

    while(true){
        cout << "Insert the name of the origin station: ";
        getline(cin, orig);
        cout << "\nInsert the name of the destination station: ";
        getline(cin, dest);
        control_ignore = false;

        if (orig == "d" || dest == "d" || orig == "D" || dest == "D") break;

        if(railway.findVertex(orig) == nullptr || railway.findVertex(dest) == nullptr){
            cout << "Invalid station name" << endl;
            continue;
        }
        bool not_found = true;
        for (auto &e: railway.findVertex(orig)->getAdj()){
            if (e->getDest()->getId()==dest){
                e->setDisabled(true);
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
    if (*currMenuPage == 3) pickEdgesToDisable(*railway);
}