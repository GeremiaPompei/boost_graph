#include <iostream>

#include "graph.hpp"
#include "edge.hpp"

using namespace std;

int main() {
    Graph *g = new Graph();
    char tmp[200] = "";
    while (true) {
        cout << "Immetti una nuova regole o digita print per stampare il risultato." << endl;
        cout << "Una regola è composta da nodo iniziale, nodo finale e costo (es. A A 3)." << endl;
        cout << " > ";
        try {
            cin.getline(tmp, sizeof(tmp));
            string in = string(tmp);
            if(in == "exit")
                break;
            else if(in == "print") {
                g->shortest_path();
                cout << g->toString() << endl;
                g = new Graph();
            } else 
                g->addEdge(Edge(in)); 
        }__catch(std::exception e) {
            cout << "Error: " << e.what() << endl;
        }
    }
    return 0;
}

/*
Bergamo Bergamo 2
Zanzibar Como 1
Bergamo Domodossola 1
Bergamo Empoli 2
Como Bergamo 7
Como Domodossola 3
Domodossola Empoli 1
Empoli Zanzibar 1
Empoli Bergamo 8
print

 */
