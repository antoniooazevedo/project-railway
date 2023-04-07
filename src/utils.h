#ifndef PROJECT_RAILWAY_UTILS_H
#define PROJECT_RAILWAY_UTILS_H

#include <limits>
#include "iostream"
#include "VertexEdge.h"
#include "Graph.h"

using namespace std;

template<typename type>
bool getInput(type &);
bool compareValue(const pair<string,int>& a, const pair<string,int>& b);
bool sortResultVector(const pair<pair<Vertex*, Vertex*>, int> &p1, const pair<pair<Vertex*, Vertex*>, int> &p2);
void sortVector(vector<Edge *> &aux);
int getLen(string str);
bool fetchStation(Vertex* *v, Graph *railway, char quit = ' ');
template<typename Name>
void draw(vector<Name> data, int page, int nPages);
template<typename Name>
void paginationController(vector<Name> data);
void drawFlow(int flow);
void drawResults();
void drawFooter(vector<Edge*> edges, bool yes = false);
void drawFooterCombinations(vector<pair<pair<Vertex *, Vertex *>, int>> result_vector, Graph *railway);
void drawCost(int cost);
template<typename edge>
void paginationControllerEdge(vector<edge> data, bool cost = false);
template<typename edge>
void drawEdgeCost(vector<edge> data, int page, int nPages);
template<typename edge>
void drawEdge(vector<edge> data, int page, int nPages);


#endif //PROJECT_RAILWAY_UTILS_H
