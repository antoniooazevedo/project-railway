//
// Created by tomas on 17/03/2023.
//

#include <iostream>
#include "Scraper.h"
#include "Graph.h"

int main(){
    Graph gh;
    auto line_map = Scraper::scrape_stations("/home/work/Desktop/code_file/2Sem/DA/project-railway/src/data/stations.csv", gh);
    Scraper::scrape_networks("/home/work/Desktop/code_file/2Sem/DA/project-railway/src/data/network.csv", gh);
    Scraper::fix_graph(gh);
    Scraper::findExtremes(line_map, gh);
    for (auto v: Scraper::extremes) {
        cout << "station: " << v->getId() << "    line: " << v->getLine() << endl;
    }
    return 0;
}
