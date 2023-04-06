#include "SinglePointMaxFlow.h"

SinglePointMaxFlow::SinglePointMaxFlow(int &currMenuPage, Graph &gh) : MenuItem(currMenuPage, gh){}

void SinglePointMaxFlow::execute() {
    string station;
    auto vertexSet = railway->getVertexSet();
    auto extremes = railway->getExtremes();
    int flow; bool control_ignore = true;
    while (true){
        if (control_ignore) cin.ignore(2000, '\n');
        cout << "Please input desired station: ";
        getline(cin, station);
        cout << endl;

        if (railway->findVertex(station) != nullptr){
            break;
        }
        cout << "That station does not exist\n \n";
        control_ignore = false;
    }

    auto v = railway->findVertex(station);

    // creating super node
    railway->addVertex("Super Node");

    // adding super edges
    for (auto e: extremes){
        if (e != v) railway->addBidirectionalEdge("Super Node", e->getId(), 9999, STANDARD);
    }

    // running maxflow on super node to destiny
    flow = railway->getMaxFlow(railway->findVertex("Super Node"), v);

    //removing super node and super edges
    railway->removeVertex("Super Node");


    cout << "flow for node: " << flow << endl;
}