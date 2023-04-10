#include "MunicipalitiesBrute.h"


void MunicipalitiesBrute::execute() {

    mun_map.clear();
    system("clear");
    municipalitiesFind();
    vector<pair<string, int>> mun_vector(mun_map.begin(), mun_map.end());
    sort(mun_vector.begin(), mun_vector.end(), compareValue);

    int nMunicipalities = 0;
    bool is_valid = false;

    while(!is_valid){
        cout << "\033[34mInsert the number of municipalities that will be displayed [1-" << mun_vector.size() << "]: " << "\033[0m";
        getInput(nMunicipalities);

        if (nMunicipalities <= 0 || nMunicipalities > mun_vector.size()){
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
    for(auto i = 0; i < nMunicipalities; i++){
        pair<string,int> p;
        p.first = mun_vector[i].first;
        p.second = mun_vector[i].second;
        aux.push_back(p);
    }

    paginationController(aux);

    for(auto n : railway->getVertexSet()){
        n.second->setVisited(false);
    }
}


void MunicipalitiesBrute::municipalitiesFind(){
    for(auto n : railway->getVertexSet()){
        n.second->setFlow(0);
    }

    for (auto v1: railway->getVertexSet()) {
        for (auto v2: railway->getVertexSet()) {
            if (v1.second->getMunicipality() == v2.second->getMunicipality() && v1.first != v2.first) {
                if(v1.first < v2.first){
                    int flow = railway->getMunMaxFlow(v1.second, v2.second);
                    if(v2.second->getFlow() < flow){
                        v2.second->setFlow(flow);
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
}

map<string,vector<int>> MunicipalitiesBrute::connectedComponents() {
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
        if (flows.count(v.second->getMunicipality()) == 0){
            flows[v.second->getMunicipality()] = vector<int>();
        }
        if (flow > 0){
            flows[v.second->getMunicipality()].push_back(flow);
        }
    }

    return flows;
}

void MunicipalitiesBrute::dfs(Vertex* n, int &flow) {
    n->setVisited(true);
    for(auto e : n->getAdj()){
        auto w = e->getDest();
        if(n->getMunicipality() != w->getMunicipality()){
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

MunicipalitiesBrute::MunicipalitiesBrute(int &currMenuPage, Graph &railway) :  MenuItem(currMenuPage, railway) {}
