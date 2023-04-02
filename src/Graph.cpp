#include "Graph.h"

int Graph::getNumVertex() const {
    return vertexSet.size();
}

std::unordered_map<string , Vertex *> Graph::getVertexSet() const {
    return vertexSet;
}

Vertex * Graph::findVertex(const string &id) const {
    auto v = vertexSet.find(id);
    if (v == vertexSet.end()) return nullptr;
    else return v->second;
}

bool Graph::reachDest(const string &origin, const string &dest) const {
    auto currVertex = findVertex(origin);

    if (currVertex == nullptr) return false;

    if (origin == dest){
        findVertex(dest)->setReachedDestination(true);
        return true;
    }

    currVertex->setVisited(true);

    for (auto e : currVertex->getAdj()) {
        auto destVertex = e->getDest();

        if (!destVertex->isVisited()) {
            destVertex->setPath(e);
            if (reachDest(destVertex->getId(), dest))
                currVertex->setReachedDestination(true);
        }

        // Visit an already visited node that reached the destination
        else if (destVertex->getReached()) {
            auto edgeToParent = currVertex->getPath();
            if (edgeToParent != nullptr && edgeToParent->getOrig() != destVertex) {
                currVertex->setReachedDestination(true);
            }
        }
    }

    return currVertex->getReached();
}


double Graph::findBottleneck(Vertex* origin, Vertex* dest) const {
    double cap = numeric_limits<double>::max();
    auto v = dest;
    while (v != origin) {
        auto e = v->getPath();
        if (e->getOrig() == v){
            cap = min(cap, e->getCapacity() - e->getFlow());
            v = e->getOrig();
    }
        else{
            cap = min(cap, e->getFlow());
            v = e->getOrig();
        }
    }
    return cap;
}

void Graph::augmentFlow(Vertex* origin, Vertex* dest, double flow) const {
    auto v = dest;
    while (v != origin) {
        auto e = v->getPath();
        if (e->getOrig() == v){
            e->setFlow(e->getFlow() + flow);
            v = e->getOrig();
        }
        else{
            e->setFlow(e->getFlow() - flow);
            v = e->getOrig();
        }
    }
}

bool Graph::findPath(Vertex* origin , Vertex* dest ) const {
    for(auto v : vertexSet){
        v.second->setVisited(false);
        v.second->setHit(false);
    }

    queue<Vertex*> q;
    origin->setVisited(true);
    q.push(origin);
    while(!q.empty() && !dest->isVisited()){
        auto v = q.front();
        q.pop();

        if (v == dest)
            return true;

        for(auto e : v->getAdj()){
            auto w = e->getDest();
            if(!w->isVisited() && e->getCapacity()-e->getFlow() > 0 && w->getReached()){
                w->setVisited(true);
                w->setPath(e);
                q.push(w);
            }
        }
        for( auto e : v->getIncoming()){
            auto w = e->getOrig();
            if(!w->isVisited() && e->getFlow() > 0){
                w->setVisited(true);
                w->setPath(e);
                q.push(w);
            }
        }
    }
    return dest->isVisited();
}

void Graph::maxFlow(const string &origin, const string &dest) const {
    auto s = findVertex(origin);
    auto t = findVertex(dest);

    // Call dfs

    for(const auto& v : vertexSet){
        v.second->setVisited(false);
        v.second->setHit(false);
        v.second->setPath(nullptr);
    }

    for(const auto& v : vertexSet){
        for(auto e : v.second->getAdj())
            e->setFlow(0);
        for (auto e: v.second->getIncoming())
            e->setFlow(0);
    }

    while (findPath(s, t)){
        double flow = minCap(s, t);
        augmentFlow(s, t, flow);
    }
}

bool Graph::addVertex(const string &id) {
    if (findVertex(id) != nullptr)
        return false;
    vertexSet.insert({id, new Vertex(id)});
    return true;
}

bool Graph::addVertex(Vertex *v) {
    if (findVertex(v->getId()) != nullptr)
        return false;
    vertexSet.insert({v->getId(), v});
    return true;
}

bool Graph::removeVertex(const std::string &id) {
    if (findVertex(id) == nullptr) return false;
    vertexSet.erase(id);
    return true;
}

bool Graph::removeVertex(Vertex *v) {
    if (findVertex(v->getId()) == nullptr) return false;
    vertexSet.erase(v->getId());
    return true;
}

bool Graph::addBidirectionalEdge(const string &sourc, const string &dest, double c, enum service s) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    auto e1 = v1->addEdge(v2, c);
    auto e2 = v2->addEdge(v1, c);
    e1->setReverse(e2);
    e2->setReverse(e1);
    e1->setService(s);
    e2->setService(s);
    return true;
}


void deleteMatrix(int **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

void deleteMatrix(double **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

Graph::~Graph() {
    deleteMatrix(distMatrix, vertexSet.size());
    deleteMatrix(pathMatrix, vertexSet.size());
}