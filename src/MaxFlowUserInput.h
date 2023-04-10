#ifndef PROJECT_RAILWAY_MAXFLOWUSERINPUT_H
#define PROJECT_RAILWAY_MAXFLOWUSERINPUT_H

#include "Graph.h"
#include "MenuItem.h"
#include "utils.h"
using namespace std;


class MaxFlowUserInput : public MenuItem{
public:
    /**
     * Constructor
     * @param currMenuPage - The current menu page
     * @param gh - The railway graph
     */
    MaxFlowUserInput(int &currMenuPage, Graph &gh);

    /**
     * Asks for user input for the name of both the origin and destination stations and calculates the max flow between the two stations;
     * Time Complexity: O(V*E²), where V is the number of vertices, E is the number of edges of the graph
     */
    void execute() override;

};


#endif //PROJECT_RAILWAY_MAXFLOWUSERINPUT_H
