#include <vector>
#include "edge.hpp"

/**
 * Metodo utile a separare una stringa in sottostringhe dato un carattere delimitatore.
 */
void split(string str, vector<string> *v, char delimiter)
{
    string token = "";
    for(auto c : str) {
        if(c == delimiter) {
            token += "\0";
            v->push_back(token);
            token = "";
        } else {
            token += c;
        }
    }
    token += "\0";
    v->push_back(token);
}

Edge::Edge(string from, string to, int weight) 
{
    _from = from;
    _to = to;
    _weight = weight;
}

Edge::Edge(std::string total)
{
    vector<string> v;
    split(total, &v, ' ');
    _from = v[0];
    _to = v[1];
    _weight = atoi(v[2].c_str());
}

const string Edge::from()
{
    return _from;
}

const string Edge::to()
{
    return _to;
}

const int Edge::weight()
{
    return _weight;
}

const string Edge::toString()
{
    return "Edge: [from: " + _from + ", to: " + _to + ", weight: " + to_string(_weight) + "]";
}

    

    

