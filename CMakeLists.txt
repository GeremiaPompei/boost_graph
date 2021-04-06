cmake_minimum_required(VERSION 3.0)

project(boost_graph)

add_executable(boost_graph main.cpp)

install(TARGETS boost_graph RUNTIME DESTINATION bin)
