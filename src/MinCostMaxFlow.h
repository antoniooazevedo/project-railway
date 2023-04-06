#ifndef PROJECT_RAILWAY_MINCOSTMAXFLOW_H
#define PROJECT_RAILWAY_MINCOSTMAXFLOW_H

#include "Graph.h"
#include "MenuItem.h"

class MinCostMaxFlow : public MenuItem {
public:
    MinCostMaxFlow(int &currMenuPage, Graph &railway);
    void execute() override;

private:
    Vertex* fetchStation() const;
};


#endif
