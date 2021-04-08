#include "graph.hpp"

Graph::Graph() {
    nodes = vector<string>();
    edges = vector<Edge>();
}

void Graph::addEdge(Edge e) {
    edges.push_back(e);
    if(find(nodes.begin(), nodes.end(), e.from()) == nodes.end())
        nodes.push_back(e.from());
    if(find(nodes.begin(), nodes.end(), e.to()) == nodes.end())
        nodes.push_back(e.to());
}

void Graph::shortest_path() {
    const int num_nodes = nodes.size();
    const int num_edges = edges.size();
    pair<int, int> edge_array[num_edges];
    int weights[num_edges];
    for(int i = 0; i < num_edges; i++) {
        int indexFrom = find(nodes.begin(), nodes.end(), edges[i].from()) - nodes.begin();
        int indexTo = find(nodes.begin(), nodes.end(), edges[i].to()) - nodes.begin();
        edge_array[i] = pair<int, int>(indexFrom, indexTo);
        weights[i] = edges[i].weight();
     }
    int num_arcs = sizeof(edge_array) / sizeof(pair<int, int>);
    g = graph_t(edge_array, edge_array + num_arcs, weights, num_nodes);
    p = vector<vertex_descriptor>(num_vertices(g));
    d = vector<int>(num_vertices(g));
    vertex_descriptor s = vertex(0, g);
    
    dijkstra_shortest_paths(g, s,
                            predecessor_map(boost::make_iterator_property_map(p.begin(), get(boost::vertex_index, g))).
                            distance_map(boost::make_iterator_property_map(d.begin(), get(boost::vertex_index, g))));
}

const string Graph::toString() {
    string res = "distances and parents\n";
    graph_traits<graph_t>::vertex_iterator vi, vend;
    for (boost::tie(vi, vend) = vertices(g); vi != vend; ++vi) {
        res += "distance(" + nodes[*vi] + ") = " + to_string(d[*vi]) + ", " + "parent(" + nodes[*vi] + ") = " + nodes[p[*vi]] + "\n";
    }
    return res;
}
