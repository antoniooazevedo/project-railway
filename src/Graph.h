// By: Gonçalo Leão

#ifndef DA_TP_CLASSES_GRAPH
#define DA_TP_CLASSES_GRAPH

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <string>
#include <unordered_set>

#include "VertexEdge.h"
#include "MutablePriorityQueue.h"

using namespace std;

enum region {LINE = 0, MUNICIPALITIES = 1, DISTRICTS = 2};
class Graph {
public:
    ~Graph();
    /*
    * Auxiliary function to find a vertex with a given ID.
    */
    Vertex *findVertex(const string &id) const;
    /*
     *  Adds a vertex with a given content or info (in) to a graph (this).
     *  Returns true if successful, and false if a vertex with that content already exists.
     */
    bool addVertex(const string &id);
    bool addVertex(Vertex *v);
    bool removeVertex(const string &id);
    bool removeVertex(Vertex *v);

    /*
     * Adds an edge to a graph (this), given the contents of the source and
     * destination vertices and the edge weight (w).
     * Returns true if successful, and false if the source or destination vertex does not exist.
     */
    bool addEdge(const string &source, const string &dest, double c, enum service s);
    bool addBidirectionalEdge(const string &source, const string &dest, double c, enum service s);

    int getNumVertex() const;
    std::unordered_map<std::string, Vertex *> getVertexSet() const;
    unordered_set<Vertex*> getExtremes() const;
    unordered_set<Vertex *> getExtremesMunicipalities() const;
    unordered_set<Vertex *> getExtremesDistricts() const;
    void insertExtreme(Vertex* v);
    void insertExtremeMunicipality(Vertex* v);
    void insertExtremeDistrict(Vertex* v);
    int getRegion() const;

    void setRegion(enum region r);
    int getMaxFlow(Vertex* v1, Vertex* v2);

protected:
    std::unordered_map<std::string, Vertex *> vertexSet;    // vertex set
    unordered_set<Vertex*> extremes;
    unordered_set<Vertex*> extremesMunicipalities;
    unordered_set<Vertex*> extremesDistricts;
    vector<unordered_map<string,vector<Vertex*>>> region_map;


    double ** distMatrix = nullptr;   // dist matrix for Floyd-Warshall
    int **pathMatrix = nullptr;   // path matrix for Floyd-Warshall

    /*
     * Finds the index of the vertex with a given content.
     */
    int findVertexIdx(const int &id) const;
    void augmentFlow(Vertex* dest, int flow) const;
    int findBottleneck(Vertex* src) const;
    void maxFlow(const string &origin, const string &dest) const;
    void costMaxFlow(const string &origin, const string &dest) const;
    bool findCheapestPath(Vertex *origin, Vertex *dest) const;
    bool reachDest(const string &origin, const string &dest) const;
    bool findPath(Vertex* origin , Vertex* dest ) const;
    int computeCost(Vertex *origin) const;
    void resetNodes() const;
    void resetFlow() const;

    enum region region;

};




void deleteMatrix(int **m, int n);
void deleteMatrix(double **m, int n);

#endif /* DA_TP_CLASSES_GRAPH */