//
// Created by work on 04-04-2023.
//

#ifndef PROJECT_RAILWAY_PAIRSMAXFLOW_H
#define PROJECT_RAILWAY_PAIRSMAXFLOW_H

#include "Graph.h"
#include "MenuItem.h"

using namespace std;


class PairsMaxFlow : public MenuItem{
private:
    Graph graph;
    vector<pair<pair<Vertex*, Vertex*>, int>> result_vector;
public:
    PairsMaxFlow(int &currMenuPage, Graph &gh);
    void execute() override;
};


#endif //PROJECT_RAILWAY_PAIRSMAXFLOW_H