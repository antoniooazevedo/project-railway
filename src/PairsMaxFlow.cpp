
#include "PairsMaxFlow.h"

PairsMaxFlow::PairsMaxFlow(int &currMenuPage, Graph &railway) : MenuItem(currMenuPage, railway){}


void PairsMaxFlow::execute() {
    cin.ignore(2000, '\n');
    auto extremes = railway->getExtremes();
    result_vector.clear();
    int flow = 0;
    for (auto v1: extremes){
        for (auto v2: extremes){
            if (v1->getId() < v2->getId()){
                pair<Vertex*, Vertex*> insidePair = {v1, v2};
                flow = railway->getMaxFlow(v1, v2);
                this->result_vector.emplace_back(insidePair, flow);
            }
        }
    }
    std::sort(result_vector.begin(), result_vector.end(), sortResultVector);

    drawResults();
    drawFlow(result_vector[0].second);
    cout << "|\033[100m Pairs with Max-Flow:                        \033[0m|\n";

    for (auto pa: result_vector) {
        auto s = pa.first.first->getId() + " <-> " + pa.first.second->getId();
        cout.clear();
        if (pa.second == result_vector[0].second) cout << "|\033[100m   -->   " << s << string(36 - getLen(s), ' ') << "\033[0m|\n";
    }
    drawFooter();
}