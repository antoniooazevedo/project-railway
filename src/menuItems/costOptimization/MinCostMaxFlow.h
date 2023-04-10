#ifndef PROJECT_RAILWAY_MINCOSTMAXFLOW_H
#define PROJECT_RAILWAY_MINCOSTMAXFLOW_H

#include "graph/Graph.h"
#include "menuItems/general/MenuItem.h"
#include "utils.h"

class MinCostMaxFlow : public MenuItem {
public:
    /**
     * Constructor
     * @param currMenuPage - The current menu page
     * @param railway - The railway graph
     */
    MinCostMaxFlow(int &currMenuPage, Graph &railway);

    /**
     * Asks for user input for the name of both the origin and destination stations and calculates the minimum cost path that provides the max flow between the two stations
     * Time Complexity: O(V*E²), where V is the number of vertices and E is the number of edges.
     */
    void execute() override;

};


#endif
