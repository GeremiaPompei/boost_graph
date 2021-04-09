# boost_graph

Progetto esempio per testare la librearia [**boost**](https://www.boost.org/) graph.

## Istallazione e build
### Istallazione libboost
```
sudo apt-get install libboost-all-dev
```
### Istallazione cmake
```
sudo apt-get install cmake
```
### Build
Fare il download della directory e aprire il terminale. Posizionarsi all'interno della directory e digitare 
```
mkdir build
cd build
cmake ..
make
```
Se ci sono problemi legati a permessi all'avvio dell'esehuibile digitare 
```
chmod +x boost_graph
```
Per eseguire il programma basta digitare 
```
./boost_graph
```

## Funzionamento
Il programma permette di compiere diverse azioni tramite le quali viene creato un grafo e possono essere stampati i cammini minimi tramite l'algoritmo di **Dijkstra**.
I comandi sono:
```
add <FROM> <TO> <WEIGHT>
```
che permette di aggiungere un **arco** costituito dal **nodo** **di** **origine**, il **nodo** **di** **fine** e un **peso** espresso tramite un numero intero positivo. 
Tramite l'aggiunta degli archi vengono in automatico aggiunti anche i nodi.
```
root <NODE>
```
che permette di settare il nodo scelto come root del grafo.
```
spprint
```
che permette di stampare sulla console la rappresentazione a stringa dei cammini minimi del grafo settato in precedenza tramite le distanze minime per ogni nodo e i loro padri.
```
eprint
```
che permette di stampare sulla console una rappresentazione a stringa di tutti gli archi registrati fino a quel momento.
```
reset
```
che permette di resettare i valori del grafo.
```
help
```
che permette di stampare a console la legenda dei comandi con la relativa spiegazione del funzionamento.
```
exit
```
che permette di uscire dal programma.
