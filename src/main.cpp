//
// Created by tomas on 17/03/2023.
//

#include <iostream>
#include "Scraper.h"
#include "Graph.h"
#include "Program.h"
#include "ExampleGraphs.h"


int main(){
    Graph gh = ExampleGraphs::maxFlowSinglePointGraph1();
    /*
    auto line_map = Scraper::scrape_stations("../src/data/stations.csv", gh);
    Scraper::scrape_networks("../src/data/network.csv", gh);
    Scraper::fix_graph(gh);
    Scraper::findExtremes(line_map, gh);

     */
    unordered_map<string, vector<Vertex *>> line_map;
    vector<Vertex *> v;
    line_map["Line1"] = v;
    Scraper::findExtremes(line_map, gh);

    Program p(gh);
    p.run();

    return 0;
}


