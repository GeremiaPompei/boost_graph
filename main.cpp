#include <iostream>

#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

using namespace std;
using namespace boost;

/**
 * Metodo utile a separare una stringa in sottostringhe dato un carattere delimitatore.
 */
void split(string str, int v[3]) {
        v[0] = str[0] % 'A';
        v[1] = str[2] % 'A';
        v[2] = atoi(str.substr(4).c_str());
    }
    

    
int main() {
    typedef adjacency_list<listS, vecS, directedS, no_property, property<edge_weight_t, int>> graph_t;
    typedef graph_traits<graph_t>::vertex_descriptor vertex_descriptor;
    typedef pair<int, int> Edge;
    
    char tmp[200] = "";
    vector<int*> v;
    vector<int> nodes;
    while (true) {
        cout << "Immetti una nuova regole o digita print per stampare il risultato." << endl;
        cout << "Una regola è composta da nodo iniziale, nodo finale e costo (es. A A 3)." << endl;
        cout << " > ";
        cin.getline(tmp, sizeof(tmp));
        string in = string(tmp);
        if(in == "print") break;
        int pieces[3];
        split(in, pieces);
        v.push_back(pieces);
        if(find(nodes.begin(), nodes.end(), pieces[0]) != nodes.end())
            nodes.push_back(pieces[0]);
        if(find(nodes.begin(), nodes.end(), pieces[1]) != nodes.end())
            nodes.push_back(pieces[1]);
    }
    
    sort(nodes.begin(), nodes.end(), [](const int a, const int b) {
        return a > b;
    });

    const int num_nodes = nodes.size();
    const int num_edges = v.size();
    Edge edge_array[num_edges];
    int weights[num_edges];
    //{ pair<int, int>(A, C, 1), Edge(B, B, 2), Edge(B, D, 1), Edge(B, E, 2), Edge(C, B, 7), Edge(C, D, 3), Edge(D, E, 1), Edge(E, A, 1), Edge(E, B, 8)};
    for(int i = 0; i < num_edges; i++) {
        edge_array[i] = pair<int, int>(v[i][0], v[i][1]);
        weights[i] = v[i][2];
     }
    int num_arcs = sizeof(edge_array) / sizeof(Edge);
    graph_t g(edge_array, edge_array + num_arcs, weights, num_nodes);
    vector<vertex_descriptor> p(num_vertices(g));
    vector<int> d(num_vertices(g));
    vertex_descriptor s = vertex(v[0][0], g);
    
    dijkstra_shortest_paths(g, s,
                            predecessor_map(boost::make_iterator_property_map(p.begin(), get(boost::vertex_index, g))).
                            distance_map(boost::make_iterator_property_map(d.begin(), get(boost::vertex_index, g))));

    cout << "distances and parents:" << endl;
    graph_traits<graph_t>::vertex_iterator vi, vend;
    for (boost::tie(vi, vend) = vertices(g); vi != vend; ++vi) {
        cout << "distance(" << (char)(*vi+'A') << ") = " << d[*vi] << ", " << "parent(" << (char)(*vi+'A') << ") = " << (char)(p[*vi]+'A') << endl;
    }
    
    char str [20];
    cin.getline(str, sizeof(str));
    return 0;
}
