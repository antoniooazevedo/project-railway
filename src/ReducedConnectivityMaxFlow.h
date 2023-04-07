#ifndef PROJECT_RAILWAY_REDUCEDCONNECTIVITYMAXFLOW_H
#define PROJECT_RAILWAY_REDUCEDCONNECTIVITYMAXFLOW_H

#include <ctime>
#include "Graph.h"
#include "MenuItem.h"

class ReducedConnectivityMaxFlow : public MenuItem{
private:
    int currMenuPage;

public:
    ReducedConnectivityMaxFlow(int &currMenuPage, Graph &gh);
    void execute() override;

};


#endif //PROJECT_RAILWAY_REDUCEDCONNECTIVITYMAXFLOW_H
