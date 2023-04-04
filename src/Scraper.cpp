//
// Created by work on 17-03-2023.
//


#include "Scraper.h"
#include "Graph.h"

using namespace std;

unordered_map<string, vector<Vertex *>> Scraper::scrape_stations(string filename, Graph &graph) {
    unordered_map<string, vector<Vertex *>> line_map;
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
        vector<Vertex*> vec;
        line_map[main_line] = vec;

        auto v = new Vertex(name, district, municipality, main_line, townships);
        graph.addVertex(v);
    }

    return line_map;
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

void Scraper::getPrematureExtremes(unordered_map<string, vector<Vertex *>> &map, Graph &gh) {
    auto vertexSet = gh.getVertexSet();
    for (auto const &v: vertexSet){
        int count = 0;
        auto line = v.second->getLine();

        for (auto &e: v.second->getAdj()){
            if (e->getDest()->getLine() == line) count++;
        }

        if (count == 1 || count > 2){
            map[line].push_back(v.second);

            /* PERGUNTAR AO ANTONIO
            auto find_res = map.find(line)

            vector<Vertex *> vec = {v.second};

            if (!find_res->second.empty()){
                for (auto &vertex: find_res->second) vec.push_back(vertex);
            }

            map[line] = vec;*/
        }
    }

    for (auto &pa: map){
        if (pa.second.empty()){
            for (auto v: vertexSet){
                if (v.second->getLine() == pa.first){
                    pa.second.push_back(v.second);
                    break;
                }
            }
        }
    }

    auto itr = map.begin();

    while (itr != map.end()) {
        if (itr->second.empty()) {
            itr = map.erase(itr);
        }
        else
            itr++;
    }
}

void Scraper::findExtremes(unordered_map<string, vector<Vertex*>> &map, Graph &gh){
    getPrematureExtremes(map, gh);
    for (auto &p : map){
        findExtremesBFS(p.second[0], gh);
        for (auto &v: p.second) gh.insertExtreme(v);
    }
}


void Scraper::findExtremesBFS(Vertex* origin, Graph &gh){

    for(auto &n : gh.getVertexSet()){
        n.second->setQueue(false);
        n.second->setProcesssing(false);
    }

    queue<Vertex*> q;
    q.push(origin);
    origin->setQueue(true);
    bool isExtreme;

    while (!q.empty()){
        isExtreme = true;

        auto v = q.front();
        q.pop();


        for(auto &e: v->getAdj()) {
            auto w = e->getDest();
            if (w->getLine() != v->getLine()) {
                continue;
            }
            if (!w->inQueue()) {
                w->setQueue(true);
                q.push(w);
            }

            if (!w->isProcessing()) {
                isExtreme = false;
            }
        }

        if (isExtreme)
            gh.insertExtreme(v);
        v->setProcesssing(true);
    }
}
