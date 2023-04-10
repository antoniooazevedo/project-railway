#ifndef PROJECT_RAILWAY_MENU_H
#define PROJECT_RAILWAY_MENU_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "MenuItem.h"

using namespace std;

class Menu
{
private:
    /** @var buttons to be printed by the menu */
    vector<string> buttons;

    /** @var action to be taken when a certain option of the menu is chosen */
    vector<MenuItem *> actions;

public:
    Menu(string path);
    vector<string> getButtons();
    void draw() const;
    void addMenuItem(MenuItem *menuItem);
    void doAction(int option);
    vector<MenuItem *> getActions();
};

#endif //PROJECT_RAILWAY_MENU_H
