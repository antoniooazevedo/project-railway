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
     *  Adds a vertex with a given string id to a graph (this).
     *  Returns true if successful, and false if a vertex with that id already exists.
     */
    bool addVertex(const string &id);

    /*
     * Adds a vertex to a graph (this).
     * Returns true if successful, and false if a vertex with that id already exists.
     */
    bool addVertex(Vertex *v);

    /*
     * Removes a vertex with a given string id from a graph (this).
     * Returns true if successful, and false if a vertex with that id does not exist.
     */
    bool removeVertex(const string &id);

    /*
     * Removes a vertex from a graph (this).
     * Returns true if successful, and false if a vertex with that id does not exist.
     */
    bool removeVertex(Vertex *v);

    /*
     * Adds an edge to a graph (this), given the IDs of the source and
     * destination vertices and the edge capacity (c), as well as the edges service (s).
     * Returns true if successful, and false if the source or destination vertex does not exist.
     */
    bool addEdge(const string &source, const string &dest, double c, enum service s);

    /*
     * Adds an edge to a graph (this), given the source and destination vertices
     * and the edge capacity (c), as well as the edges service (s).
     * It also adds a reverse edge from the destination to the source.
     * Returns true if successful, and false if the source or destination vertex does not exist.
     */
    bool addBidirectionalEdge(const string &source, const string &dest, double c, enum service s);

    /*
     * Calculates all the cheapest paths that augment flow from the origin vertex to the destination vertex.
     * It then calculates the max flow between those two vertices and also displays the minimum cost of the path.
     * Time Complexity: O(V*E*F) where V is the number of vertices, E is the number of edges and F is the max flow.
     */
    void minCostMaxFlow(Vertex *origin, Vertex *dest) const;

    /*
     * Calculates the cost of all paths with flow originating from the origin vertex.
     * Time Complexity: O(V+E), where V is the number of vertices and E is the number of edges.
     */
    int computeCost(Vertex *origin) const;

    /*
     * Returns a vector containing all the edges that have flow originating from the origin vertex.
     * Time Complexity: O(V+E), where V is the number of vertices and E is the number of edges.
     */
    vector<Edge *> fetchUsedEdges(vector<Vertex *> origin);


    int getNumVertex() const;

    /*
     * Returns the vertex set of a graph (this).
     */
    unordered_map<string, Vertex *> getVertexSet() const;

    /*
     * Returns an unordered set containing all the extremes of all lines of a graph (this).
     */
    unordered_set<Vertex*> getExtremes() const;

    unordered_set<Vertex *> getExtremesMunicipalities() const;
    unordered_set<Vertex *> getExtremesDistricts() const;

    /*
     * Inserts a vertex (v) into the extremes set of a graph (this).
     */
    void insertExtreme(Vertex* v);
    void insertExtremeMunicipality(Vertex* v);
    void insertExtremeDistrict(Vertex* v);
    int getRegion() const;

    void setRegion(enum region r);

    /*
     * Calculates and returns the max flow between two vertices (v1 and v2) of a graph (this).
     * Time Complexity: O(V*E²), where V is the number of vertices and E is the number of edges.
     */
    int getMaxFlow(Vertex* v1, Vertex* v2);

    /*
     * Calculates and returns the max flow between two vertices (v1 and v2) of a graph (this), that belong to the same municipality.
     * Time Complexity: O(V*E²), where V is the number of vertices and E is the number of edges.
     */
    int getMunMaxFlow(Vertex *v1, Vertex *v2);

    /*
     * Calculates and returns the max flow between two vertices (v1 and v2) of a graph (this), that belong to the same district.
     * Time Complexity: O(V*E²), where V is the number of vertices and E is the number of edges.
     */
    int getDistrictMaxFlow(Vertex *v1, Vertex *v2);

    /*
     * Returns the flow of a vertex (v) of a graph (this).
     * Time Complexity: O(E), where E is the number of edges of a certain vertex.
     */
    int getVertexFlow(Vertex *v) const;

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

    /*
     * Augments the flow of all edges of a path ending in a given vertex (dest) by a given flow (flow).
     * Time Complexity: O(E), where E is the number of edges.
     */
    void augmentFlow(Vertex* dest, int flow) const;

    /*
     * Returns the bottleneck of a flow path ending in a given vertex (src).
     * Time Complexity: O(E), where E is the number of edges.
     */
    int findBottleneck(Vertex* src) const;

    /*
     * Calculates the max flow between two vertices (v1 and v2) of a graph (this).
     * Time Complexity: O(V*E²), where V is the number of vertices and E is the number of edges.
     */
    void maxFlow(const string &origin, const string &dest) const;

    /*
     * Finds the cheapest path between two vertices (origin and dest) of a graph (this).
     * Returns true if a path was found, and false otherwise.
     * Time Complexity: O(V*E), where V is the number of vertices and E is the number of edges.
     */
    bool findCheapestPath(Vertex *origin, Vertex *dest) const;

    /*
     * BFS used to find a path between two vertices (origin and dest) of a graph (this).
     * Returns true if a path was found, and false otherwise.
     * Time Complexity: O(V+E), where V is the number of vertices and E is the number of edges.
     */
    bool findPath(Vertex* origin , Vertex* dest ) const;

    /*
     * Finds the max flow between two vertices (origin and dest) of a graph (this), that belong to the same municipality.
     * Time Complexity: O(V*E²), where V is the number of vertices and E is the number of edges.
     */
    void munMaxFlow(const string &origin, const string &dest) const;

    /*
     * Finds the path between two vertices (origin and dest) of a graph (this), that belong to the same municipality.
     * Returns true if a path was found, and false otherwise.
     * Time Complexity: O(V+E), where V is the number of vertices and E is the number of edges.
     */
    bool findMunPath(Vertex* origin , Vertex* dest ) const;

    /*
     * Finds the max flow between two vertices (origin and dest) of a graph (this), that belong to the same district.
     * Returns true if a path was found, and false otherwise.
     * Time Complexity: O(V+E), where V is the number of vertices and E is the number of edges.
     */
    bool findDistrictPath(Vertex *origin, Vertex *dest) const;

    /*
     * Finds the max flow between two vertices (origin and dest) of a graph (this), that belong to the same district.
     * Time Complexity: O(V*E²), where V is the number of vertices and E is the number of edges.
     */
    void districtMaxFlow(const string &origin, const string &dest) const;

    /*
     * Resets the visited, path, price and inqueue attributes of all vertices of a graph (this), as well as the visited attribute of all edges.
     * Time Complexity: O(V+E), where V is the number of vertices and E is the number of edges.
     */
    void resetNodes() const;

    /*
     * Resets the flow of all edges of a graph (this).
     * Time Complexity: O(E), where E is the number of edges.
     */
    void resetFlow() const;

    enum region region;
};

void deleteMatrix(int **m, int n);
void deleteMatrix(double **m, int n);

#endif /* DA_TP_CLASSES_GRAPH */