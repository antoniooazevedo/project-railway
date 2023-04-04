//
// Created by tomas on 17/03/2023.
//

#include <iostream>
#include "Scraper.h"
#include "Graph.h"
#include "ExampleGraphs.h"


int main(){
    Graph gh1 = ExampleGraphs::Graph6();
    unordered_map<string, vector<Vertex *>> line_map1;
    line_map1["Line1"] = vector<Vertex *>();
    Scraper::findExtremes(line_map1, gh1);
    for (auto v: gh1.getExtremes()) {
        cout << "Station: " << v->getId() << "   Line: " << v->getLine() << endl;
    }



    Graph gh;
    auto line_map = Scraper::scrape_stations("../src/data/stations.csv", gh);
    Scraper::scrape_networks("../src/data/network.csv", gh);
    Scraper::fix_graph(gh);
    Scraper::findExtremes(line_map, gh);
    for (auto v: gh.getExtremes()) {
        cout << "Station: " << v->getId() << "   Line: " << v->getLine() << endl;
    }

    return 0;
}


