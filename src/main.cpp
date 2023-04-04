#include "Scraper.h"
#include "Graph.h"
#include "Program.h"

int main(){
    Graph gh;
    Scraper::scrape_stations("../src/data/stations.csv", gh);
    Scraper::scrape_networks("../src/data/network.csv", gh);
    cout << gh.getVertexSet().size() << '\n';
    Scraper::fix_graph(gh);
    cout << gh.getVertexSet().size() << '\n';
    return 0;
}
