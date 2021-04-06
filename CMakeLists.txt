cmake_minimum_required(VERSION 3.0)

project(boost_graph)

find_package(Boost 1.45.0 COMPONENTS graph) 

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    add_executable(${PROJECT_NAME} main.cpp)
    target_link_libraries(${PROJECT_NAME} Boost::graph)
endif()
