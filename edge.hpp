#ifndef EDGE_H
#define EDGE_H

#include <iostream>

using namespace std;

/**
 * Classe utile a creare oggetti di tipo arco.
 */
class Edge {
private:
    /**
     * Nodo di origine di un arco.
     */
    string _from;
    
    /**
     * Nodo di fine di un arco.
     */
    string _to;
    
    /**
     * Valore del peso dell'arco.
     */
    int _weight;
    
public:
    /**
     * Metodo costruttore dell'arco.
     */
    Edge(string from, string to, int weight);
    
    /**
     * Getter dell'origine dell'arco.
     */
    const string from();
    
    /**
     * Getter della fine dell'arco.
     */
    const string to();
    
    /**
     * Getter del peso dell'arco.
     */
    const int weight();
    
    /**
     * Metodo utile a generare una rappresentazione a stringa dell'arco.
     */
    const string toString();
};

#endif
