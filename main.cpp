#include <iostream>
#include "graph.hpp"
#include "edge.hpp"

using namespace std;

/**
 * Funzione utile a stampare il menu di help.
 */
void printHelpMenu() 
{
    cout << endl;
    cout << " >> GRAPH HELP << " << endl;
    cout << " > add <FROM> <TO> <WEIGHT>   per aggiungere un nuovo arco." << endl;
    cout << " > root <ROOT>                per inizializzare la radice dei nodi del grafo." << endl;
    cout << " > spprint                    per stampare i cammini minimi del grafo." << endl;
    cout << " > eprint                     per stampare gli archi del grafo." << endl;
    cout << " > rprint                     per stampare la root del grafo." << endl;
    cout << " > reset                      per inizializzare il grafo." << endl;
    cout << " > exit                       per uscire." << endl;
    cout << endl;
}

/**
 * Funzione utile a stampare la stringa del messaggio di help.
 */
void printHelpMessage()
{
    cout << "Premi \"help\" per avere info sui comandi." << endl;
}

/**
 * Funzione utile a separare una stringa in sottostringhe dato un carattere delimitatore.
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

/**
 * Funzione main che fa partire l'esecuzione dell'app.
 */
int main() {
    Graph *g = new Graph();
    char tmp[200] = "";
    printHelpMessage();
    while (true) {
        cout << " > ";
        cin.getline(tmp, sizeof(tmp));
        string in = string(tmp);
        vector<string> v;
        split(in, &v, ' ');
        if(in == "exit")
            break;
        else if(in == "spprint") {
            g->shortestPath();
            cout << g->spString() << endl;
        } else if(in == "eprint")
            cout << g->edgesString() << endl;
        else if(in == "rprint")
            cout << g->getRoot() << endl;
        else if(in == "reset")
            g = new Graph();
        else if(v.size() >= 2 && v[0] == "root")
            g->setRoot(v[1]);
        else if(v.size() >= 4 && v[0] == "add")
            g->addEdge(Edge(v[1], v[2], atoi(v[3].c_str()))); 
        else if(in == "help")
            printHelpMenu();
        else
            printHelpMessage();
    }
    return 0;
}
