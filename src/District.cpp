#include "District.h"

void District::execute() {

    district_map.clear();

    // Get all the municipalities
    districtFind();
    vector<pair<string, int>> mun_vector(district_map.begin(), district_map.end());
    sort(mun_vector.begin(), mun_vector.end(), compareValue);

    // Get the number of districts and municipalities
    int nDistricts = 0;
    bool is_valid = false;

    while(!is_valid){
        cout << "\033[34mInsert the number of Districts that will be displayed (máx: 18): " << "\033[0m";
        getInput(nDistricts);

        if (nDistricts <= 0 || nDistricts > mun_vector.size()){
            cout << endl;
            cout << "\033[31m - Invalid input - " << "\033[0m";
            cout << endl;
            cout << endl;
            continue;
        } else {
            is_valid = true;
        }
    }

    for (auto i = 0; i < nDistricts; i++) {
        if (i == 0){
            cout << "\nnDistricts: " << endl;
        }
        cout << mun_vector[i].first << " " << mun_vector[i].second << endl;
    }

    for(auto n : graph.getVertexSet()){
        n.second->setVisited(false);
    }
}



void District::districtFind(){
    for(auto n : graph.getVertexSet()){
        n.second->setFlow(0);
    }
    auto extremesDistrict = graph.getExtremesDistricts();
    for (auto v1: extremesDistrict) {
        for (auto v2: extremesDistrict) {
            if (v1->getDistrict() == v2->getDistrict() && v1->getId() != v2->getId()) {
                if(v1->getId() < v2->getId()){
                    int flow = graph.getDistrictMaxFlow(v1, v2);
                    if(v2->getFlow() < flow){
                        v2->setFlow(flow);
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


map<string,vector<int>> District::connectedComponents() {
    map<string,vector<int>> flows;
    flows.clear();
    for(auto v : graph.getVertexSet()){
        v.second->setVisited(false);
    }

    for(auto v : graph.getVertexSet()){
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

void District::dfs(Vertex* n, int &flow) {
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

District::District(int &currMenuPage, Graph &gh) : MenuItem(currMenuPage, gh) {
    this->graph = gh;
}