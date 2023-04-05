//
// Created by tomas on 17/03/2023.
//

#include <iostream>
#include "Scraper.h"
#include "Graph.h"
#include "Program.h"
#include "ExampleGraphs.h"


int main(){
    Graph railway;
    auto region_map = Scraper::scrape_stations("../src/data/stations.csv", railway);
    Scraper::scrape_networks("../src/data/network.csv", railway);
    Scraper::fix_graph(railway);
    Scraper::findExtremes(region_map, railway);
    for (auto v : railway.getVertexSet()) {
        if (v.second->getLine() == "Rede Espanhola") {
            cout << "LMAOOOOO\n";
        }
    }
    Program p;
    p.run();

    return 0;
}


