#include "ExampleGraphs.h"

Graph ExampleGraphs::Graph1(){
    Graph gh1;
    for (auto i = 1; i <= 8; i++) {
        int line = 1;
        Vertex *v = new Vertex("V" + to_string(i), "District" + to_string(i), "Municipality" + to_string(i), "Line" + to_string(line), {"Township" + to_string(i)});
        gh1.addVertex(v);
    }

    gh1.addBidirectionalEdge("V1", "V2", 5,STANDARD);
    gh1.addBidirectionalEdge("V1", "V8", 3,STANDARD);
    gh1.addBidirectionalEdge("V2", "V3", 7,STANDARD);
    gh1.addBidirectionalEdge("V3", "V4", 7,STANDARD);
    gh1.addBidirectionalEdge("V4", "V5", 7,STANDARD);
    gh1.addBidirectionalEdge("V5", "V6", 5,STANDARD);
    gh1.addBidirectionalEdge("V6", "V7", 3,STANDARD);
    gh1.addBidirectionalEdge("V7", "V8", 3,STANDARD);
    gh1.addBidirectionalEdge("V2", "V6", 5,STANDARD);


    return gh1;
}

Graph ExampleGraphs::Graph2(){
    Graph gh2;
    for (auto i = 1; i <= 5; i++) {
        int line = 1;
        Vertex *v = new Vertex("V" + to_string(i), "District" + to_string(i), "Municipality" + to_string(i), "Line" + to_string(line), {"Township" + to_string(i)});
        gh2.addVertex(v);
    }

    gh2.addBidirectionalEdge("V1", "V2", 2,STANDARD);
    gh2.addBidirectionalEdge("V2", "V3", 3,STANDARD);
    gh2.addBidirectionalEdge("V3", "V4", 3,STANDARD);
    gh2.addBidirectionalEdge("V4", "V5", 2,STANDARD);
    gh2.addBidirectionalEdge("V5", "V1", 1,STANDARD);

    return gh2;
}

Graph ExampleGraphs::Graph3(){
    Graph gh3;
    for (auto i = 1; i <= 5; i++) {
        int line = 1;
        Vertex *v = new Vertex("V" + to_string(i), "District" + to_string(i), "Municipality" + to_string(i), "Line" + to_string(line), {"Township" + to_string(i)});
        gh3.addVertex(v);
    }

    gh3.addBidirectionalEdge("V1", "V2", 1,STANDARD);
    gh3.addBidirectionalEdge("V2", "V3", 3,STANDARD);
    gh3.addBidirectionalEdge("V4", "V5", 1,STANDARD);
    gh3.addBidirectionalEdge("V5", "V3", 2,STANDARD);
    gh3.addBidirectionalEdge("V5", "V2", 3,STANDARD);
    gh3.addBidirectionalEdge("V3", "V4", 2,STANDARD);
    gh3.addBidirectionalEdge("V1", "V4", 1,STANDARD);
    gh3.addBidirectionalEdge("V4", "V2", 4,STANDARD);
    gh3.addBidirectionalEdge("V1", "V3", 3,STANDARD);

    return gh3;
}

Graph ExampleGraphs::Graph4(){
    Graph gh4;
    for (auto i = 1; i <= 12; i++) {
        int line = 1;
        if (i >= 7){
            line = 2;
        }
        Vertex *v = new Vertex("V" + to_string(i), "District" + to_string(i), "Municipality" + to_string(i), "Line" + to_string(line), {"Township" + to_string(i)});
        gh4.addVertex(v);
    }

    gh4.addBidirectionalEdge("V1", "V2", 5,STANDARD);
    gh4.addBidirectionalEdge("V1", "V8", 10,STANDARD);
    gh4.addBidirectionalEdge("V2", "V3", 7,STANDARD);
    gh4.addBidirectionalEdge("V3", "V4", 7,STANDARD);
    gh4.addBidirectionalEdge("V4", "V5", 7,STANDARD);
    gh4.addBidirectionalEdge("V5", "V6", 5,STANDARD);
    gh4.addBidirectionalEdge("V6", "V7", 6,STANDARD);
    gh4.addBidirectionalEdge("V7", "V8", 5,STANDARD);
    gh4.addBidirectionalEdge("V2", "V6", 5,STANDARD);
    gh4.addBidirectionalEdge("V8", "V10", 4,STANDARD);
    gh4.addBidirectionalEdge("V10", "V11", 5,STANDARD);
    gh4.addBidirectionalEdge("V12", "V11", 7,STANDARD);
    gh4.addBidirectionalEdge("V11", "V9", 4,STANDARD);
    gh4.addBidirectionalEdge("V9", "V7", 5,STANDARD);

    return gh4;
}

