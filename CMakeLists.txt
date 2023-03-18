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
        src/main.cpp)
