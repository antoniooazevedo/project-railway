#include "SinglePointMaxFlow.h"

SinglePointMaxFlow::SinglePointMaxFlow(int &currMenuPage, Graph &railway) : MenuItem(currMenuPage, railway){}

void SinglePointMaxFlow::execute() {
    Vertex *dest = nullptr;
    auto vertexSet = railway->getVertexSet();
    auto extremes = railway->getExtremes();
    int flow;

    cin.ignore(2000, '\n');

    cout << "\033[34mInsert the name of the destination station: " << "\033[0m";
    fetchStation(&dest,railway);

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

    drawResults();
    drawFlow(flow);
    vector<Vertex*> vertexes;
    for (auto e: extremes){
        if (e != dest) vertexes.push_back(e);
    }
    drawFooter(railway->fetchUsedEdges(vertexes));
}