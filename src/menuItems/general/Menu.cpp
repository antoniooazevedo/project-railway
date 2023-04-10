#include "Menu.h"

/**Constructor of the Menu, reads a file with buttons and adds them to a vector of strings
 * @brief Constructor of the Menu
 * @param path the path to the file containing the buttons of the menu
 */
Menu::Menu(string path)
{
    ifstream file(path);
    for (string button; getline(file, button);)
    {
        this->buttons.push_back(button);
    }
}

/**
 * @brief Adds a MenuItem to the menu's actions
 * @param menuItem
 * Time complexity: O(1)
 */
void Menu::addMenuItem(MenuItem *menuItem)
{
    actions.push_back(menuItem);
}

/**
 * @return buttons
 */
vector<string> Menu::getButtons()
{
    return buttons;
}

/**
 * @brief Draws the menu
 * complexity O(N) being N the number of buttons
 */
void Menu::draw() const
{
    system("clear");
    cout<<"\033[0m";
    string display;
    display = " _____________________________________________ \n"
              "|\033[40m                     Menu                    \033[0m|\n"
              "|\033[40m_____________________________________________\033[0m|\n";

    for (int i = 0; i < this->buttons.size(); i++)
    {
        display += "|\033[100m\033[37m---------------------------------------------\033[0m|\n";
        display += "|\033[100m [" + to_string(i + 1) + "] " + this->buttons[i];
        for (int j = 0; j < (39 - this->buttons[i].length()); j++)
            display += " "; // adding spaces to format the menu
        if (i < 9)
            display += ' ';
        display += "\033[0m|\n";
    }
    display += "|\033[100m_____________________________________________\033[0m|\n";
    display += "|\033[40m<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\033[0m|\n";
    display += "|\033[40m_____________________________________________\033[0m|\n";
    cout << display << endl;
}

/**
 * @brief Will execute the action corresponding to the option chosen
 * @param option option chosen
 */
void Menu::doAction(int option)
{
    actions[option]->execute();
}

/**
 * @return the actions of the menu
 */
vector<MenuItem *> Menu::getActions()
{
    return actions;
}