Graph ExampleGraphs::Graph5(){
    Graph gh5;
    for (auto i = 1; i <= 7; i++) {
        int line = 1;
        Vertex *v = new Vertex("V" + to_string(i), "District" + to_string(i), "Municipality" + to_string(i), "Line" + to_string(line), {"Township" + to_string(i)});
        gh5.addVertex(v);
    }

    gh5.addBidirectionalEdge("V1", "V2", 1,STANDARD);
    gh5.addBidirectionalEdge("V2", "V3", 1,STANDARD);
    gh5.addBidirectionalEdge("V3", "V4", 1,STANDARD);
    gh5.addBidirectionalEdge("V4", "V5", 1,STANDARD);
    gh5.addBidirectionalEdge("V3", "V6", 1,STANDARD);
    gh5.addBidirectionalEdge("V6", "V7", 1,STANDARD);


    return gh5;
}

Graph ExampleGraphs::Graph6(){
    Graph gh6;
    for (auto i = 1; i <= 5; i++) {
        int line = 1;
        Vertex *v = new Vertex("V" + to_string(i), "District" + to_string(i), "Municipality" + to_string(i), "Line" + to_string(line), {"Township" + to_string(i)});
        gh6.addVertex(v);
    }

    gh6.addBidirectionalEdge("V1", "V2", 1,STANDARD);
    gh6.addBidirectionalEdge("V2", "V3", 1,STANDARD);
    gh6.addBidirectionalEdge("V3", "V4", 1,STANDARD);
    gh6.addBidirectionalEdge("V4", "V5", 1,STANDARD);


    return gh6;
}

Graph ExampleGraphs::costGraph1() {
    Graph gh;

    for (auto i = 1; i <= 5; i++) {
        int line = 1;
        Vertex *v = new Vertex("V" + to_string(i), "District" + to_string(i), "Municipality" + to_string(i), "Line" + to_string(line), {"Township" + to_string(i)});
        gh.addVertex(v);
    }

    gh.addBidirectionalEdge("V1", "V2", 2, STANDARD);
    gh.addBidirectionalEdge("V1", "V3", 2, ALFA_PENDULAR);
    gh.addBidirectionalEdge("V2", "V3", 4, ALFA_PENDULAR);
    gh.addBidirectionalEdge("V2", "V4", 4, ALFA_PENDULAR);
    gh.addBidirectionalEdge("V4", "V5", 4, ALFA_PENDULAR);
    gh.addBidirectionalEdge("V3", "V5", 2, STANDARD);

    return gh;
}

Graph ExampleGraphs::costGraph2() {
    Graph gh;

    for (auto i = 1; i <= 6; i++) {
        int line = 1;
        Vertex *v = new Vertex("V" + to_string(i), "District" + to_string(i), "Municipality" + to_string(i), "Line" + to_string(line), {"Township" + to_string(i)});
        gh.addVertex(v);
    }

    gh.addBidirectionalEdge("V1", "V2", 2, ALFA_PENDULAR);
    gh.addBidirectionalEdge("V2", "V3", 2, ALFA_PENDULAR);
    gh.addBidirectionalEdge("V1", "V4", 2, STANDARD);
    gh.addBidirectionalEdge("V4", "V5", 4, ALFA_PENDULAR);
    gh.addBidirectionalEdge("V5", "V6", 4, ALFA_PENDULAR);
    gh.addBidirectionalEdge("V3", "V6", 2, STANDARD);

    return gh;
}

Graph ExampleGraphs::maxFlowSinglePointGraph1() {
    Graph gh;
    for (auto i = 1; i <= 14; i++) {
        int line = 1;
        auto *v = new Vertex("V" + to_string(i), "District" + to_string(i), "Municipality" + to_string(i), "Line" + to_string(line), {"Township" + to_string(i)});
        gh.addVertex(v);
    }

    gh.addBidirectionalEdge("V1", "V2", 4, STANDARD);
    gh.addBidirectionalEdge("V2", "V3", 8, STANDARD);
    gh.addBidirectionalEdge("V3", "V4", 8, STANDARD);
    gh.addBidirectionalEdge("V4", "V5", 2, STANDARD);
    gh.addBidirectionalEdge("V5", "V6", 10, STANDARD);
    gh.addBidirectionalEdge("V6", "V7", 6, STANDARD);

    gh.addBidirectionalEdge("V7", "V8", 2, STANDARD);
    gh.addBidirectionalEdge("V8", "V9", 6, STANDARD);
    gh.addBidirectionalEdge("V9", "V10", 10, STANDARD);
    gh.addBidirectionalEdge("V10", "V7", 8, STANDARD);

    gh.addBidirectionalEdge("V4", "V11", 16, STANDARD);
    gh.addBidirectionalEdge("V11", "V12", 20, STANDARD);
    gh.addBidirectionalEdge("V12", "V13", 12, STANDARD);
    gh.addBidirectionalEdge("V12", "V14", 18, STANDARD);

    return gh;
}

