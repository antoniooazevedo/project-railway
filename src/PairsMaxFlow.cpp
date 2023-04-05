
#include "PairsMaxFlow.h"
#include "Scraper.h"

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
    cout << "stations: " << result_vector[0].first.first->getId() << ", " << result_vector[0].first.second->getId() << endl;
    cout << "Max Flow: " << result_vector[0].second << endl;
}
