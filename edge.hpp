#ifndef EDGE_H
#define EDGE_H

#include <iostream>

using namespace std;

class Edge {
private:
    string _from;
    string _to;
    int _weight;
    
public:
    Edge(string from, string to, int weight);
    Edge(string total);
    const string from();
    const string to();
    const int weight();
    const string toString();
};

#endif
