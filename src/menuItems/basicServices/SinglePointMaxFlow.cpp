#include "SinglePointMaxFlow.h"

SinglePointMaxFlow::SinglePointMaxFlow(int &currMenuPage, Graph &railway) : MenuItem(currMenuPage, railway){}

void SinglePointMaxFlow::execute() {
    system("clear");
    Vertex *dest = nullptr;
    auto vertexSet = railway->getVertexSet();
    auto extremes = railway->getExtremes();
    int flow;

    cin.ignore(2000, '\n');

    cout << "\033[34mInsert the name of the destination station: " << "\033[0m";
    fetchStation(&dest,railway);

    Vertex *superSource = railway->addSuperSource(dest);

    // running maxflow on super node to destiny
    flow = railway->getMaxFlow(superSource, dest);

    railway->removeSuperSource(superSource);

    drawResults();
    drawFlow(flow);
    vector<Vertex*> vertexes;
    for (auto e: extremes){
        if (e != dest) vertexes.push_back(e);
    }
    drawFooter(railway->fetchUsedEdges(vertexes));
}