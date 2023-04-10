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

using namespace std;

enum region {LINE = 0, MUNICIPALITIES = 1, DISTRICTS = 2};
class Graph {
public:
    /**
     * Default constructor for the Graph class;
     */
    ~Graph();
    /**
     * Auxiliary function to find a vertex with a given ID.
     * @param id - the id of the vertex;
     * @return the vertex with the given id;
    */
    Vertex *findVertex(const string &id) const;
    /**
     *  Adds a vertex with a given string id to a graph (this).
     *  @param id - the id of the vertex;
     *  @return true - if successful
     *          false - if a vertex with that id already exists.
     */
    bool addVertex(const string &id);

    /**
     * Adds a vertex to a graph (this).
     * @param v - the vertex to be added;
     * @return true - if successful
     *         false - if a vertex with that id already exists.
     */
    bool addVertex(Vertex *v);

    /**
     * Removes a vertex with a given string id from a graph (this).
     * @param id - the id of the vertex;
     * @return true - if successful
     *         false - if a vertex with that id does not exist.
     */
    bool removeVertex(const string &id);

    /**
     * Removes a vertex from a graph (this).
     * @param v - the vertex to be removed;
     * @return true - if successful
     *         false - if a vertex with that id does not exist.
     */
    bool removeVertex(Vertex *v);


    /**
     * Adds an edge to a graph (this), given the source and destination vertices
     * and the edge capacity (c), as well as the edges service (s).
     * It also adds a reverse edge from the destination to the source.
     * @param source - the id of the source vertex;
     * @param dest - the id of the destination vertex;
     * @param c - the capacity of the edge;
     * @param s - the service of the edge;
     * @return true - if successful
     *         false - if the source or destination vertex does not exist.
     */
    bool addBidirectionalEdge(const string &source, const string &dest, double c, enum service s);

    /**
     * Calculates all the cheapest paths that augment flow from the origin vertex to the destination vertex.
     * It then calculates the max flow between those two vertices and also displays the minimum cost of the path.
     * Time Complexity: O(V*E*F) where V is the number of vertices, E is the number of edges and F is the max flow.
     * @param origin - the origin vertex;
     * @param dest - the destination vertex;
     */
    void minCostMaxFlow(Vertex *origin, Vertex *dest) const;

    /**
     * Calculates the cost of all paths with flow originating from the origin vertex.
     * Time Complexity: O(V+E), where V is the number of vertices and E is the number of edges.
     * @param origin - the origin vertex;
     * @return the cost of all paths with flow originating from the origin vertex.
     */
    int computeCost(Vertex *origin) const;

    /**
     * Fetches all the edges that have flow originating from the origin vertex.
     * Time Complexity: O(V+E), where V is the number of vertices and E is the number of edges.
     * @param origin - the origin vertex;
     * @return a vector containing all the edges fetched.
     */
    vector<Edge *> fetchUsedEdges(vector<Vertex *> origin);

    /**
     * Gets the vertex set of a graph (this).
     * @return the vertex set.
     */
    unordered_map<string, Vertex *> getVertexSet() const;

    /**
     * Gets the extremes set of the lines of a graph (this).
     * @return the extremes set.
     */
    unordered_set<Vertex*> getExtremes() const;

    /**
     * Gets the extremes set of the municipalities of a graph (this).
     * @return the extremes set.
     */
    unordered_set<Vertex *> getExtremesMunicipalities() const;

    /**
     * Gets the extremes set of the districts of a graph (this).
     * @return the extremes set.
     */
    unordered_set<Vertex *> getExtremesDistricts() const;

    /**
     * Inserts a vertex (v) into the extremes set of a graph (this).
     * @param v - the vertex to be inserted.
     */
    void insertExtreme(Vertex* v);

    /**
     * Inserts a vertex (v) into the extremes set of the municipalities of a graph (this).
     * @param v - the vertex to be inserted.
     */
    void insertExtremeMunicipality(Vertex* v);

    /**
     * Inserts a vertex (v) into the extremes set of the districts of a graph (this).
     * @param v - the vertex to be inserted.
     */
    void insertExtremeDistrict(Vertex* v);

    /**
     * Gets the region index of a certain graph (line, municipality or district).
     * @return the region index.
     */
    int getRegion() const;

    /**
     * Sets the region index of a certain graph (line, municipality or district).
     * @param r - the region index.
     */
    void setRegion(enum region r);

    /**
     * Calculates and returns the max flow between two vertices (v1 and v2) of a graph (this).
     * Time Complexity: O(V*E²), where V is the number of vertices and E is the number of edges.
     * @param v1 - the starting vertex;
     * @param v2 - the sink/target vertex;
     * @return the max flow between v1 and v2.
     */
    int getMaxFlow(Vertex* v1, Vertex* v2);

    /**
     * Calculates and returns the max flow between two vertices (v1 and v2) of a graph (this), that belong to the same municipality.
     * Time Complexity: O(V*E²), where V is the number of vertices and E is the number of edges.
     * @param v1 - the starting vertex;
     * @param v2 - the sink/target vertex;
     * @return the max flow between v1 and v2.
     */
    int getMunMaxFlow(Vertex *v1, Vertex *v2);

