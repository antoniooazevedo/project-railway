#ifndef PROJECT_RAILWAY_MAXFLOWUSERINPUT_H
#define PROJECT_RAILWAY_MAXFLOWUSERINPUT_H

#include "Graph.h"
#include "MenuItem.h"
#include "utils.h"
using namespace std;


class MaxFlowUserInput : public MenuItem{
private:
    Graph graph;
public:
    MaxFlowUserInput(int &currMenuPage, Graph &gh);

    /*
     * Asks for user input for the name of both the origin and destination stations and calculates the max flow between the two stations;
     * Time Complexity: O(V*E*F), where V is the number of vertices, E is the number of edges and F is the max flow.
     */
    void execute() override;

};


#endif //PROJECT_RAILWAY_MAXFLOWUSERINPUT_H
