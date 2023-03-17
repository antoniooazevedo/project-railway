//
// Created by work on 17-03-2023.
//

#include <fstream>
#include <sstream>
#include <list>
#include "Scraper.h"

using namespace std;


void Scraper::scrape_stations(string filename) {
    ifstream file;
    file.open(filename);

    string line;
    getline(file, line);
    string name, district, municipality, main_line;
    list<string> townships;


}