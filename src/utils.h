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
int getLen(string str);
bool fetchStation(Vertex* *v, Graph *railway, char quit = ' ');
template<typename Name>
void draw(vector<Name> data, int page, int nPages);
template<typename Name>
void paginationController(vector<Name> data);
void drawFlow(int flow);
void drawResults();
void drawFooter();
void drawCost(int cost);


#endif //PROJECT_RAILWAY_UTILS_H
