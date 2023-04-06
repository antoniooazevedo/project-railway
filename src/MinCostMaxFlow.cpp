#include "MinCostMaxFlow.h"

MinCostMaxFlow::MinCostMaxFlow(int &currMenuPage, Graph &railway) : MenuItem(currMenuPage, railway) {}

void MinCostMaxFlow::execute() {
    system("clear");
    Vertex *orig, *dest;
    string dummy;
    int cost, flow;

    cin.ignore(2000, '\n');
    cout << "Input the origin station: ";
    orig = fetchStation();

    cout << "Input the destination station: ";
    dest = fetchStation();

    railway->minCostMaxFlow(orig, dest);

    cost = railway->computeCost(orig);
    flow = railway->getVertexFlow(dest);

    if (flow > 0) {
        cout << "Total cost: " << cost << endl;
        cout << "Total flow: " << flow << endl << endl;
    }
    else {
        cout << "Station " << orig->getId() << " can't reach station " << dest->getId() << endl << endl;
    }

    cout << "Input anything to go back ";
    getline(cin, dummy);
}

Vertex *MinCostMaxFlow::fetchStation() const {
    Vertex *v;
    string input;

    while (true) {
        getline(cin, input);

        system("clear");

        v = railway->findVertex(input);
        if (v != nullptr)
            break;
        cout << "There isn't a station named: " << input << endl;
        cout << "Input another station: ";
    }

    return v;
}
