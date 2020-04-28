#include "graph.h"
#include <list>
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

//This needs to be implemented
void Graph::sort(){

	//first find if the graph is cyclic
	if(isCyclic()){
		cout << "The graph is cyclic and can't be ordered "<<endl;
		return;
	}

	//Make a copy of the adj matrix to keep graph intact while doing operations
	list<int> *tempAdj;
	tempAdj = new list<int>[num_of_vertices];
	for(int i = 0; i < num_of_vertices; i++){
		tempAdj[i].assign(Adj[i].begin(),Adj[i].end()); 
	}

	int order[num_of_vertices]; //array that holds the answer
	list<int>::iterator test;

	//Filling up the array
	for(int i = num_of_vertices-1; i> -1; i--){
		order[i] = findEmpty(tempAdj,order);
	}

	//Printing out the answer
	cout<<"The order is: ";
	for(int i = 0; i < num_of_vertices; i++){
		cout<< order[i]; 
	}
	cout<<endl;
	cout<<endl;
}


//helper method for figuring out if graph is cyclic
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack){
	if(visited[v] == false){
		visited[v] = true;
		recStack[v] = true;

		list<int>::iterator i;
		for(i= Adj[v].begin();i != Adj[v].end(); i++){
			if(!visited[*i] && isCyclicUtil(*i,visited,recStack))
				return true;
			else if(recStack[*i])
				return true;
		}
	}
	recStack[v] = false;
	return false;

}


bool Graph::isCyclic(){
	bool *visited = new bool[num_of_vertices];
	bool *recStack = new bool[num_of_vertices];
	for(int i =0; i<num_of_vertices;i++){
		visited[i] = false;
		recStack[i] = false;
	}

	for(int i = 0; i< num_of_vertices;i++){
		if(isCyclicUtil(i,visited,recStack))
			return true;
	}
	return false;
}



//Will find which nodes have no outgoing edges meaning they are at the end
//Will build the order from the back
//FIX:
//How it looks, is getting stuck on first element
int Graph::findEmpty(list<int> *adj, int array[]){
	list<int>::iterator j;
	for(int i = 0; i< num_of_vertices;i++){
		j = adj[i].begin();
		if(j == adj[i].end() && !inArray(i, array)){
			for(int k = 0; k <num_of_vertices;k++){
				adj[k].remove(i);
			}
			return i;
		}
	}
	return -1;

}

bool Graph::inArray(int elem, int array[]){
	for(int i = 0; i<num_of_vertices;i++){
		if(elem == array[i])
			return true;
	}
	return false;

}
