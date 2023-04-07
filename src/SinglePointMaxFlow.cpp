#include "SinglePointMaxFlow.h"

SinglePointMaxFlow::SinglePointMaxFlow(int &currMenuPage, Graph &gh) : MenuItem(currMenuPage, gh){}

void SinglePointMaxFlow::execute() {
    string station;
    auto vertexSet = railway->getVertexSet();
    auto extremes = railway->getExtremes();
    int flow; bool control_ignore = true;
    while (true){
        if (control_ignore) cin.ignore(2000, '\n');
        cout << "\033[34mInsert the name of the origin station: " << "\033[0m";
        getline(cin, station);
        if (railway->findVertex(station) != nullptr){
            break;
        }
        cout << endl;
        cout << "\033[31m - Station not found - " << "\033[0m";
        cout << endl;
        cout << endl;
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

    int size = flow > 10 ? 2 : 1;
    cout << " _____________________________________________ \n"
         << "|\033[40m                   Results                   \033[0m|\n"
         << "|\033[40m_____________________________________________\033[0m|\n"
         << "|\033[100m Max-Flow: " << flow<< string(34 - size, ' ') << "\033[0m|\n"
         << "|\033[100m\033[40m---------------------------------------------\033[0m|\n"
         << "|\033[40m<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\033[0m|\n"
         << "|\033[40m_____________________________________________\033[0m|\n"
         << "Input anything to continue: ";
    string w8Input;
    getline(cin,w8Input);
}