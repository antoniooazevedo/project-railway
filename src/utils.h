#ifndef PROJECT_RAILWAY_UTILS_H
#define PROJECT_RAILWAY_UTILS_H

#include <limits>

#include <iostream>
#include "graph/VertexEdge.h"
#include "graph/Graph.h"
#include <cmath>

using namespace std;

/**
* This is an auxiliary function, it will have a parameter passed by reference which will be the variable in which we are going to store the input
* (the use of the template will make this function useful for every type of variable) then it will ask the user to give an input and after that will check
* if the input is valid for the type of the variable. If it not valid it will clear the input and return false, otherwise ir will return true. As the
* variable is passed by reference it will keep the value of the input.
* Gets user's input and checks if it valid according to the type of the variable "input". The variable "input" will be
* updated since it is passed by reference.
* @tparam type - variable that will hold the user's input
* @return true if the input was valid, false otherwise.
*/
template<typename type>
bool getInput(type &input);

/**
 * Compares the integers of the two pairs a and b
 * @param a - first pair of string and integer
 * @param b - second pair of string and integer
 * @return true if the integer from the first pair is greater than the integer of the second, false otherwise
 */
bool compareValue(const pair<string,int>& a, const pair<string,int>& b);

/**
 * Sorts the pairs by the integer value of the pair. The integer value is intended to be the flow that goes through the two
 * vertexes
 * @param p1 - first pair of 2 vertexes and the flow that goes through them
 * @param p2 - second pair of 2 vertexes and the flow that goes through them
 * @return true if the integer from the first pair is greater than the integer of the second, false otherwise
 */
bool sortResultVector(const pair<pair<Vertex*, Vertex*>, int> &p1, const pair<pair<Vertex*, Vertex*>, int> &p2);

/**
 * Sorts a vector of stations by alphabetical order
 */
void sortVector(vector<Edge *> &aux);

/**
 * Calculates the number of characters of the string. This considers all characters that take more than one byte as size one
 * such as a "Á"
 * @param str - string to be considered
 * @return the number of characters of a string
 */
int getLen(string str);

/**
 * Asks the user for the name of a station. If the user writes the character provided by the variable 'quit' the user will
 * exit or confirm the stations he inserted
 * @param v - variable that will hold the vertex that corresponds to the station the user inserted
 * @param railway - graph with all the stations
 * @param quit - character that the user needs to input to exit the selection of stations UI
 * @return true if the user insert the 'quit' character, false otherwise
 */
bool fetchStation(Vertex* *v, Graph *railway, char quit = ' ');

/**
 * @brief Draws a table to display values, uses a system of pagination that displays 10 values per page
 * @tparam Name type of the value we want to display
 * @param data the values to display
 * @param page current page
 * @param nPages number of pages that exist
 * Time complexity: O(1)
 */
template<typename Name>
void draw(vector<Name> data, int page, int nPages);

/** Controls the pagination of the drawn table. It allows the user to quit the menu, or jump to the next, previous or any other page directly.
 * @brief Controls the pagination of the drawn table.
 * @tparam Name type of the values we want to display
 * @param data the values we want to display
 * complexity O(1)
 */
template<typename Name>
void paginationController(vector<Name> data);

/**
 * Draws the value of the variable flow on the screen
 * @param flow
 */
void drawFlow(int flow);

/**
 * Draws a header with results written on it
 */
void drawResults();

/**
 * Draws the footer of the paginated results to ask the user if he wants detailed information about the output of the
 * max flow algorithm that was executed.
 * @param edges - edges to be printed in the detailed output
 * @param printCost - determines if the cost of it edge should be printed or not
 */
void drawFooter(vector<Edge*> edges, bool printCost = false);

/**
 * Asks the user for the edge he wants to consider for the detailed information
 * @param result_vector - vector with the pair of vertexes to be considered
 * @param railway - graph with all the stations
 */
void drawFooterCombinations(vector<pair<pair<Vertex *, Vertex *>, int>> result_vector, Graph *railway);

/**
 * Draws a header with results written on it
 * @param cost - integer to be printed
 */
void drawCost(int cost);

/**
 * Controls what happens with each input from the user in the paginated results
 * @param data - data to be printed
 * @param cost - determines if the cost of each edge should be printed or not
 */
template<typename edge>
void paginationControllerEdge(vector<edge> data, bool cost = false);

/**
 * Draws the information of an edge with some cost
 * @param data - data to be printed
 * @param page - page the user is in
 * @param nPages - number of pages there are
 */
template<typename edge>
void drawEdgeCost(vector<edge> data, int page, int nPages);

/**
 * Draws the information about an edge
 * @param data - data to be printed
 * @param page - page the user is in
 * @param nPages - number of pages there are
 */
template<typename edge>
void drawEdge(vector<edge> data, int page, int nPages);

/**
 * Picks an edge to be disabled temporarily for the top-k stations that are the most affected with that edge disabled
 * @param data - edges to be printed
 * @return
 */
Edge* pickAnEdge(const vector<Edge*>& data);

/**
 * Draws the interface with all the edges that are options to be disabled for the top-k stations that are the most affected
 * with that edge disabled algorithm
 * @param data - edges to be printed
 * @param page - page we are in
 * @param nPages - number of pages there are
 */
void drawEdges(vector<Edge*> data, int page, int nPages);

/**
 * Prints the top-k nodes that are the most affected by the removal of an edge in the graph. Shows the flow that enters
 * each station with and without the edge disabled
 * @param data - stations to be printed
 */
void topNode(const vector<Vertex*>& data);

/**
 * Draws the information about a station in the op-k nodes that are the most affected by the removal of an edge in the graph
 * algorithm
 * @param data - information of the stations to be printed
 * @param page - page the user is in
 * @param nPages - number of pages there are
 */
void drawNode(vector<Vertex*> data, int page, int nPages);

#endif //PROJECT_RAILWAY_UTILS_H
