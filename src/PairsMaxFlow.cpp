

#include "PairsMaxFlow.h"
#include <iomanip>

PairsMaxFlow::PairsMaxFlow(int &currMenuPage, Graph &gh) : MenuItem(currMenuPage, gh){
    this->graph = gh;
}

bool sortResultVector(const pair<pair<Vertex*, Vertex*>, int> &p1, const pair<pair<Vertex*, Vertex*>, int> &p2){
    return (p1.second > p2.second);
}

void PairsMaxFlow::execute() {
    auto extremes = graph.getExtremes();
    result_vector.clear();
    int flow = 0;
    for (auto v1: extremes){
        for (auto v2: extremes){
            if (v1->getId() < v2->getId()){
                pair<Vertex*, Vertex*> insidePair = {v1, v2};
                flow = graph.getMaxFlow(v1, v2);
                this->result_vector.emplace_back(insidePair, flow);
            }
        }
    }
    std::sort(result_vector.begin(), result_vector.end(), sortResultVector);

    cout << " _____________________________________________ \n"
         << "|\033[40m                   Results                   \033[0m|\n"
         << "|\033[40m_____________________________________________\033[0m|\n";
    cout << "|\033[100m Max-Flow: " << result_vector[0].second << "                                \033[0m|\n"
         << "|\033[100m\033[37m---------------------------------------------\033[0m|\n";
    cout << "|\033[100m Pairs with Max-Flow:                        \033[0m|\n";

    for (auto pa: result_vector) {
        auto s = pa.first.first->getId() + " <-> " + pa.first.second->getId();
        cout.clear();
        if (pa.second == result_vector[0].second) cout << "|\033[100m   -->   " << s << string(36 - s.size(), ' ') << "\033[0m|\n";
    }
    string useless;
    cin >> useless;
}