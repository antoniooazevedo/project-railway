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
    void disabledEdgesMaxFlow(bool disabled);
    set<Edge*> fetchDisabledEdges();
    void enableEdges();
    void disableEdges();
    void getAllStations();

    set<Edge*> disabledEdges;
    vector<Vertex*> stations;
public:
    TopSegmentFailure(int &currMenuPage, Graph &gh);
    void execute() override;
};


#endif //PROJECT_RAILWAY_TOPSEGMENTFAILURE_H
