#include "graph.h"
#include <iostream>

using namespace std;

Graph::Graph(int n){
	num_of_vertices = n;
	Adj = new list<int>[n];
}

void Graph::addEdge(int u, int v){
	Adj[u].push_front(v);
}

void Graph::printAdjacencyList(){
	list<int>::iterator v;
	for(int u = 0; u < num_of_vertices; u++){
		cout << u << ": ";
		for (v = Adj[u].begin(); v != Adj[u].end(); v++){
			cout << *v << " ";
		}
		cout << endl;
	}
}

void Graph::sort(){
	//This needs to be implemented.
}
