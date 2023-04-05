#include "MaxFlowUserInput.h"

#include "utils.cpp"

MaxFlowUserInput::MaxFlowUserInput(int &currMenuPage, Graph &gh) : MenuItem(currMenuPage, gh){
    this->graph = gh;
}

void MaxFlowUserInput::execute() {
    string orig = "", dest = "";

    cin.ignore(2000, '\n');
    while (graph.findVertex(orig) == nullptr){
        cout << "Origin: ";
        std::getline(cin, orig);
        transform(orig.begin(), orig.end(), orig.begin(), ::tolower);

        if (graph.findVertex(orig) == nullptr){
            cout << "Station not found";
            cout << endl;
        }
    }

    while (graph.findVertex(dest) == nullptr){
        cout << "Destination: ";
        std::getline(cin, dest);
        transform(dest.begin(), dest.end(), dest.begin(), ::tolower);

        if (graph.findVertex(dest) == nullptr){
            cout << "Station not found";
            cout << endl;
        }
    }

    auto flow = graph.getMaxFlow(graph.findVertex(orig), graph.findVertex(dest));
    cout << "\nMax flow: " << flow << endl;
}