#include "MinCostMaxFlow.h"

MinCostMaxFlow::MinCostMaxFlow(int &currMenuPage, Graph &railway) : MenuItem(currMenuPage, railway) {}

void MinCostMaxFlow::execute() {
    system("clear");
    Vertex *orig = nullptr, *dest = nullptr;
    int cost, flow;

    cin.ignore(2000, '\n');
    cout << "\033[34mInsert the name of the origin station: " << "\033[0m";
    fetchStation(&orig,railway);

    cout << "\033[34mInsert the name of the destination station: " << "\033[0m";
    fetchStation(&dest,railway);

    railway->minCostMaxFlow(orig, dest);

    cost = railway->computeCost(orig);
    flow = railway->getVertexFlow(dest);

    if (flow > 0) {
        drawResults();
        drawCost(cost);
        drawFlow(flow);
        drawFooter();
    }
    else {
        cout << "\033[31mStation " << orig->getId() << " can't reach station " << dest->getId()<< "\033[0m" << endl << endl;
    }

}

