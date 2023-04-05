//
// Created by tomas on 05/04/2023.
//

#ifndef PROJECT_RAILWAY_MUNDISTRICT_H
#define PROJECT_RAILWAY_MUNDISTRICT_H


#include "Graph.h"
#include "MenuItem.h"

class MunDistrict: public MenuItem {
private:
    Graph graph;
    set<pair<string , int>> result_set;
public:
    MunDistrict(int &currMenuPage, Graph &gh);
    void execute() override;
};


#endif //PROJECT_RAILWAY_MUNDISTRICT_H
