#ifndef PROJECT_RAILWAY_MUNICIPALITIES_H
#define PROJECT_RAILWAY_MUNICIPALITIES_H


#include <map>
#include "Graph.h"
#include "MenuItem.h"
#include "utils.h"

class Municipalities: public MenuItem {
private:
    Graph graph;
    map<string , int> mun_map;
public:
    Municipalities(int &currMenuPage, Graph &gh);
    void execute() override;

    map<string,vector<int>> connectedComponents();
    void dfs(Vertex *n, int &flow);

    void municipalitiesFind();
};


#endif //PROJECT_RAILWAY_MUNICIPALITIES_H
