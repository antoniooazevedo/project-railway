//
// Created by work on 17-03-2023.
//


#include "Scraper.h"
#include "Graph.h"

using namespace std;

void Scraper::scrape_stations(string filename, Graph &graph) {
    ifstream file;
    file.open(filename);

    string line;
    getline(file, line);  // discard first line
    string name, district, municipality, main_line;
    list<string> townships;
    string townshipword;

    while (getline(file, line)){
        istringstream iss(line);
        getline(iss, name,',');
        getline(iss, district,',');
        getline(iss, municipality,',');
        getline(iss, townshipword,'"');

        if (townshipword.empty()){
            getline(iss, townshipword,'"');
            townships = scrape_townships(townshipword);
            getline(iss, main_line, ',');
            getline(iss, main_line, '\r');
        }
        else{
            stringstream smol(townshipword);
            getline(smol, townshipword, ',');
            townships = scrape_townships(townshipword);
            getline(smol, main_line, '\r');
        }

        auto v = new Vertex(name, district, municipality, main_line, townships);
        graph.addVertex(v);
    }
}

list<string> Scraper::scrape_townships(string aux_string){
    list<string> aux_list;
    istringstream iss(aux_string);
    string township;
    int i = 0;

    while (getline(iss,township,',')){
        if(i > 0){
            township.erase(0, 1);
        }
        aux_list.push_back(township);
        i++;
    }
    return  aux_list;
}

void Scraper::scrape_networks(std::string filename, Graph &gh) {
    ifstream file;
    file.open(filename);

    string line;
    getline(file, line); // discard first line

    string s1, s2, capacity, service_string;

    while(getline(file, line)) {
        istringstream iss(line);
        getline(iss, s1, ',');
        getline(iss, s2, ',');
        getline(iss, capacity, ',');
        getline(iss, service_string, '\r');

        enum service service;
        if (service_string == "STANDARD") service = STANDARD;
        else if (service_string == "ALFA PENDULAR") service = ALFA_PENDULAR;

        gh.addBidirectionalEdge(s1, s2, stoi(capacity), service);
    }
}

void Scraper::fix_graph(Graph &gh){
    auto map = gh.getVertexSet();
    for (auto &v: map){
        if (v.second->getAdj().empty()) gh.removeVertex(v.second);
    }
}