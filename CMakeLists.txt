cmake_minimum_required(VERSION 3.23)
project(project_railway)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(project_railway
        src/Scraper.cpp
        src/Scraper.h
        src/VertexEdge.cpp
        src/VertexEdge.h
        src/Graph.cpp
        src/Graph.h
        src/main.cpp
        src/Program.cpp
        src/Program.h
        src/Menu.cpp
        src/Menu.h
        src/MenuItem.cpp
        src/MenuItem.h
        src/ChangeMenu.cpp
        src/ChangeMenu.h
        src/PairsMaxFlow.cpp
        src/PairsMaxFlow.h
        src/ChangeMenu.h
        src/ExampleGraphs.cpp
        src/ExampleGraphs.h
        src/MaxFlowUserInput.cpp
        src/MaxFlowUserInput.h
        src/utils.cpp
        src/utils.h
        src/SinglePointMaxFlow.cpp
        src/SinglePointMaxFlow.h
        src/ReducedConnectivityMaxFlow.cpp
        src/ReducedConnectivityMaxFlow.h
        src/TopSegmentFailure.cpp
        src/TopSegmentFailure.h
        src/Municipalities.cpp src/Municipalities.h src/District.cpp src/District.h)

