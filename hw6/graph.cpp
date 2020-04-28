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

//This needs to be implemented
void Graph::sort(){
	int begin;
	int end;
	int flag = 0;
/*
	//first find if there is a begining
	for(int i = 0; i <num_of_vertices; i++){
		begin = i;
		if(!findElement(i)){
			break;
		}

		if(i == num_of_vertices-1 && findElement(i)){
			begin = -1;
		}
	}
	std::cout << "The begining is " << begin <<endl;
*/

	if(isCyclic()){
		cout << "The graph is cyclic and can't be ordered "<<endl;
		return;
	}
	cout<<"the graph is not cyclic"<<endl;
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


/*
//If it finds the element it is looking for then it returns true
//search is the element it is looking for
bool Graph::findElement(int search){
	list<int>::iterator j;
	for(int i = 0; i< num_of_vertices;i++){
		for(j = Adj[i].begin(); j != Adj[i].end(); j++){
			if(search == *j)
				return true;
		}

	}

	return false;

}
*/
