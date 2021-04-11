cmake_minimum_required(VERSION 3.4)

project(boost_graph)

#add_library(Boost SHARED graph)

add_executable(${PROJECT_NAME} main.cpp edge.cpp graph.cpp)

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
