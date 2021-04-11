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

/**
 * Classe utile a generare e gestire oggetti di tipo grafico.
 */
class Graph {
private:
    /**
     * Oggetto che rappresenta il gtrafico della libreria boost.
     */
    graph_t _graph;
    
    /**
     * Vettore contenente i padri dei vari nodi.
     */
    vector<vertex_descriptor> _parents;
    
    /**
     * Vettore contenente le minime distanze tra i vari nodi.
     */
    vector<int> _distances;
    
    /**
     * Vettore contenente i nodi.
     */
    vector<string> _nodes;
    
    /**
     * Vettore contenente gli archi.
     */
    vector<Edge> _edges;
    
    /**
     * Oggetto che tiene traccia del nodo radice.
     */
    vertex_descriptor _root;
    
    /**
     * Metodo utile a configurare il grafico per il calcolo dei percorsi minimi.
     */
    void config();
public:
    /**
     * Costruttore del grafo.
     */
    Graph();
    
    /**
     * Metodo utile ad aggiungere un arco al grafo.
     */
    void addEdge(Edge e);
    
    /**
     * Metodo utile a settare il nodo radice del grafo.
     */
    void setRoot(string root);
    
    /**
     * Metodo utile a calcolare i percorsi minimi.
     */
    void shortestPath();
    
    /**
     * Metodo utile ad avere una rappresentazione a stringa dei percorsi minimi.
     */
    const string spString();
    
    /**
     * Metodo utile ad avere una rappresentazione a stringa degli archi.
     */
    const string edgesString();
    
    /**
     * Getter della root.
     */
    const string getRoot();
};

#endif
