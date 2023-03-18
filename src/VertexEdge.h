// By: Gonçalo Leão

#ifndef DA_TP_CLASSES_VERTEX_EDGE
#define DA_TP_CLASSES_VERTEX_EDGE

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <limits>
#include <algorithm>

class Edge;

#define INF std::numeric_limits<double>::max()

/************************* Vertex  **************************/

class Vertex {
public:
    Vertex(std::string id);
    Vertex(std::string id, std::string district, std::string municipality, std::string mainLine,
           std::list<std::string> townships);
    bool operator<(Vertex & vertex) const; // // required by MutablePriorityQueue

    std::string getId() const;
    std::vector<Edge *> getAdj() const;
    bool isVisited() const;
    bool isProcessing() const;
    unsigned int getIndegree() const;
    double getDist() const;
    Edge *getPath() const;
    std::vector<Edge *> getIncoming() const;

    void setId(std::string info);
    void setVisited(bool visited);
    void setProcesssing(bool processing);
    void setIndegree(unsigned int indegree);
    void setDist(double dist);
    void setPath(Edge *path);
    Edge * addEdge(Vertex *dest, double w);
    bool removeEdge(std::string destID);
    void removeOutgoingEdges();

protected:
    std::string id;                // identifier
    std::vector<Edge *> adj;  // outgoing edges

    // auxiliary fields
    bool visited = false; // used by DFS, BFS, Prim ...
    bool processing = false; // used by isDAG (in addition to the visited attribute)
    unsigned int indegree; // used by topsort
    double dist = 0;
    Edge *path = nullptr;
    std::string name = id, district, municipality, main_line;
    std::list<std::string> townships;

    std::vector<Edge *> incoming; // incoming edges

    void deleteEdge(Edge *edge);
};

/********************** Edge  ****************************/

enum service{STANDARD,ALFA_PENDULAR};

class Edge {
public:
    Edge(Vertex *orig, Vertex *dest, double c);

    Vertex * getDest() const;
    double getCapacity() const;
    bool isSelected() const;
    Vertex * getOrig() const;
    Edge *getReverse() const;
    double getFlow() const;
    int getService() const;

    void setSelected(bool selected);
    void setReverse(Edge *reverse);
    void setFlow(double flow);
    void setService(enum service s);
protected:
    Vertex * dest; // destination vertex
    double capacity; // edge weight, can also be used for capacity

    // auxiliary fields
    bool selected = false;

    // used for bidirectional edges
    Vertex *orig;
    Edge *reverse = nullptr;

    double flow; // for flow-related problems

    enum service service;
};

#endif /* DA_TP_CLASSES_VERTEX_EDGE */