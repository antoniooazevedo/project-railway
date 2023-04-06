#ifndef PROJECT_RAILWAY_MAXFLOWUSERINPUT_H
#define PROJECT_RAILWAY_MAXFLOWUSERINPUT_H

#include "Graph.h"
#include "MenuItem.h"
using namespace std;


class MaxFlowUserInput : public MenuItem{
private:
    Graph graph;
public:
    MaxFlowUserInput(int &currMenuPage, Graph &gh);
    void execute() override;

};


#endif //PROJECT_RAILWAY_MAXFLOWUSERINPUT_H
