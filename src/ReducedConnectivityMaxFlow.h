#ifndef PROJECT_RAILWAY_REDUCEDCONNECTIVITYMAXFLOW_H
#define PROJECT_RAILWAY_REDUCEDCONNECTIVITYMAXFLOW_H

#include <ctime>
#include "Graph.h"
#include "MenuItem.h"

class ReducedConnectivityMaxFlow : public MenuItem{
private:
    int currMenuPage; /**< The current menu page */

public:
    /**
     * Constructor
     * @param currMenuPage - The current menu page
     * @param gh - The railway graph
     */
    ReducedConnectivityMaxFlow(int &currMenuPage, Graph &gh);

    /**
     * Calculates the max flow between two stations when some of the edges were set as disabled;
     * Time Complexity: O(V*E²), where V is the number of vertices and E is the number of edges.
     */
    void execute() override;

};


#endif //PROJECT_RAILWAY_REDUCEDCONNECTIVITYMAXFLOW_H
