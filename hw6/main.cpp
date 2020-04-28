#include "graph.h"
#include <iostream>

void runTest1(){
	Graph G(5);
	G.addEdge(2, 3);
	G.addEdge(2, 4);
	G.addEdge(3, 0);
	G.addEdge(3, 1);
	G.addEdge(4, 1);
	G.addEdge(1, 0);
	G.printAdjacencyList(); //for testing and visibility
	std::cout <<""<< endl;
	G.sort();
}

void runTest2(){
	Graph G(5);
	G.addEdge(0, 3);
	G.addEdge(1, 0);
	G.addEdge(2, 1);
	G.addEdge(2, 3);
	G.addEdge(0, 2);
	G.addEdge(2, 4);
	G.printAdjacencyList(); //for testing
	G.sort();
}

int main(){
	runTest1();
	runTest2();
}