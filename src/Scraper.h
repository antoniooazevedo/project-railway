#ifndef PROJECT_RAILWAY_SCRAPER_H
#define PROJECT_RAILWAY_SCRAPER_H

#include <fstream>
#include <sstream>
#include <list>
#include <string>
#include <unordered_set>
#include <map>
#include "Graph.h"


using namespace std;


class Scraper {
public:

    /**
     * Scrapes the stations from the file specified in the filename parameter and adds them to the graph;
     * Time Complexity: O(L), where L is the number of lines in the file;
     * @param filename - the name of the file to be scraped
     * @param gh - the graph to which the stations will be added
     * @return a vector of unordered_maps, each map containing the stations of a certain region (line, municipality or district);

     */
    static vector<unordered_map<string, vector<Vertex *>>> scrape_stations(string filename, Graph &gh);

    /**
     * Scrapes the networks from the file specified in the filename parameter and adds them to the graph, connecting the stations;
     * Time Complexity: O(L), where L is the number of lines in the file;
     * @param filename - the name of the file to be scraped
     * @param gh - the graph to which the networks will be added
     */
    static void scrape_networks(string filename, Graph &gh);

    /**
     * Scrapes the townships from the string specified in the aux parameter and returns a list of them;
     * Time Complexity: O(T), where T is the number of townships in the string;
     * @param aux - the string to be scraped
     * @return a list of the townships in the string;
     */
    static list<string> scrape_townships(string aux);

    /**
     * Removes all stations from the graph that have no adjacent edges
     * Time Complexity: O(V), where V is the number of vertices in the graph;
     * @param gh - the graph to be fixed
     */
    static void fix_graph(Graph &gh);

    /**
     * Finds the extremes of the graph according to lines, municipalities and districts, and adds them to the different extreme vectors;
     * Time Complexity: O(P*(V+E)), where V is the number of vertices in the graph, E is the number of edges in the graph and P is the number of extreme vertices;
     * @param map - the vector of unordered_maps containing all the stations of the graph;
     * @param gh - the graph used to find the extremes;
     */
    static void findExtremes(vector<unordered_map<string, vector<Vertex *>>> &map, Graph &gh);

private:
    /**
     * Finds the extremes based on only if a vertex only has one adjacent edge, or if it has more than two adjacent edges;
     * Time Complexity: O(V+E), where V is the number of vertices in the graph and E is the number of edges in the graph; //TODO: check this
     * @param map - the unordered_map containing all the stations of the graph;
     * @param gh - the graph used to find the extremes;
     */
    static void getPrematureExtremes(unordered_map<string, vector<Vertex *>> &map, Graph &gh);

    /**
     * Runs a BFS starting at the node origin and finds all the remaining extremes of the graph, adding them to the extreme vectors;
     * Time Complexity: O(V+E), where V is the number of vertices in the graph and E is the number of edges in the graph;
     * @param origin - the vertex from which the BFS will start;
     * @param gh - the graph used to find the extremes;
     */
    static void findExtremesBFS(Vertex *origin, Graph &gh);
};


#endif //PROJECT_RAILWAY_SCRAPER_H
