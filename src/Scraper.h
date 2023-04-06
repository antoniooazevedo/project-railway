//
// Created by work on 17-03-2023.
//

#ifndef PROJECT_RAILWAY_SCRAPER_H
#define PROJECT_RAILWAY_SCRAPER_H

#include <fstream>
#include <sstream>
#include <list>
#include <string>
#include <unordered_set>
#include <map>
#include "Graph.h"


using namespace std;


class Scraper {
public:
    static vector<unordered_map<string, vector<Vertex *>>> scrape_stations(string filename, Graph &gh);
    static void scrape_networks(string filename, Graph &gh);
    static list<string> scrape_townships(string aux);
    static void fix_graph(Graph &gh);
    static void findExtremes(vector<unordered_map<string, vector<Vertex *>>> &map, Graph &gh);

private:
    static void getPrematureExtremes(unordered_map<string, vector<Vertex *>> &map, Graph &gh);
    static void findExtremesBFS(Vertex *origin, Graph &gh);
};


#endif //PROJECT_RAILWAY_SCRAPER_H
