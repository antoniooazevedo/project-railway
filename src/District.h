#ifndef PROJECT_RAILWAY_DISTRICT_H
#define PROJECT_RAILWAY_DISTRICT_H
#include <map>
#include "Graph.h"
#include "MenuItem.h"
#include "utils.h"

class District : public MenuItem{
private:
    Graph graph;
    map<string , int> district_map;
public:
    District(int &currMenuPage, Graph &gh);
    void execute() override;

    map<string,vector<int>> connectedComponents();
    void dfs(Vertex *n, int &flow);

    void districtFind();
};


#endif //PROJECT_RAILWAY_DISTRICT_H