Graph ExampleGraphs::maxFlowSinglePointGraph2() {
    Graph gh;
    for (auto i = 1; i <= 6; i++) {
        int line = 1;
        auto *v = new Vertex("V" + to_string(i), "District" + to_string(i), "Municipality" + to_string(i), "Line" + to_string(line), {"Township" + to_string(i)});
        gh.addVertex(v);
    }

    gh.addBidirectionalEdge("V1", "V2", 6, STANDARD);
    gh.addBidirectionalEdge("V1", "V3", 4, STANDARD);
    gh.addBidirectionalEdge("V3", "V4", 2, STANDARD);
    gh.addBidirectionalEdge("V1", "V5", 5, STANDARD);
    gh.addBidirectionalEdge("V5", "V6", 8, STANDARD);


    return gh;
}

Graph ExampleGraphs::topSegmentFailureGraph1() {
    Graph gh;
    for (auto i = 1; i <= 7; i++) {
        int line = 1;
        auto *v = new Vertex("V" + to_string(i), "District" + to_string(i), "Municipality" + to_string(i), "Line" + to_string(line), {"Township" + to_string(i)});
        gh.addVertex(v);
    }

    gh.addBidirectionalEdge("V1", "V2", 8, STANDARD);
    gh.addBidirectionalEdge("V2", "V3", 8, STANDARD);
    gh.addBidirectionalEdge("V2", "V4", 2, STANDARD);
    gh.addBidirectionalEdge("V2", "V5", 3, STANDARD);
    gh.addBidirectionalEdge("V2", "V6", 3, STANDARD);
    gh.addBidirectionalEdge("V1", "V7", 8, STANDARD);

    return gh;
}

Graph ExampleGraphs::topSegmentFailureGraph2() {
    Graph gh;
    for (auto i = 1; i <= 4; i++) {
        int line = 1;
        auto *v = new Vertex("V" + to_string(i), "District" + to_string(i), "Municipality" + to_string(i), "Line" + to_string(line), {"Township" + to_string(i)});
        gh.addVertex(v);
    }

    gh.addBidirectionalEdge("V1", "V2", 4, STANDARD);
    gh.addBidirectionalEdge("V2", "V3", 6, STANDARD);
    gh.addBidirectionalEdge("V3", "V4", 6, STANDARD);

    return gh;
}

Graph ExampleGraphs::Graph7() {
    Graph gh;
    for (auto i = 1; i <= 6; i++) {
        int line = 1;
        Vertex *v = new Vertex("V" + to_string(i), "District" + to_string(i), "Municipality" + to_string(i), "Line" + to_string(line), {"Township" + to_string(i)});
        gh.addVertex(v);
    }

    gh.addBidirectionalEdge("V1", "V2", 2,STANDARD);
    gh.addBidirectionalEdge("V1", "V3", 1,STANDARD);
    gh.addBidirectionalEdge("V3", "V5", 1,STANDARD);
    gh.addBidirectionalEdge("V2", "V5", 2,STANDARD);
    gh.addBidirectionalEdge("V1", "V4", 3,STANDARD);
    gh.addBidirectionalEdge("V4", "V5", 2,STANDARD);
    gh.addBidirectionalEdge("V5", "V6", 3,STANDARD);

    return gh;
}

Graph ExampleGraphs::Graph8() {
    Graph gh;
    for (auto i = 1; i <= 5; i++) {
        int line = 1;
        Vertex *v = new Vertex("V" + to_string(i), "District" + to_string(i), "Municipality" + to_string(i), "Line" + to_string(line), {"Township" + to_string(i)});
        gh.addVertex(v);
    }

    gh.addBidirectionalEdge("V1", "V2", 6,STANDARD);
    gh.addBidirectionalEdge("V2", "V3", 2,STANDARD);
    gh.addBidirectionalEdge("V3", "V4", 6,STANDARD);
    gh.addBidirectionalEdge("V4", "V5", 4,STANDARD);

    return gh;
}

Graph ExampleGraphs::Graph9() {
    Graph gh2;
    for (auto i = 1; i <= 13; i++) {
        int line = 1;
        int mun = 0;
        if (i <= 11){
            mun = 1;
        }
        Vertex *v = new Vertex("V" + to_string(i), "District" + to_string(i), "Municipality" + to_string(mun), "Line" + to_string(line), {"Township" + to_string(i)});
        gh2.addVertex(v);
    }

    gh2.addBidirectionalEdge("V1", "V2", 2,STANDARD);
    gh2.addBidirectionalEdge("V2", "V3", 4,STANDARD);
    gh2.addBidirectionalEdge("V4", "V5", 4,STANDARD);
    gh2.addBidirectionalEdge("V5", "V12", 3,STANDARD);
    gh2.addBidirectionalEdge("V12", "V8", 1,STANDARD);
    gh2.addBidirectionalEdge("V8", "V9", 2,STANDARD);
    gh2.addBidirectionalEdge("V9", "V10", 2,STANDARD);
    gh2.addBidirectionalEdge("V10", "V11", 4,STANDARD);
    gh2.addBidirectionalEdge("V7", "V8", 4,STANDARD);
    gh2.addBidirectionalEdge("V6", "V7", 2,STANDARD);
    gh2.addBidirectionalEdge("V12", "V13", 3,STANDARD);

    return gh2;
}

