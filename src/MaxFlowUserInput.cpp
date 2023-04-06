#include "MaxFlowUserInput.h"
MaxFlowUserInput::MaxFlowUserInput(int &currMenuPage, Graph &gh) : MenuItem(currMenuPage, gh){
    this->graph = gh;
}

void MaxFlowUserInput::execute() {
    string orig = "", dest = "";

    cin.ignore(2000, '\n');
    while (true){
        cout << "\033[34mInsert the name of the origin station: " << "\033[0m";
        std::getline(cin, orig);

        if (graph.findVertex(orig) == nullptr){
            cout << "\033[31m - Station not found - " << "\033[0m";
            cout << endl;
            cout << endl;
            continue;
        }
        break;
    }

    while (true){
        cout << "\033[34mInsert the name of the destination station: " << "\033[0m";
        std::getline(cin, dest);

        if (graph.findVertex(dest) == nullptr){
            cout << "\033[31m - Station not found - " << "\033[0m";
            cout << endl;
            cout << endl;
            continue;
        }
        break;
    }

    auto flow = graph.getMaxFlow(graph.findVertex(orig), graph.findVertex(dest));
    int size = flow > 10 ? 2 : 1;
    cout << " _____________________________________________ \n"
         << "|\033[40m                   Results                   \033[0m|\n"
         << "|\033[40m_____________________________________________\033[0m|\n"
         << "|\033[100m Max-Flow: " << flow<< string(34 - size, ' ') << "\033[0m|\n"
         << "|\033[100m\033[40m---------------------------------------------\033[0m|\n"
         << "|\033[40m<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\033[0m|\n"
         << "|\033[40m_____________________________________________\033[0m|\n"
         << "Input anything to continue: ";
    string w8Input;
    getline(cin,w8Input);
}