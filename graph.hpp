#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>

#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include "edge.hpp"

using namespace std;
using namespace boost;

typedef adjacency_list<listS, vecS, directedS, no_property, property<edge_weight_t, int>> graph_t;
typedef graph_traits<graph_t>::vertex_descriptor vertex_descriptor;

class Graph {
private:
    graph_t g;
    vector<vertex_descriptor> p;
    vector<int> d;
    vector<string> nodes;
    vector<Edge> edges;
public:
    Graph();
    void addEdge(Edge e);
    void shortest_path();
    const string toString();
};

#endif
