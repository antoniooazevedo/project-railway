#include "SinglePointMaxFlow.h"

SinglePointMaxFlow::SinglePointMaxFlow(int &currMenuPage, Graph &railway) : MenuItem(currMenuPage, railway){}

void SinglePointMaxFlow::execute() {
    Vertex *orig = nullptr;
    auto vertexSet = railway->getVertexSet();
    auto extremes = railway->getExtremes();
    int flow; bool control_ignore = true;
    if (control_ignore) cin.ignore(2000, '\n');
    cout << "\033[34mInsert the name of the origin station: " << "\033[0m";
    fetchStation(&orig,railway);

    auto v = orig;

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

    drawResults();
    drawFlow(flow);
    vector<Vertex*> vertexes;
    for (auto e: extremes){
        if (e != v) vertexes.push_back(e);
    }
    drawFooter(railway->fetchUsedEdges(vertexes));
}