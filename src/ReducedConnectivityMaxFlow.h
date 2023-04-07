//
// Created by work on 05-04-2023.
//

#ifndef PROJECT_RAILWAY_REDUCEDCONNECTIVITYMAXFLOW_H
#define PROJECT_RAILWAY_REDUCEDCONNECTIVITYMAXFLOW_H


#include "Graph.h"
#include "MenuItem.h"

class ReducedConnectivityMaxFlow : public MenuItem{
private:
    int currMenuPage{};

public:
    ReducedConnectivityMaxFlow(int &currMenuPage, Graph &gh);
    void execute() override;

};


#endif //PROJECT_RAILWAY_REDUCEDCONNECTIVITYMAXFLOW_H
