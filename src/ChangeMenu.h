#ifndef PROJECT_RAILWAY_CHANGEMENU_H
#define PROJECT_RAILWAY_CHANGEMENU_H

#include "MenuItem.h"

using namespace std;

class ChangeMenu : public MenuItem
{
private:
    /** @var Menu to change to */
    int nextMenu;

public:
    ChangeMenu(int &currMenuPage, Graph &railway, int nextMenu);
    void execute() override;
};

#endif //PROJECT_RAILWAY_CHANGEMENU_H
