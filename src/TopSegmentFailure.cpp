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
        Vertex *superSource = railway->addSuperSource(pa.second);

        pa.second->setDisabledFlow(railway->getMaxFlow(superSource, pa.second));

        for (Vertex *extreme: extremes) {
            extreme->removeEdge("Super Node");
        }

        railway->removeVertex("Super Node");
    }
}

void TopSegmentFailure::execute() {
    pair<Edge*, vector<Vertex*>> edgeReport;
    vector<Vertex*> topVertexes;
    int topK;
    system("clear");

    disabledEdges = fetchDisabledEdges();

    vector<Edge*> v;

    for (auto e: disabledEdges) {
        v.push_back(e);
    }

    cout << "\033[34mPlease input how many stations you would like the top-k report to have (1-" << stations.size() << "): \033[0m";
    getInput(topK);
    while ( 0 >= topK || topK > stations.size()) {
        cout << "\033[31mPlease input a valid number (1-" << stations.size() << "): \033[0m";
        getInput(topK);
    }

    topVertexes.reserve(topK);
    Edge *pickedEdge = pickAnEdge(v);
    auto vertexSet = railway->getVertexSet();
    enableEdges();

    pickedEdge->setDisabled(true);
    pickedEdge->getReverse()->setDisabled(true);

    disabledEdgesMaxFlow(true);

    sort(stations.begin(), stations.end(), [](Vertex* s1, Vertex* s2) {
        return s1->getMaxFlow() - s1->getDisabledFlow() > s2->getMaxFlow() - s2->getDisabledFlow();
    });

    for (int i = 0; i < topK; i++) {
        topVertexes.push_back(stations[i]);
    }

    topNode(topVertexes);

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
