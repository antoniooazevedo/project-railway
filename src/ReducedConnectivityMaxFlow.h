//
// Created by work on 05-04-2023.
//

#ifndef PROJECT_RAILWAY_REDUCEDCONNECTIVITYMAXFLOW_H
#define PROJECT_RAILWAY_REDUCEDCONNECTIVITYMAXFLOW_H


#include "Graph.h"
#include "MenuItem.h"

class ReducedConnectivityMaxFlow : public MenuItem{
private:
    int currMenuPage;

public:
    ReducedConnectivityMaxFlow(int &currMenuPage, Graph &gh);

    /*
     * Calculates the max flow between all possible pairs of stations belonging to the extremes vector;
     * Time Complexity: O(V*E²*P²), where V is the number of vertices, E is the number of edges and P is the number of extreme vertices.
     */
    void execute() override;

};


#endif //PROJECT_RAILWAY_REDUCEDCONNECTIVITYMAXFLOW_H
