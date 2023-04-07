#include "MaxFlowUserInput.h"
MaxFlowUserInput::MaxFlowUserInput(int &currMenuPage, Graph &railway) :  MenuItem(currMenuPage, railway) {}

void MaxFlowUserInput::execute() {
    Vertex *orig = nullptr, *dest = nullptr;

    cin.ignore(2000, '\n');
    cout << "\033[34mInsert the name of the origin station: " << "\033[0m";
    fetchStation(&orig,railway);

    cout << "\033[34mInsert the name of the destination station: " << "\033[0m";
    fetchStation(&dest,railway);

    auto flow = railway->getMaxFlow(orig, dest);
    drawResults();
    drawFlow(flow);
    vector<Vertex*> vertexes;
    vertexes.push_back(orig);
    drawFooter(railway->fetchUsedEdges(vertexes));
}