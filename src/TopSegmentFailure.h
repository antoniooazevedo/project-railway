//
// Created by work on 06-04-2023.
//

#ifndef PROJECT_RAILWAY_TOPSEGMENTFAILURE_H
#define PROJECT_RAILWAY_TOPSEGMENTFAILURE_H


#include "Graph.h"
#include "MenuItem.h"

class TopSegmentFailure : public MenuItem{
private:
    int currMenuPage;
    vector<pair<Vertex*, int>> fullGraphMaxFlow();
public:
    TopSegmentFailure(int &currMenuPage, Graph &gh);
    void execute() override;
};


#endif //PROJECT_RAILWAY_TOPSEGMENTFAILURE_H
