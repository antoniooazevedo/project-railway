//
// Created by work on 05-04-2023.
//

#include "SinglePointMaxFlow.h"

SinglePointMaxFlow::SinglePointMaxFlow(int &currMenuPage, Graph &gh) : MenuItem(currMenuPage, gh){}

void SinglePointMaxFlow::execute() {
    string station;
    auto vertexSet = railway->getVertexSet();
    auto extremes = railway->getExtremes();
    int flow;

    cin.ignore(2000, '\n');

    while (true){
        cout << "Please input the desired station: ";
        getline(cin, station);
        cout << endl;

        if (railway->findVertex(station) != nullptr){
            break;
        }
        cout << "That station does not exist\n \n";
    }

    auto dest = railway->findVertex(station);

    // creating super node
    railway->addVertex("Super Node");

    Vertex *superNode = railway->findVertex("Super Node");

    // adding super edges
    for (auto e: extremes){
        if (e != dest) railway->addBidirectionalEdge("Super Node", e->getId(), 9999, STANDARD);
    }

    // running maxflow on super node to destiny
    flow = railway->getMaxFlow(superNode, dest);

    for (Vertex *extreme: extremes) {
        extreme->removeEdge("Super Node");
    }

    //removing super node and super edges
    railway->removeVertex("Super Node");

    cout << "Flow for node: " << flow << endl;
}