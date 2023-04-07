#ifndef PROJECT_RAILWAY_DISTRICT_H
#define PROJECT_RAILWAY_DISTRICT_H
#include <map>
#include "Graph.h"
#include "MenuItem.h"
#include "utils.h"

class District : public MenuItem{
private:
    map<string , int> district_map; /**< Map of districts and their respective ids */
public:
    /**
     * Constructor
     * @param currMenuPage - The current menu page
     * @param gh - The railway graph
     */
    District(int &currMenuPage, Graph &gh);
    void execute() override;

    /**
     *
     * @return
     */
    map<string,vector<int>> connectedComponents();

    /**
     * Applies a DFS to the graph, starting at the vertex n, and returns the maximum flow of the graph;
     * @param n - the vertex to start the DFS
     * @param flow - the maximum flow of the graph
     * Time Complexity: O(V+E), where V is the number of vertices in the graph and E is the number of edges in the graph;
     */
    void dfs(Vertex *n, int &flow);

    /**
     *
     */
    void districtFind();
};


#endif //PROJECT_RAILWAY_DISTRICT_H
