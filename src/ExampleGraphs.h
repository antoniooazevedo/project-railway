#ifndef PROJECT_RAILWAY_EXAMPLEGRAPHS_H
#define PROJECT_RAILWAY_EXAMPLEGRAPHS_H
#include <iostream>
#include "Scraper.h"
#include "graph/Graph.h"


class ExampleGraphs {
public:
    static Graph Graph1() ;

    static Graph Graph2();

    static Graph Graph3();

    static Graph Graph4();

    static Graph Graph5();

    static Graph Graph6();

    static Graph costGraph1();

    static Graph costGraph2();

    static Graph maxFlowSinglePointGraph1();

    static Graph maxFlowSinglePointGraph2();

    static Graph topSegmentFailureGraph1();

    static Graph topSegmentFailureGraph2();

};

#endif //PROJECT_RAILWAY_EXAMPLEGRAPHS_H
