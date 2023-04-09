#include "DistrictBrute.h"

void DistrictBrute::execute() {

    district_map.clear();
    system("clear");
    // Get all the municipalities
    districtFind();
    vector<pair<string, int>> district_vector(district_map.begin(), district_map.end());
    sort(district_vector.begin(), district_vector.end(), compareValue);

    // Get the number of districts and municipalities
    int nDistricts = 0;
    bool is_valid = false;

    while(!is_valid){
        cout << "\033[34mInsert the number of Districts that will be displayed [1-" << district_vector.size() << "]: " << "\033[0m";
        getInput(nDistricts);

        if (nDistricts <= 0 || nDistricts > district_vector.size()){
            cout << endl;
            cout << "\033[31m - Invalid input - " << "\033[0m";
            cout << endl;
            cout << endl;
            continue;
        } else {
            is_valid = true;
        }
    }

    vector<pair<string,int>> aux;
    for(auto i = 0; i < nDistricts; i++){
        pair<string,int> p;
        p.first = district_vector[i].first;
        p.second = district_vector[i].second;
        aux.push_back(p);
    }

    paginationController(aux);

    for(auto n : railway->getVertexSet()){
        n.second->setVisited(false);
    }
}



void DistrictBrute::districtFind(){
    for(auto n : railway->getVertexSet()){
        n.second->setFlow(0);
    }
    for (auto v1: railway->getVertexSet()) {
        for (auto v2: railway->getVertexSet()) {
            if (v1.second->getDistrict() == v2.second->getDistrict() && v1.first != v2.first) {
                if(v1.first < v2.first){
                    int flow = railway->getDistrictMaxFlow(v1.second, v2.second);
                    if(v2.second->getFlow() < flow){
                        v2.second->setFlow(flow);
                    }
                }
            }
        }
    }
    auto ConnectedDistricts = connectedComponents();
    for (auto cc : ConnectedDistricts){
        if(district_map.count(cc.first) == 0){
            district_map[cc.first] = 0;
        }
        for (int i = 0; i < cc.second.size(); i++){
            district_map[cc.first] += cc.second[i];
        }
    }
}


map<string,vector<int>> DistrictBrute::connectedComponents() {
    map<string,vector<int>> flows;
    flows.clear();
    for(auto v : railway->getVertexSet()){
        v.second->setVisited(false);
    }

    for(auto v : railway->getVertexSet()){
        int flow = 0;
        if(!v.second->isVisited()){
            dfs(v.second, flow);
        }

        if (flows.count(v.second->getDistrict()) == 0){
            flows[v.second->getDistrict()] = vector<int>();
        }
        if (flow > 0){
            flows[v.second->getDistrict()].push_back(flow);
        }
    }

    return flows;
}

void DistrictBrute::dfs(Vertex* n, int &flow) {
    n->setVisited(true);
    for(auto e : n->getAdj()){
        auto w = e->getDest();
        if(n->getDistrict() != w->getDistrict()){
            continue;
        }
        if(w->getFlow() > flow){
            flow = w->getFlow();
        }
        if(!w->isVisited()){
            dfs(w, flow);
        }
    }
}

DistrictBrute::DistrictBrute(int &currMenuPage, Graph &railway) :  MenuItem(currMenuPage, railway) {}
