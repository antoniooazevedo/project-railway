#ifndef PROJECT_RAILWAY_UTILS_H
#define PROJECT_RAILWAY_UTILS_H

#include <limits>
#include "iostream"
#include "VertexEdge.h"
#include "Graph.h"

using namespace std;

template<typename type>
bool getInput(type &);

int getLen(string str);
bool fetchStation(Vertex *v, Graph *railway, char quit = ' ');


#endif //PROJECT_RAILWAY_UTILS_H
