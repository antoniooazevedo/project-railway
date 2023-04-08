#include "TopSegmentFailure.h"

TopSegmentFailure::TopSegmentFailure(int &currMenuPage, Graph &gh) : MenuItem(currMenuPage, gh){
    getAllStations();
}

bool sortResultVector(const pair<Vertex*, int> &p1, const pair<Vertex*, int> &p2){
    return (p1.second > p2.second);
}

void TopSegmentFailure::disabledEdgesMaxFlow(bool disabled) {
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
        if (disabled)
            pa.second->setDisabledFlow(railway->getMaxFlow(railway->findVertex("Super Node"), pa.second));
        else
            pa.second->setMaxFlow(railway->getMaxFlow(railway->findVertex("Super Node"), pa.second));

        for (Vertex *extreme: extremes) {
            extreme->removeEdge("Super Node");
        }

        //removing super node and super edges
        railway->removeVertex("Super Node");
    }
}

void TopSegmentFailure::execute() {
    vector<pair<Edge*, vector<Vertex*>>> topResults;
    vector<Vertex*> topResultsPerEdge;

    // TODO: Ask the user for the edge he wants to get the report of
    // TODO: Change this to calculate only one edge

    disabledEdges = fetchDisabledEdges();

    vector<Edge*> v;

    for (auto e: disabledEdges) {
        v.push_back(e);
    }

    Edge *e = pickAnEdge(v);
    auto vertexSet = railway->getVertexSet();
    enableEdges();
    disabledEdgesMaxFlow(false);

    for (Edge *e: disabledEdges) {
        topResultsPerEdge.clear();

        e->setDisabled(true);
        e->getReverse()->setDisabled(true);

        disabledEdgesMaxFlow(true);

        sort(stations.begin(), stations.end(), [](Vertex* s1, Vertex* s2) {
            return s1->getMaxFlow() - s1->getDisabledFlow() > s2->getMaxFlow() - s2->getDisabledFlow();
        });

        for (int i = 0; i < 10; i++) {
            topResultsPerEdge.push_back(stations[i]);
        }

        topResults.emplace_back(e, topResultsPerEdge);

        e->setDisabled(false);
        e->getReverse()->setDisabled(false);
    }

    disableEdges();
}

set<Edge*> TopSegmentFailure::fetchDisabledEdges() {
    set<Edge*> allDisabledEdges;

    for (const auto& v: railway->getVertexSet()) {
        for (Edge *e: v.second->getAdj()) {
            if (e->getDisabled() && allDisabledEdges.find(e->getReverse()) == allDisabledEdges.end()) {
                allDisabledEdges.insert(e);
            }
        }
    }

    return allDisabledEdges;
}

void TopSegmentFailure::enableEdges() {
    for (Edge *e: disabledEdges) {
        e->setDisabled(false);
        e->getReverse()->setDisabled(false);
    }
}

void TopSegmentFailure::getAllStations() {
    for (const auto& v: railway->getVertexSet())
        stations.push_back(v.second);
}

void TopSegmentFailure::disableEdges() {
    for (Edge *e: disabledEdges) {
        e->setDisabled(true);
        e->getReverse()->setDisabled(true);
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
