//
// Created by tomas on 17/03/2023.
//

#include <iostream>
#include "Scraper.h"
#include "Graph.h"

int main(){
    Graph gh;
    Scraper::scrape_stations("/home/work/Desktop/code_file/2Sem/DA/project-railway/src/data/stations.csv", gh);
    Scraper::scrape_networks("/home/work/Desktop/code_file/2Sem/DA/project-railway/src/data/network.csv", gh);
    cout << gh.getVertexSet().size() << '\n';
    Scraper::fix_graph(gh);
    cout << gh.getVertexSet().size() << '\n';
    return 0;
}
