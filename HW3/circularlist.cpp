#include "circularlist.h"
#include <iostream>

using namespace std;

Linkedlist::Linkedlist(){
	rear = NULL;
}

Linkedlist::~Linkedlist(){
	if(is_empty())
		return;
	while(rear->next != rear){
		node *front = rear->next;
		node *n = front->next;
		delete front;
		rear->next = n;
	}
	delete rear;
}

bool Linkedlist::is_empty(){
	return (rear == NULL);
}

void Linkedlist::insertRear(int id){
	if(is_empty()){
		rear = new node(id, 0, NULL);
		rear->next = rear;
	}
	else{
		node *n = new node(id, 0, NULL);
		n->next = rear->next;
		rear->next = n;
		rear = n;
	}
}

void Linkedlist::deleteFront(){
//	node *front = rear->next;
	if(rear->next == rear){
		delete rear;
		rear = NULL;
	}
	else{
		node *n = rear->next;
		rear->next = rear->next->next;
		delete n;
//		front = rear->next;
	}
}

void Linkedlist::run_a_process(){
	//node *front = rear->next;
	if(is_empty())
		return;
	node *front = rear->next;
	front->percentage += 0.25;
	if(front->percentage == 1){
		cout << "Process " << front->process_id << " finished execution." << endl;
		deleteFront();
	}
	else{
		cout << "Process " << front->process_id << ": " << front->percentage << " percent completed." << endl;
		rear = front;
		front = rear->next;
	}
}

