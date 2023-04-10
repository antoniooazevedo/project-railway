#ifndef PROJECT_RAILWAY_PAIRSMAXFLOW_H
#define PROJECT_RAILWAY_PAIRSMAXFLOW_H

#include "Graph.h"
#include "MenuItem.h"
#include <iomanip>
#include "utils.h"

using namespace std;


class PairsMaxFlow : public MenuItem{
private:
    vector<pair<pair<Vertex*, Vertex*>, int>> result_vector; /**< Vector containing the pairs of stations and their max flow*/
public:
    /**
     * Constructor
     * @param currMenuPage - The current menu page
     * @param gh - The railway graph
     */
    PairsMaxFlow(int &currMenuPage, Graph &gh);

    /**
     * Calculates the max flow between all possible pairs of stations belonging to the extremes vector;
     * Time Complexity: O(V*E²*P), where V is the number of vertices, E is the number of edges and P is the number of extreme vertices.
     */
    void execute() override;
};


#endif //PROJECT_RAILWAY_PAIRSMAXFLOW_H
