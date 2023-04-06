//
// Created by tomas on 05/04/2023.
//

#ifndef PROJECT_RAILWAY_MUNDISTRICT_H
#define PROJECT_RAILWAY_MUNDISTRICT_H


#include <map>
#include "Graph.h"
#include "MenuItem.h"

class MunDistrict: public MenuItem {
private:
    Graph graph;
    map<string , int> mun_map;
    map<string , int> district_map;
public:
    MunDistrict(int &currMenuPage, Graph &gh);
    void execute() override;

    map<string,vector<int>> connectedComponents();
    void dfs(Vertex *n, int &flow);
};


#endif //PROJECT_RAILWAY_MUNDISTRICT_H
