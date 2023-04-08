#include "ReducedConnectivityMaxFlow.h"

ReducedConnectivityMaxFlow::ReducedConnectivityMaxFlow(int &currMenuPage, Graph &gh) : MenuItem(currMenuPage, gh){}

void ReducedConnectivityMaxFlow::execute() {
    string amount, orig, dest;
    auto vertexSet = railway->getVertexSet();
    cin.ignore(2000, '\n');

    while (true){
        cout << "Please input desired origin station: ";
        getline(cin, orig);
        cout << endl;

        if (railway->findVertex(orig) == nullptr){
            cout << "That station does not exist\n \n";
            continue;
        }

        cout << "Please input desired destination station: ";
        getline(cin, dest);
        cout << endl;

        if (railway->findVertex(dest) == nullptr){
            cout << "That station does not exist\n \n";
            continue;
        }

        break;
    }
    auto v1 = railway->findVertex(orig), v2 = railway->findVertex(dest);
    int flow = railway->getMaxFlow(v1,v2);
    cout << "flow with restricted graph: " << flow << endl;
}