#include "graph.hpp"

/**
 * Metodo utile a trovare l'indice di un elemento in un vettore.
 */
template <typename T>
int findIndex(vector<T> v, T el) 
{
    return find(v.begin(), v.end(), el) - v.begin();
}

/**
 * Costruttore del grafo.
 */
Graph::Graph() 
{
    _nodes = vector<string>();
    _edges = vector<Edge>();
}

/**
 * Metodo utile ad aggiungere un arco al grafo.
 */
void Graph::addEdge(Edge e) 
{
    _edges.push_back(e);
    if(find(_nodes.begin(), _nodes.end(), e.from()) == _nodes.end())
        _nodes.push_back(e.from());
    if(find(_nodes.begin(), _nodes.end(), e.to()) == _nodes.end())
        _nodes.push_back(e.to());
}

/**
 * Metodo utile a settare il nodo radice del grafo.
 */
void Graph::setRoot(string root) {
    int r = findIndex(_nodes, root);
    _root = vertex(r, _graph);
}

/**
 * Metodo utile a configurare il grafico per il calcolo dei percorsi minimi.
 */
void Graph::config() 
{
    const int num_nodes = _nodes.size();
    const int num_edges = _edges.size();
    pair<int, int> edge_array[num_edges];
    int weights[num_edges];
    for(int i = 0; i < num_edges; i++) {
        int indexFrom = findIndex(_nodes, _edges[i].from());
        int indexTo = findIndex(_nodes, _edges[i].to());
        edge_array[i] = pair<int, int>(indexFrom, indexTo);
        weights[i] = _edges[i].weight();
     }
    int num_arcs = sizeof(edge_array) / sizeof(pair<int, int>);
    _graph = graph_t(edge_array, edge_array + num_arcs, weights, num_nodes);
    _parents = vector<vertex_descriptor>(num_vertices(_graph));
    _distances = vector<int>(num_vertices(_graph));
}

/**
 * Metodo utile a calcolare i percorsi minimi.
 */
void Graph::shortestPath() 
{
    if(_nodes.size() > 0) {
        config();
        dijkstra_shortest_paths(_graph, _root,
                            predecessor_map(boost::make_iterator_property_map(_parents.begin(), get(boost::vertex_index, _graph))).
                            distance_map(boost::make_iterator_property_map(_distances.begin(), get(boost::vertex_index, _graph))));
    }
}

/**
 * Metodo utile ad avere una rappresentazione a stringa dei percorsi minimi.
 */
const string Graph::spString() 
{
    string res = "distances and parents\n";
    graph_traits<graph_t>::vertex_iterator vi, vend;
    for (boost::tie(vi, vend) = vertices(_graph); vi != vend; ++vi) {
        res += "distance(" + _nodes[*vi] + ") = " + to_string(_distances[*vi]) + ", " + "parent(" + _nodes[*vi] + ") = " + _nodes[_parents[*vi]] + "\n";
    }
    return res;
}

/**
 * Metodo utile ad avere una rappresentazione a stringa degli archi.
 */
const string Graph::edgesString()
{
    string res = "";
    for(Edge e : _edges)
        res += e.toString() + "\n";
    return res;
}
