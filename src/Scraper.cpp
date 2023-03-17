//
// Created by work on 17-03-2023.
//


#include "Scraper.h"

using namespace std;


void Scraper::scrape_stations(string filename) {
    int i = 1;
    ifstream file;
    file.open(filename);

    string line;
    getline(file, line);
    string name, district, municipality, main_line;
    list<string> townships;
    string townshipword;

    while (getline(file, line)){
        istringstream iss(line);
        string info;
        getline(iss, name,',');
        getline(iss, district,',');
        getline(iss, municipality,',');
        getline(iss, townshipword,'"');
        getline(iss, townshipword,'"');
        scrape_townships(townshipword);
        i++;

    }
}

list<string> Scraper::scrape_townships(string aux_string){
    list<string> aux_list;
    istringstream iss(aux_string);
    string township;

    while (getline(iss,township,',')){
        aux_list.push_back(township);
    }
    return  aux_list;
}