// By: Gonçalo Leão

#ifndef DA_TP_CLASSES_GRAPH
#define DA_TP_CLASSES_GRAPH

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <string>

#include "VertexEdge.h"

using namespace std;

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
    bool addEdge(const string &sourc, const string &dest, double c, enum service s);
    bool addBidirectionalEdge(const string &sourc, const string &dest, double c, enum service s);

    int getNumVertex() const;
    std::unordered_map<std::string, Vertex *> getVertexSet() const;
protected:
    std::unordered_map<std::string, Vertex *> vertexSet;    // vertex set

    double ** distMatrix = nullptr;   // dist matrix for Floyd-Warshall
    int **pathMatrix = nullptr;   // path matrix for Floyd-Warshall

    /*
     * Finds the index of the vertex with a given content.
     */
    int findVertexIdx(const int &id) const;
    void augmentFlow(Vertex* dest, int flow) const;
    double findBottleneck(Vertex* src) const;
    void maxFlow(const string &origin, const string &dest) const;
    bool reachDest(const string &origin, const string &dest) const;
    bool findPath(Vertex* origin , Vertex* dest ) const;
    void resetNodes() const;
    void resetFlow() const;
};

void deleteMatrix(int **m, int n);
void deleteMatrix(double **m, int n);

#endif /* DA_TP_CLASSES_GRAPH */