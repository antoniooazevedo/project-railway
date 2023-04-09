#include "ReducedConnectivityMaxFlow.h"

ReducedConnectivityMaxFlow::ReducedConnectivityMaxFlow(int &currMenuPage, Graph &gh) : MenuItem(currMenuPage, gh){}

void ReducedConnectivityMaxFlow::execute() {
    string amount;
    Vertex *orig = nullptr, *dest = nullptr;
    auto vertexSet = railway->getVertexSet();
    cin.ignore(2000, '\n');

    while (true){
        cout << "\033[34mInsert the name of the origin station: " << "\033[0m";
        fetchStation(&orig,railway);

        cout << "\033[34mInsert the name of the destination station: " << "\033[0m";
        fetchStation(&dest,railway);
        break;
    }
    int flow = railway->getMaxFlow(orig,dest);
    drawResults();
    drawFlow(flow);
    vector<Vertex*> vertexes;
    vertexes.push_back(orig);
    if (flow > 0){
        drawFooter(railway->fetchUsedEdges(vertexes));
    }
    else{
        cout << "|\033[40m<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\033[0m|\n"
             << "|\033[40m_____________________________________________\033[0m|\n";
        string dummy;
        cout << "\033[33mInput anything to continue: \033[0m";
        getline(cin, dummy);
    }
}