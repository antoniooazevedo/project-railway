//
// Created by work on 17-03-2023.
//

#ifndef PROJECT_RAILWAY_SCRAPER_H
#define PROJECT_RAILWAY_SCRAPER_H

#include <fstream>
#include <sstream>
#include <list>
#include <string>

using namespace std;


class Scraper {
public:
    void scrape_stations(string filename);
    void scrape_networks(string filename);
    list<string> scrape_townships(string aux);
};


#endif //PROJECT_RAILWAY_SCRAPER_H
