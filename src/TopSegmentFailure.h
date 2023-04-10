#ifndef PROJECT_RAILWAY_TOPSEGMENTFAILURE_H
#define PROJECT_RAILWAY_TOPSEGMENTFAILURE_H


#include "Graph.h"
#include "MenuItem.h"
#include "utils.h"

class TopSegmentFailure : public MenuItem{
private:
    int currMenuPage; /**< The current menu page */

    /**
     * Calculates the max flow on a single station for all stations of the graph;
     * Time Complexity: O(V*E²), where V is the number of vertices and E is the number of edges.
     * @return
     */
    void disabledEdgesMaxFlow();

    /**
     * Fetches all disabled edges of the graph;
     * Time Complexity: O(E), where E is the number of edges.
     * @return a set containing all disabled edges
     */
    set<Edge*> fetchDisabledEdges();

    /**
     * Enables certain disabled edges;
     * Time Complexity: O(D), where D is the number of edges in the disabled edges set.
     */
    void enableEdges();

    /**
     * Disables certain enabled edges;
     * Time Complexity: O(D), where D is the number of edges in the disabled edges set.
     */
    void disableEdges();

    /**
     * Fetches all stations and adds them to the stations vector.
     * Time Complexity: O(V), where V is the number of nodes in the graph.
     */
    void getAllStations();

    set<Edge*> disabledEdges; /**< Set containing the disabled edges */
    vector<Vertex*> stations; /**< Vector containing the stations of the graph */
public:
    /**
     * Constructor
     * @param currMenuPage - The current menu page
     * @param gh - The railway graph
     */
    TopSegmentFailure(int &currMenuPage, Graph &gh);

    /**
     * Calculates which stations would be most affected by the selected edges being disabled;
     * Time Complexity: O(V*E²), where V is the number of vertices and E is the number of edges.
     */
    void execute() override;
};


#endif //PROJECT_RAILWAY_TOPSEGMENTFAILURE_H
