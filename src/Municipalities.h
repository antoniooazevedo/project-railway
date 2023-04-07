#ifndef PROJECT_RAILWAY_MUNICIPALITIES_H
#define PROJECT_RAILWAY_MUNICIPALITIES_H


#include <map>
#include "Graph.h"
#include "MenuItem.h"
#include "utils.h"

class Municipalities: public MenuItem {
private:
    map<string , int> mun_map; /**< Map of municipalities and their respective ids */
public:

    /**
     * Constructor
     * @param currMenuPage - The current menu page
     * @param gh - The railway graph
     */
    Municipalities(int &currMenuPage, Graph &gh);

    /**
     * Runs the municipalitiesFind() function and draws a simple paginated menu to display all the municipalities and their respective flows;
     */
    void execute() override;

    /**
     * Finds the connected components of the graph based on the municipality of the vertices and calculates the max flow of each component;
     * Time Complexity: O(V(V+E)), where V is the number of vertices in the graph and E is the number of edges in the graph;
     * @return a map of the municipalities and their respective max flows;
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
     * Calculates the maximum flow for each possible extremes pair of a certain municipality and stores it in the vertex's flow attribute;
     * After that, it calls the connectedComponents() function to calculate the maximum flow of each municipality;
     * Time Complexity: O(V*E²*P), where V is the number of vertices in the graph, E is the number of edges in the graph and P is the number of possible vertex pairs;
     */
    void municipalitiesFind();
};


#endif //PROJECT_RAILWAY_MUNICIPALITIES_H
