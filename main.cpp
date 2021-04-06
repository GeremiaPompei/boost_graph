#include <iostream>

#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

using namespace std;
using namespace boost;

int main() {
  typedef adjacency_list<listS, vecS, directedS, no_property, property<edge_weight_t, int>> graph_t;
  typedef graph_traits<graph_t>::vertex_descriptor vertex_descriptor;
  typedef pair<int, int> Edge;

  const int num_nodes = 5;
  enum nodes { A, B, C, D, E };
  char name[] = "ABCDE";
  Edge edge_array[] = { Edge(A, C), Edge(B, B), Edge(B, D), Edge(B, E),
    Edge(C, B), Edge(C, D), Edge(D, E), Edge(E, A), Edge(E, B)};
  int weights[] = { 1, 2, 1, 2, 7, 3, 1, 1, 8 };
  int num_arcs = sizeof(edge_array) / sizeof(Edge);
  graph_t g(edge_array, edge_array + num_arcs, weights, num_nodes);
  vector<vertex_descriptor> p(num_vertices(g));
  vector<int> d(num_vertices(g));
  vertex_descriptor s = vertex(A, g);

  dijkstra_shortest_paths(g, s,
                          predecessor_map(boost::make_iterator_property_map(p.begin(), get(boost::vertex_index, g))).
                          distance_map(boost::make_iterator_property_map(d.begin(), get(boost::vertex_index, g))));

  cout << "distances and parents:" << endl;
  graph_traits<graph_t>::vertex_iterator vi, vend;
  for (boost::tie(vi, vend) = vertices(g); vi != vend; ++vi) {
    cout << "distance(" << name[*vi] << ") = " << d[*vi] << ", " << "parent(" << name[*vi] << ") = " << name[p[*vi]] << endl;
  }
  
  return 0;
}
