#ifndef PROJECT_RAILWAY_MUNICIPALITIESBRUTE_H
#define PROJECT_RAILWAY_MUNICIPALITIESBRUTE_H

#include <map>
#include "Graph.h"
#include "MenuItem.h"
#include "utils.h"

class MunicipalitiesBrute: public MenuItem {
private:
    Graph graph;
    map<string , int> mun_map;
public:
    MunicipalitiesBrute(int &currMenuPage, Graph &gh);
    void execute() override;

    map<string,vector<int>> connectedComponents();
    void dfs(Vertex *n, int &flow);

    void municipalitiesFind();
};


#endif //PROJECT_RAILWAY_MUNICIPALITIESBRUTE_H
