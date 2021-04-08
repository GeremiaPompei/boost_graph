#include <vector>
#include "edge.hpp"

/**
 * Metodo costruttore dell'arco.
 */
Edge::Edge(string from, string to, int weight) 
{
    _from = from;
    _to = to;
    _weight = weight;
}

/**
 * Getter dell'origine dell'arco.
 */
const string Edge::from()
{
    return _from;
}

/**
 * Getter della fine dell'arco.
 */
const string Edge::to()
{
    return _to;
}

/**
 * Getter del peso dell'arco.
 */
const int Edge::weight()
{
    return _weight;
}

/**
 * Metodo utile a generare una rappresentazione a stringa dell'arco.
 */
const string Edge::toString()
{
    return _from + " -> " + _to + " (weight: " + to_string(_weight) + ")";
}

    

    

