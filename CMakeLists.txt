cmake_minimum_required(VERSION 3.4)

project(boost_graph)

#find_package(Boost 1.45.0 COMPONENTS graph) 

add_executable(${PROJECT_NAME} main.cpp edge.cpp graph.cpp)

#target_link_libraries(${PROJECT_NAME} libboost_graph.so)
