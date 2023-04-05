//
// Created by work on 05-04-2023.
//

#include "ReducedConnectivityMaxFlow.h"
#include <ctime>

ReducedConnectivityMaxFlow::ReducedConnectivityMaxFlow(int &currMenuPage, Graph &gh) : MenuItem(currMenuPage, gh){}

void ReducedConnectivityMaxFlow::execute() {
    string amount, orig, dest;
    auto vertexSet = railway->getVertexSet();
    int count;
    bool control_ignore = true;

    while (true){
        if (control_ignore) cin.ignore(2000, '\n');
        cout << "Please input desired amount: ";
        getline(cin, amount);
        cout << endl;
        control_ignore = false;
        try{
           count = stoi(amount);
        }catch (invalid_argument){
            cout << "Invalid Input\n";
            continue;
        }catch (out_of_range){
            cout << "Invalid Input\n";
            continue;
        }

        if (count < 0){
            cout << "Invalid Input\n";
            continue;
        }

        break;
    }
    srand((unsigned) time(0));

    while(count > 0){
        unsigned int num1 = rand() % vertexSet.size();

        for (auto &pa: vertexSet){
            num1--;
            if (num1 <= 0 && pa.second->getAdj().size() > 0){
                unsigned int num2 = rand() % pa.second->getAdj().size();

                if (pa.second->getAdj()[num2]->getDisabled()) continue;

                pa.second->getAdj()[num2]->setDisabled(true);
                pa.second->getAdj()[num2]->getReverse()->setDisabled(true);
                break;
            }
        }
        count--;
    }

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

    for (auto &pa: railway->getVertexSet()){
        for (auto &e : pa.second->getAdj()){
            e->setDisabled(false);
            e->getReverse()->setDisabled(false);
        }
    }
}