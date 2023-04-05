// By: Gonçalo Leão

//#include <wsman.h>
#include "Graph.h"

int Graph::getNumVertex() const {
    return vertexSet.size();
}

std::unordered_map<string , Vertex *> Graph::getVertexSet() const {
    return vertexSet;
}

unordered_set<Vertex*> Graph::getExtremes() const{
    return extremes;
}


/*
 * Auxiliary function to find a vertex with a given content.
 */

Vertex * Graph::findVertex(const string &id) const {
    auto lowerId = id;
    transform(lowerId.begin(), lowerId.end(), lowerId.begin(), ::tolower);
    auto v = vertexSet.find(lowerId);
    if (v == vertexSet.end()) return nullptr;
    else return v->second;
}

void Graph::insertExtreme(Vertex *v) {
    extremes.insert(v);
}

bool Graph::reachDest(const string &origin, const string &dest) const {
    auto currVertex = findVertex(origin);

    if (currVertex == nullptr) return false;

    currVertex->setVisited(true);

    if (origin == dest){
        findVertex(dest)->setReachedDestination(true);
        return true;
    }

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


int Graph::findBottleneck(Vertex* src) const {
    int cap = numeric_limits<double>::max();
    int tmp;
    auto v = src;
    auto e = v->getPath();

    while (e != nullptr) {
        tmp = e->getOrig() == v ? e->getFlow() : e->getCapacity() - e->getFlow() - e->getReverse()->getFlow();

        if (tmp < cap)
            cap = tmp;

        v = e->getOrig() == v ? e->getDest() : e->getOrig();

        e = v->getPath();
    }

    return cap;
}

void Graph::augmentFlow(Vertex* dest, int flow) const {
    auto v = dest;
    auto e = v->getPath();

    while (e != nullptr) {
        e->getOrig() == v ? e->setFlow(e->getFlow() - flow) : e->setFlow(e->getFlow() + flow);

        v = e->getOrig() == v ? e->getDest() : e->getOrig();

        e = v->getPath();
    }
}

bool Graph::findPath(Vertex* origin , Vertex* dest ) const {
    resetNodes();

    queue<Vertex*> q;
    origin->setVisited(true);
    q.push(origin);

    while (!q.empty()) {
        auto v = q.front();
        q.pop();

        for (auto e : v->getAdj()) {
            auto w = e->getDest();

            if (!w->isVisited() && e->getCapacity() > e->getFlow() + e->getReverse()->getFlow() && !e->getDisabled()) {
                if (w == dest) {
                    w->setPath(e);
                    return true;
                }

                w->setVisited(true);
                w->setPath(e);
                q.push(w);
            }
        }

        for (auto e : v->getIncoming()) {
            auto w = e->getOrig();
            if (!w->isVisited() && e->getFlow() > 0 && !e->getDisabled()) {
                w->setVisited(true);
                w->setPath(e);
                q.push(w);
            }
        }
    }

    return false;
}

void Graph::maxFlow(const string &origin, const string &dest) const {
    resetNodes();
    resetFlow();

    reachDest(origin, dest);

    auto s = findVertex(origin);
    auto t = findVertex(dest);

    while (findPath(s, t)){
        int flow = findBottleneck(t);
        augmentFlow(t, flow);
    }
}


void Graph::costMaxFlow(const string &origin, const string &dest) const {
    resetNodes();
    resetFlow();

    reachDest(origin, dest);

    auto s = findVertex(origin);
    auto t = findVertex(dest);

    while (findCheapestPath(s, t)){
        int flow = findBottleneck(t);
        augmentFlow(t, flow);
    }
}


bool Graph::findCheapestPath(Vertex *origin, Vertex *dest) const {
    resetNodes();

    MutablePriorityQueue<Vertex> mq;
    Vertex *currNode = origin;

    currNode->setPrice(0);

    for (const auto& pair : vertexSet) {
        pair.second->setInQueue(true);
        mq.insert(pair.second);
    }

    while (!mq.empty()) {
        currNode = mq.extractMin();

        if (currNode != origin && currNode->getPath() == nullptr)
            continue;

        if (currNode == dest)
            return currNode->getPath() != nullptr;

        for (auto e: currNode->getAdj()) {
            Vertex *adjNode = e->getDest();
            Edge *reverse = e->getReverse();

            bool relaxEdge = adjNode->getPrice() > currNode->getPrice() + e->getService();
            bool isNotFull = e->getCapacity() > e->getFlow() + reverse->getFlow();

            if (adjNode->getInQueue() && relaxEdge && isNotFull) {
                adjNode->setPrice(adjNode->getPrice() + e->getService());
                adjNode->setPath(e);
                mq.decreaseKey(adjNode);
            }
        }

        for (auto e: currNode->getIncoming()) {
            Vertex *adjNode = e->getOrig();

            bool relaxEdge = adjNode->getPrice() > currNode->getPrice() - e->getService();

            if (adjNode->getInQueue() && e->getFlow() > 0 && relaxEdge) {
                adjNode->setPrice(adjNode->getPrice() - e->getService());
                adjNode->setPath(e);
                mq.decreaseKey(adjNode);
            }
        }
        currNode->setInQueue(false);
    }

    return false;
}

bool Graph::addVertex(const string &id) {
    if (findVertex(id) != nullptr)
        return false;
    string lowerid = id;
    transform(lowerid.begin(), lowerid.end(), lowerid.begin(), ::tolower);
    vertexSet.insert({lowerid, new Vertex(id)});
    return true;
}

bool Graph::addVertex(Vertex *v) {
    if (findVertex(v->getId()) != nullptr)
        return false;

    auto lowerId = v->getId();
    transform(lowerId.begin(), lowerId.end(), lowerId.begin(), ::tolower);
    vertexSet.insert({lowerId, v});
    return true;
}

bool Graph::removeVertex(const std::string &id) {
    if (findVertex(id) == nullptr) return false;
    auto v = findVertex(id);
    v->removeOutgoingEdges();
    vertexSet.erase(id);
    return true;
}

bool Graph::removeVertex(Vertex *v) {
    if (findVertex(v->getId()) == nullptr) return false;
    v->removeOutgoingEdges();
    vertexSet.erase(v->getId());
    return true;
}
/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
/*
bool Graph::addEdge(const int &sourc, const int &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, w);
    return true;
}

  */
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

void Graph::resetFlow() const {
    for (const auto& v: getVertexSet()) {
        for (auto e: v.second->getAdj()) {
            e->setFlow(0);
        }
        for (auto e: v.second->getIncoming()) {
            e->setFlow(0);
        }
    }
}

void Graph::resetNodes() const {
    for (auto v: getVertexSet()) {
        v.second->setVisited(false);
        v.second->setPath(nullptr);
        v.second->setPrice(INF);
        v.second->setInQueue(false);
    }
}

int Graph::getMaxFlow(Vertex *v1, Vertex *v2) {
    maxFlow(v1->getId(), v2->getId());
    int flow = 0;
    for (auto e: v2->getIncoming()) flow += e->getFlow();
    return flow;
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

int Graph::computeCost(Vertex *origin) const {
    int totalCost = 0;
    queue<Vertex *> q;
    resetNodes();

    origin->setVisited(true);
    q.push(origin);
    Vertex *currNode;

    while (!q.empty()) {
        currNode = q.front();

        for (Edge *e: currNode->getAdj()) {
            Vertex *destNode = e->getDest();

            if (e->getFlow() > 0) {
                if (!destNode->isVisited()) {
                    q.push(destNode);
                    destNode->setVisited(true);
                }
                totalCost += e->getFlow() * e->getService();
            }
        }

        q.pop();
    }

    return totalCost;
}