    /**
     * Calculates and returns the max flow between two vertices (v1 and v2) of a graph (this), that belong to the same district.
     * Time Complexity: O(V*E²), where V is the number of vertices and E is the number of edges.
     * @param v1 - the starting vertex;
     * @param v2 - the sink/target vertex;
     * @return the max flow between v1 and v2.
     */
    int getDistrictMaxFlow(Vertex *v1, Vertex *v2);

    /**
     * Returns the flow of a vertex (v) of a graph (this).
     * Time Complexity: O(E), where E is the number of edges of a certain vertex.
     * @param v - the vertex;
     * @return the flow of the vertex.
     */
    int getVertexFlow(Vertex *v) const;

    // TODO: Add documentation

    Vertex* addSuperSource(Vertex *dest);

    void removeSuperSource(Vertex *superSource);

    void connectedComponentsDfs(Vertex *src, int i);

    void setConnectedComponents();

protected:
    std::unordered_map<std::string, Vertex *> vertexSet; /**< The vertex set of the graph. */
    unordered_set<Vertex*> extremes; /**< The extremes set of the lines of the graph. */
    unordered_set<Vertex*> extremesMunicipalities; /**< The extremes set of the municipalities of the graph. */
    unordered_set<Vertex*> extremesDistricts; /**< The extremes set of the districts of the graph. */
    vector<unordered_map<string,vector<Vertex*>>> region_map; /**< The vector of all extreme sets of the graph. */

    /**
     * Augments the flow of all edges of a path ending in a given vertex (dest) by a given flow (flow).
     * Time Complexity: O(E), where E is the number of edges.
     * @param dest - the destination vertex;
     * @param flow - the flow to be augmented.
     */
    void augmentFlow(Vertex* dest, int flow) const;

    /**
     * Finds the bottleneck of a flow path ending in a given vertex (dest).
     * Time Complexity: O(E), where E is the number of edges.
     * @param dest - the destination vertex;
     * @return the bottleneck of the flow path.
     */
    int findBottleneck(Vertex* dest) const;

    /**
     * Calculates the max flow between two vertices (v1 and v2) of a graph (this).
     * Time Complexity: O(V*E²), where V is the number of vertices and E is the number of edges.
     * @param origin - the id of the starting vertex;
     * @param dest - the id of the sink/target vertex;
     */
    void maxFlow(const string &origin, const string &dest) const;

    /**
     * Finds the cheapest path between two vertices (origin and dest) of a graph (this).
     * Time Complexity: O(V*E), where V is the number of vertices and E is the number of edges.
     * @param origin - the origin vertex;
     * @param dest - the destination vertex;
     * @return true if a path was found, and false otherwise.
     */
    bool findCheapestPath(Vertex *origin, Vertex *dest) const;

    /**
     * BFS used to find a path between two vertices (origin and dest) of a graph (this).
     * Time Complexity: O(V+E), where V is the number of vertices and E is the number of edges.
     * @param origin - the origin vertex;
     * @param dest - the destination vertex;
     * @return true if a path was found, and false otherwise.
     */
    bool findPath(Vertex* origin , Vertex* dest ) const;

    /**
     * Finds the max flow between two vertices (origin and dest) of a graph (this), that belong to the same municipality.
     * Time Complexity: O(V*E²), where V is the number of vertices and E is the number of edges.
     * @param origin - the id of starting vertex;
     * @param dest - the id of the sink/target vertex;
     */

    void munMaxFlow(const string &origin, const string &dest) const;

    /**
     * Finds the path between two vertices (origin and dest) of a graph (this), that belong to the same municipality.
     * Time Complexity: O(V+E), where V is the number of vertices and E is the number of edges.
     * @param origin - the origin vertex;
     * @param dest - the destination vertex;
     * @return true if a path was found, and false otherwise.
     */
    bool findMunPath(Vertex* origin , Vertex* dest ) const;

    /**
     * Finds the max flow between two vertices (origin and dest) of a graph (this), that belong to the same district.
     * Time Complexity: O(V+E), where V is the number of vertices and E is the number of edges.
     * @param origin - the origin vertex;
     * @param dest - the destination vertex;
     * @return true if a path was found, and false otherwise.
     */
    bool findDistrictPath(Vertex *origin, Vertex *dest) const;

    /**
     * Finds the max flow between two vertices (origin and dest) of a graph (this), that belong to the same district.
     * Time Complexity: O(V*E²), where V is the number of vertices and E is the number of edges.
     * @param origin - the id of the origin vertex;
     * @param dest - the id of the destination vertex;
     */
    void districtMaxFlow(const string &origin, const string &dest) const;

    /**
     * Resets the visited, path, price and inqueue attributes of all vertices of a graph (this), as well as the visited attribute of all edges.
     * Time Complexity: O(V+E), where V is the number of vertices and E is the number of edges.
     */
    void resetNodes() const;

    /**
     * Resets the flow of all edges of a graph (this).
     * Time Complexity: O(E), where E is the number of edges.
     */
    void resetFlow() const;

    enum region region; /**< The region of the graph. */
};

#endif /** DA_TP_CLASSES_GRAPH */