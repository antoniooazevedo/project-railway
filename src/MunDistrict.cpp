#include "MunDistrict.h"

bool compareValue(const pair<string,int>& a, const pair<string,int>& b){
    return a.second > b.second;
}

map<string,vector<int>> MunDistrict::connectedComponents() {
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
        if(graph.getRegion() == MUNICIPALITIES){
            if (flows.count(v.second->getMunicipality()) == 0){
                flows[v.second->getMunicipality()] = vector<int>();
            }
            if (flow > 0){
                flows[v.second->getMunicipality()].push_back(flow);
            }
        }
        else if(graph.getRegion() == DISTRICTS){
            if (flows.count(v.second->getDistrict()) == 0){
                flows[v.second->getDistrict()] = vector<int>();
            }
            if (flow > 0){
                flows[v.second->getDistrict()].push_back(flow);
            }
        }
    }

    return flows;
}

void MunDistrict::dfs(Vertex* n, int &flow) {
    n->setVisited(true);
    for(auto e : n->getAdj()){
        auto w = e->getDest();
        if(graph.getRegion() == MUNICIPALITIES){
            if(n->getMunicipality() != w->getMunicipality()){
                continue;
            }
        }
        else if(graph.getRegion() == DISTRICTS){
            if(n->getDistrict() != w->getDistrict()){
                continue;
            }
        }
        if(w->getFlow() > flow){
            flow = w->getFlow();
        }
        if(!w->isVisited()){
            dfs(w, flow);
        }
    }
}



void MunDistrict::execute() {


    mun_map.clear();
    district_map.clear();

    for(auto n : graph.getVertexSet()){
        n.second->setFlow(0);
    }




    // Get all the municipalities
    auto extremesMun = graph.getExtremesMunicipalities();
    graph.setRegion(MUNICIPALITIES);
    for (auto v1: extremesMun) {
        for (auto v2: extremesMun) {
            if (v1->getMunicipality() == v2->getMunicipality() && v1->getId() != v2->getId()) {
                if(v1->getId() < v2->getId()){
                    int flow = graph.getMunMaxFlow(v1, v2);
                    if(v2->getFlow() < flow){
                        v2->setFlow(flow);
                    }
                }
            }
        }
    }
    auto ConnectedMunicipalities = connectedComponents();
    for (auto cc : ConnectedMunicipalities){
        if(mun_map.count(cc.first) == 0){
            mun_map[cc.first] = 0;
        }
        for (int i = 0; i < cc.second.size(); i++){
            mun_map[cc.first] += cc.second[i];
        }
    }
    vector<pair<string, int>> mun_vector(mun_map.begin(), mun_map.end());
    sort(mun_vector.begin(), mun_vector.end(), compareValue);





    //Get all the districts
    for(auto n : graph.getVertexSet()){
        n.second->setFlow(0);
    }
    auto extremesDistrict = graph.getExtremesDistricts();
    graph.setRegion(DISTRICTS);
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
    vector<pair<string, int>> district_vector(district_map.begin(), district_map.end());
    sort(district_vector.begin(), district_vector.end(), compareValue);



    // Get the number of districts and municipalities
    int districts = 0, municipalities = 0;
    bool is_valid = false;

    while(!is_valid){
        cout << "Number of districts: ";
        cin >> districts;
        cout << "Number of municipalities: ";
        cin >> municipalities;
        if (municipalities <= 0 || municipalities > mun_vector.size() || districts <= 0 || districts > district_vector.size()){
            cout << "Invalid input\n" << endl;
        } else {
            is_valid = true;
        }
    }

    for (auto i = 0; i < districts; i++) {
        if (i == 0){
            cout << "\nDistricts: " << endl;
        }
        cout << district_vector[i].first << " " << district_vector[i].second << endl;
    }

    for (auto i = 0; i < municipalities; i++) {
        if (i == 0){
            cout << "\nMunicipalities: " << endl;
        }
        cout << mun_vector[i].first << " " << mun_vector[i].second << endl;
    }
}

MunDistrict::MunDistrict(int &currMenuPage, Graph &gh) : MenuItem(currMenuPage, gh) {
    this->graph = gh;
}