#ifndef PROJECT_RAILWAY_UTILS_H
#define PROJECT_RAILWAY_UTILS_H

#include <limits>
#include <iostream>
#include "VertexEdge.h"
#include "Graph.h"
#include <cmath>

using namespace std;

template<typename type>
bool getInput(type &input);
Edge* pickAnEdge(const vector<Edge*>& data);
void drawEdges(vector<Edge*> data, int page, int nPages);

bool fetchStation(Vertex **v, Graph *railway, char quit = ' ');

#endif //PROJECT_RAILWAY_UTILS_H
