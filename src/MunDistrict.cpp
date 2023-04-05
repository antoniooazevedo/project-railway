//
// Created by tomas on 05/04/2023.
//

#include "MunDistrict.h"
#include "Scraper.h"

void MunDistrict::execute() {
    auto extremes = graph.getExtremesMunicipalities();
    for (auto v1: extremes){
        for (auto v2: extremes){
            if (v1->getId() < v2->getId()){
                if(v1->getMunicipality() == v2->getMunicipality()){
                    result_set.insert({v1->getMunicipality(), graph.getMaxFlow(v1, v2)});
                }
            }
        }
    }
    for(auto it : result_set){
        cout << it.first << " " << it.second << endl;
    }
}

MunDistrict::MunDistrict(int &currMenuPage, Graph &gh) : MenuItem(currMenuPage, gh) {
    this->graph = gh;
}