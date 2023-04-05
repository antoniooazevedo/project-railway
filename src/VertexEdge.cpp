// By: Gonçalo Leão

#include "VertexEdge.h"

using namespace std;

/************************* Vertex  **************************/

Vertex::Vertex(string id, std::string district, std::string municipality, std::string mainLine,
               std::list<std::string> townships)
        : id(id), district(district), municipality(municipality), main_line(mainLine), townships(townships) {}

Vertex::Vertex(std::string id) : id(id) {}


/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
Edge * Vertex::addEdge(Vertex *d, double w) {
    auto newEdge = new Edge(this, d, w);
    adj.push_back(newEdge);
    d->incoming.push_back(newEdge);
    return newEdge;
}

/*
 * Auxiliary function to remove an outgoing edge (with a given destination (d))
 * from a vertex (this).
 * Returns true if successful, and false if such edge does not exist.
 */
bool Vertex::removeEdge(string destID) {
    bool removedEdge = false;
    auto it = adj.begin();
    while (it != adj.end()) {
        Edge *edge = *it;
        Vertex *dest = edge->getDest();
        if (dest->getId() == destID) {
            it = adj.erase(it);
            deleteEdge(edge);
            removedEdge = true; // allows for multiple edges to connect the same pair of vertices (multigraph)
        }
        else {
            it++;
        }
    }
    return removedEdge;
}

/*
 * Auxiliary function to remove an outgoing edge of a vertex.
 */
void Vertex::removeOutgoingEdges() {
    auto it = adj.begin();
    while (it != adj.end()) {
        Edge *edge = *it;
        it = adj.erase(it);
        deleteEdge(edge);
    }
}

bool Vertex::operator<(Vertex & vertex) const {
    return this->price < vertex.price;
}

string Vertex::getId() const {
    return this->id;
}

string Vertex::getLine() const {
    return this->main_line;
}

string Vertex::getMunicipality() const {
    return this->municipality;
}

string Vertex::getDistrict() const {
    return this->district;
}

std::vector<Edge*> Vertex::getAdj() const {
    return this->adj;
}

bool Vertex::getReached() const {
    return this->reachDestination;
}

bool Vertex::getHit() const {
    return this->hit;
}



bool Vertex::isVisited() const {
    return this->visited;
}

bool Vertex::isProcessing() const {
    return this->processing;
}

unsigned int Vertex::getIndegree() const {
    return this->indegree;
}

double Vertex::getDist() const {
    return this->dist;
}

Edge *Vertex::getPath() const {
    return this->path;
}

std::vector<Edge *> Vertex::getIncoming() const {
    return this->incoming;
}

void Vertex::setId(string id) {
    this->id = id;
}

void Vertex::setVisited(bool visited) {
    this->visited = visited;
}

void Vertex::setReachedDestination(bool reachDestination) {
    this->reachDestination = reachDestination;
}

void Vertex::setHit(bool hit) {
    this->hit = hit;
}

void Vertex::setProcesssing(bool processing) {
    this->processing = processing;
}

void Vertex::setIndegree(unsigned int indegree) {
    this->indegree = indegree;
}

void Vertex::setDist(double dist) {
    this->dist = dist;
}

void Vertex::setPath(Edge *path) {
    this->path = path;
}

void Vertex::deleteEdge(Edge *edge) {
    Vertex *dest = edge->getDest();
    // Remove the corresponding edge from the incoming list
    auto it = dest->incoming.begin();
    while (it != dest->incoming.end()) {
        if ((*it)->getOrig()->getId() == id) {
            it = dest->incoming.erase(it);
        }
        else {
            it++;
        }
    }
    delete edge;
}

int Vertex::getPrice() const {
    return price;
}

void Vertex::setPrice(int price) {
    this->price = price;
}

bool Vertex::getInQueue() const {
    return inQueue;
}

void Vertex::setInQueue(bool inQueue) {
    this->inQueue = inQueue;
}

bool Vertex::operator==(const Vertex &v) {
    return this->getId() == v.getId();
}

/********************** Edge  ****************************/


Edge::Edge(Vertex *orig, Vertex *dest, double w): orig(orig), dest(dest), capacity(w) {}

Vertex * Edge::getDest() const {
    return this->dest;
}

int Edge::getCapacity() const {
    return this->capacity;
}

Vertex * Edge::getOrig() const {
    return this->orig;
}

Edge *Edge::getReverse() const {
    return this->reverse;
}

bool Edge::isSelected() const {
    return this->selected;
}

int Edge::getFlow() const {
    return this->flow;
}

int Edge::getService() const {
    return this->service;
}

void Edge::setSelected(bool selected) {
    this->selected = selected;
}

void Edge::setReverse(Edge *reverse) {
    this->reverse = reverse;
}

void Edge::setFlow(int flow) {
    this->flow = flow;
}

void Edge::setService(enum service s) {
    this->service = s;
}