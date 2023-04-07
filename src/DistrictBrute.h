#ifndef PROJECT_RAILWAY_DISTRICTBRUTE_H
#define PROJECT_RAILWAY_DISTRICTBRUTE_H
#include <map>
#include "Graph.h"
#include "MenuItem.h"
#include "utils.h"

class DistrictBrute: public MenuItem {
    map<string , int> district_map;
public:
    DistrictBrute(int &currMenuPage, Graph &gh);
    void execute() override;

    map<string,vector<int>> connectedComponents();
    void dfs(Vertex *n, int &flow);

    void districtFind();
};


#endif //PROJECT_RAILWAY_DISTRICTBRUTE_H
