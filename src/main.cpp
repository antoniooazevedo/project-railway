//
// Created by tomas on 17/03/2023.
//

#include <iostream>
#include "Scraper.h"
#include "Graph.h"

int main(){
    Scraper sc;
    Graph gh;
    sc.scrape_stations("/home/work/Desktop/code_file/2Sem/DA/project-railway/src/data/stations.csv", gh);
    sc.scrape_networks("/home/work/Desktop/code_file/2Sem/DA/project-railway/src/data/network.csv", gh);
    return 0;
}
