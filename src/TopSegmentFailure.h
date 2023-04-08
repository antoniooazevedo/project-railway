#ifndef PROJECT_RAILWAY_TOPSEGMENTFAILURE_H
#define PROJECT_RAILWAY_TOPSEGMENTFAILURE_H


#include "Graph.h"
#include "MenuItem.h"
#include "utils.h"

class TopSegmentFailure : public MenuItem{
private:
    int currMenuPage; /**< The current menu page */

    //TODO perguntar ao dani sobre complexidade
    /**
     * Calculates the max flow on a single station for all stations of the graph;
     * Time Complexity: O(V²*E²), where V is the number of vertices and E is the number of edges.
     * @return
     */
    void disabledEdgesMaxFlow(bool disabled);
    set<Edge*> fetchDisabledEdges();
    void enableEdges();
    void disableEdges();
    void getAllStations();

    set<Edge*> disabledEdges;
    vector<Vertex*> stations;
public:
    /**
     * Constructor
     * @param currMenuPage - The current menu page
     * @param gh - The railway graph
     */
    TopSegmentFailure(int &currMenuPage, Graph &gh);

    /**
     * Calculates which stations would be most affected by the selected edges being disabled;
     * Time Complexity: O(V³*E²), where V is the number of vertices and E is the number of edges.
     */
    void execute() override;
};


#endif //PROJECT_RAILWAY_TOPSEGMENTFAILURE_H
