//
// Created by work on 17-03-2023.
//

#ifndef PROJECT_RAILWAY_SCRAPER_H
#define PROJECT_RAILWAY_SCRAPER_H

#include <fstream>
#include <sstream>
#include <list>
#include <string>

#include "Graph.h"

using namespace std;


class Scraper {
public:
    void scrape_stations(string filename, Graph &gh);
    void scrape_networks(string filename, Graph &gh);
    list<string> scrape_townships(string aux);
};


#endif //PROJECT_RAILWAY_SCRAPER_H
