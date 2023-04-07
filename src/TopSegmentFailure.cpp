#include "TopSegmentFailure.h"

TopSegmentFailure::TopSegmentFailure(int &currMenuPage, Graph &gh) : MenuItem(currMenuPage, gh){}

bool sortResultVector(const pair<Vertex*, int> &p1, const pair<Vertex*, int> &p2){
    return (p1.second > p2.second);
}

void TopSegmentFailure::fullGraphMaxFlow() {
    auto vertexSet = railway->getVertexSet();
    auto extremes = railway->getExtremes();

    for (auto &pa: vertexSet){
        // creating super node
        railway->addVertex("Super Node");

        // adding super edges
        for (auto e: extremes){
            if (e != pa.second) railway->addBidirectionalEdge("Super Node", e->getId(), 9999, STANDARD);
        }

        // running maxflow on super node to destiny
        pa.second->setMaxFlow(railway->getMaxFlow(railway->findVertex("Super Node"), pa.second));

        for (Vertex *extreme: extremes) {
            extreme->removeEdge("Super Node");
        }

        //removing super node and super edges
        railway->removeVertex("Super Node");
    }
}

vector<pair<Vertex*, int>> getDelta(const vector<pair<Vertex*, int>> &original_v, const vector<pair<Vertex*, int>> &particular_v){
    vector<pair<Vertex*, int>> deltas;

    for (auto &original: original_v){
        for (auto &particular: particular_v){
            if (original.first == particular.first){
                deltas.emplace_back(original.first, original.second - particular.second);
            }
        }
    }

    std::sort(deltas.begin(), deltas.end(), sortResultVector);
    return deltas;
}

void TopSegmentFailure::execute() {
    auto vertexSet = railway->getVertexSet();
    fullGraphMaxFlow();

}