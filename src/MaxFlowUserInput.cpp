#include "MaxFlowUserInput.h"

#include "utils.cpp"

MaxFlowUserInput::MaxFlowUserInput(int &currMenuPage, Graph &gh) : MenuItem(currMenuPage, gh){
    this->graph = gh;
}

void MaxFlowUserInput::execute() {
    string orig = "", dest = "";

    cin.ignore(2000, '\n');
    while (true){
        cout << "Origin: ";
        std::getline(cin, orig);

        if (graph.findVertex(orig) == nullptr){
            cout << "Station not found";
            cout << endl;
            continue;
        }
        break;
    }

    while (true){
        cout << "Destination: ";
        std::getline(cin, dest);

        if (graph.findVertex(dest) == nullptr){
            cout << "Station not found";
            cout << endl;
            continue;
        }
        break;
    }

    auto flow = graph.getMaxFlow(graph.findVertex(orig), graph.findVertex(dest));
    cout << "\nMax flow: " << flow << endl;
}