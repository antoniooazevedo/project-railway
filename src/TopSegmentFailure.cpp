#include "TopSegmentFailure.h"

TopSegmentFailure::TopSegmentFailure(int &currMenuPage, Graph &gh) : MenuItem(currMenuPage, gh){}

bool sortResultVector(const pair<Vertex*, int> &p1, const pair<Vertex*, int> &p2){
    return (p1.second > p2.second);
}

vector<pair<Vertex*, int>> TopSegmentFailure::fullGraphMaxFlow() {
    auto vertexSet = railway->getVertexSet();
    auto extremes = railway->getExtremes();
    vector<pair<Vertex*, int>> results;

    for (auto &pa: vertexSet){
        // creating super node
        railway->addVertex("Super Node");

        // adding super edges
        for (auto e: extremes){
            if (e != pa.second) railway->addBidirectionalEdge("Super Node", e->getId(), 9999, STANDARD);
        }

        // running maxflow on super node to destiny
        results.emplace_back(pa.second,railway->getMaxFlow(railway->findVertex("Super Node"), pa.second));

        //removing super node and super edges
        railway->removeVertex("Super Node");
    }

    std::sort(results.begin(), results.end(), sortResultVector);
    return results;
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
    auto original_results = fullGraphMaxFlow();

    for (auto &pa: vertexSet){
        for (auto &e: pa.second->getAdj()){
            if (pa.second->getId() < e->getDest()->getId()){
                e->setDisabled(true);
                e->getReverse()->setDisabled(true);

                auto particular_results = fullGraphMaxFlow();

                e->setDisabled(false);
                e->getReverse()->setDisabled(false);

                auto deltas = getDelta(original_results, particular_results);

                cout << pa.second->getId() << " <-> " << e->getDest()->getId() << endl << endl;
                for (int i = 0; i <= 2; i++){
                    cout << "Station: " << deltas[i].first->getId() << "  Loss in flow: " << deltas[i].second << endl;
                }
                cout << "----------------------------------------\n\n\n";
            }
        }
    }
}