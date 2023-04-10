#ifndef PROJECT_RAILWAY_SINGLEPOINTMAXFLOW_H
#define PROJECT_RAILWAY_SINGLEPOINTMAXFLOW_H


#include "menuItems/general/MenuItem.h"
#include "utils.h"

class SinglePointMaxFlow : public MenuItem{
private:
    int currMenuPage; /**< The current menu page */
public:
    /**
     * Constructor
     * @param currMenuPage - The current menu page
     * @param gh - The railway graph
     */
    SinglePointMaxFlow(int &currMenuPage, Graph &gh);

    /**
     * Calculates the max flow possible on a single station when some of the edges were set as disabled;
     * Time Complexity: O(V*E²), where V is the number of vertices and E is the number of edges.
     */
    void execute() override;
};


#endif //PROJECT_RAILWAY_SINGLEPOINTMAXFLOW_H
