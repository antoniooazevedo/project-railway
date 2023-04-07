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

    /**
     * Runs the districtFind() function and draws a simple paginated menu to display all the districts and their respective flows;
     */
    void execute() override;

    /**
     * Finds the connected components of the graph based on the district of the vertices and calculates the max flow of each component;
     * Time Complexity: O(V(V+E)), where V is the number of vertices in the graph and E is the number of edges in the graph;
     * @return a map of the districts and their respective max flows;
     */
    map<string,vector<int>> connectedComponents();

    /**
     * Applies a DFS to the graph, starting at the vertex n, and returns the maximum flow of the graph;
     * Time Complexity: O(V+E), where V is the number of vertices in the graph and E is the number of edges in the graph;
     * @param n - the vertex to start the DFS
     * @param flow - the maximum flow of the graph
     */
    void dfs(Vertex *n, int &flow);

    /**
     * Calculates the maximum flow for each possible extremes pair of a certain district and stores it in the vertex's flow attribute;
     * After that, it calls the connectedComponents() function to calculate the maximum flow of each district;
     * Time Complexity: O(V*E²*P), where V is the number of vertices in the graph, E is the number of edges in the graph and P is the number of possible vertex pairs;
     */
    void districtFind();
};


#endif //PROJECT_RAILWAY_DISTRICT_H
