#include "Scraper.h"

using namespace std;


vector<unordered_map<string, vector<Vertex *>>> Scraper::scrape_stations(string filename, Graph &graph) {
    unordered_map<string, vector<Vertex *>> line_map;
    unordered_map<string, vector<Vertex *>> municipality_map;
    unordered_map<string, vector<Vertex *>> district_map;
    vector<unordered_map<string, vector<Vertex *>>> region_maps;

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
        municipality_map[municipality] = vec;
        district_map[district] = vec;
        auto v = new Vertex(name, district, municipality, main_line, townships);
        graph.addVertex(v);
    }

    region_maps.push_back(line_map);
    region_maps.push_back(municipality_map);
    region_maps.push_back(district_map);


    return region_maps;
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
        if(gh.getRegion() == LINE){
            auto line = v.second->getLine();

        for (auto &e: v.second->getAdj()){
            if (e->getDest()->getLine() == line) count++;
        }

        if (count == 1 || count > 2){
            map[line].push_back(v.second);
        }
    }
        else if (gh.getRegion() == MUNICIPALITIES){
            auto municipality = v.second->getMunicipality();

            for (auto &e: v.second->getAdj()){
                if (e->getDest()->getMunicipality() == municipality) count++;
            }

            if (count == 1){
                map[municipality].push_back(v.second);
            }
        }
        else{
            auto district = v.second->getDistrict();

            for (auto &e: v.second->getAdj()){
                if (e->getDest()->getDistrict() == district) count++;
            }

            if (count == 1 || count > 2){
                map[district].push_back(v.second);
            }
        }
    }

    for (auto &pa: map){
        if (pa.second.empty()){
            for (const auto& v: vertexSet){
                if (gh.getRegion() == LINE){
                    if (v.second->getLine() == pa.first) {
                        pa.second.push_back(v.second);
                        break;
                    }
                }
                else if (gh.getRegion() == MUNICIPALITIES){
                    if (v.second->getMunicipality() == pa.first){
                        pa.second.push_back(v.second);
                        break;
                    }
                }
                else{
                    if (v.second->getDistrict() == pa.first){
                        pa.second.push_back(v.second);
                        break;
                    }
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

void Scraper::findExtremes(vector<unordered_map<string, vector<Vertex *>>> &map, Graph &gh){
    if(gh.getRegion() == LINE){
        getPrematureExtremes(map[0], gh);
        for (auto &p : map[0]){
            findExtremesBFS(p.second[0], gh);
            for (auto &v: p.second) gh.insertExtreme(v);
        }
    }else if(gh.getRegion() == MUNICIPALITIES){
        getPrematureExtremes(map[1], gh);
        for (auto &p : map[1]){
            findExtremesBFS(p.second[0], gh);
            for (auto &v: p.second) gh.insertExtremeMunicipality(v);
        }
    }
    else{
        getPrematureExtremes(map[2], gh);
        for (auto &p : map[2]){
            findExtremesBFS(p.second[0], gh);
            for (auto &v: p.second) gh.insertExtremeDistrict(v);
        }
    }
}


void Scraper::findExtremesBFS(Vertex* origin, Graph &gh){

    for(auto &n : gh.getVertexSet()){
        n.second->setInQueue(false);
        n.second->setProcesssing(false);
    }

    queue<Vertex*> q;
    q.push(origin);
    origin->setInQueue(true);
    bool isExtreme;

    while (!q.empty()){
        isExtreme = true;

        auto v = q.front();
        q.pop();


        for(auto &e: v->getAdj()) {
            auto w = e->getDest();
            if(gh.getRegion() == LINE){
                if (w->getLine() != v->getLine()) {
                    continue;
                }
            }
            else if(gh.getRegion() == MUNICIPALITIES){
                if (w->getMunicipality() != v->getMunicipality()) {
                    continue;
                }
            }
            else{
                if (w->getDistrict() != v->getDistrict()) {
                    continue;
                }
            }

            if (!w->getInQueue()) {
                w->setInQueue(true);
                q.push(w);
            }

            if (!w->isProcessing()) {
                isExtreme = false;
            }
        }

        if (isExtreme){
            if (gh.getRegion() == LINE){
                gh.insertExtreme(v);
            }
            else if (gh.getRegion() == MUNICIPALITIES){
                gh.insertExtremeMunicipality(v);
            }
            else{
                gh.insertExtremeDistrict(v);
            }
        }
        v->setProcesssing(true);
    }
}
