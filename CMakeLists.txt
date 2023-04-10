cmake_minimum_required(VERSION 3.23)
project(project_railway)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(project_railway
        src/Scraper.cpp
        src/Scraper.h
        src/graph/VertexEdge.cpp
        src/graph/VertexEdge.h
        src/graph/Graph.cpp
        src/graph/Graph.h
        src/main.cpp
        src/Program.cpp
        src/Program.h
        src/menuItems/general/Menu.cpp
        src/menuItems/general/Menu.h
        src/menuItems/general/MenuItem.cpp
        src/menuItems/general/MenuItem.h
        src/menuItems/general/ChangeMenu.cpp
        src/menuItems/general/ChangeMenu.h
        src/menuItems/basicServices/PairsMaxFlow.cpp
        src/menuItems/basicServices/PairsMaxFlow.h
        src/menuItems/general/ChangeMenu.h
        src/ExampleGraphs.cpp
        src/ExampleGraphs.h
        src/menuItems/basicServices/MaxFlowUserInput.cpp
        src/menuItems/basicServices/MaxFlowUserInput.h
        src/utils.cpp
        src/utils.h
        src/menuItems/basicServices/SinglePointMaxFlow.cpp
        src/menuItems/basicServices/SinglePointMaxFlow.h
        src/menuItems/reliabilityAndSensivity/ReducedConnectivityMaxFlow.cpp
        src/menuItems/reliabilityAndSensivity/ReducedConnectivityMaxFlow.h
        src/menuItems/reliabilityAndSensivity/TopSegmentFailure.cpp
        src/menuItems/reliabilityAndSensivity/TopSegmentFailure.h
        src/menuItems/costOptimization/MinCostMaxFlow.h
        src/menuItems/costOptimization/MinCostMaxFlow.cpp
        src/menuItems/basicServices/Municipalities.cpp
        src/menuItems/basicServices/Municipalities.h
        src/menuItems/basicServices/District.cpp
        src/menuItems/basicServices/District.h src/menuItems/basicServices/DistrictBrute.cpp src/menuItems/basicServices/DistrictBrute.h src/menuItems/basicServices/MunicipalitiesBrute.cpp src/menuItems/basicServices/MunicipalitiesBrute.h)

