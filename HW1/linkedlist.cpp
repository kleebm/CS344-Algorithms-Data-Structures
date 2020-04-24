#include "linkedlist.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList(){
	head = new node(0, NULL);
	size = 0;
}

LinkedList::~LinkedList(){
	while(head != NULL){
		node *p = head->next;
		delete head;
		head = p;
	}
}

void LinkedList::print(){
	if(size == 0)
		return;
	node *p = head->next;
	cout << p->item;
	p = p->next;
	while(p != NULL){
		cout << " -> " << p->item;
		p = p->next;
	}
	cout << endl;
}

bool LinkedList::searchFor(int d){
	node *p = head->next;
	while(p != NULL){
		if(p->item == d)
			return true;
		p = p->next;
	}
	return false;
}

void LinkedList::update(int pos, int data){
	if(pos < 1 || pos > size){
		cout << "error";
		return;
	}
	node *p = head->next;
	int i = 1;
	while(i < pos){
		p = p-> next;
		i++;
	}
	p->item = data;
}


void LinkedList::insertAt(int pos, int data){
	if(pos < 1 || pos > size + 1){
		cout << "error";
		return;
	}

	node *p = head;
	int i = 0;
	while(i < pos - 1){
		p = p->next;
		i++;
	}

	node *n = new node(data, NULL);
	n->next = p->next;
	p->next = n;
	size++;
}

void LinkedList::deleteAt(int pos){
	if(pos < 1 || pos > size){
		cout << "error";
		return;
	}

	node *p = head;
	int i = 0;
	while(i < pos - 1){
		p = p->next;
		i++;
	}

	node *n = p->next;
	p->next = n->next;
	delete n;
	size--;
}


int LinkedList::getData(int pos){
	node *current = head->next; 
	int count = 0;
	while(current != NULL){
		if(count == pos)
			return (current->item);
		count++;
		current = current->next;
	}
}

void LinkedList::reverse_and_duplicate(){
	//Please implement this function.
	//reversing
	int count = 1;
	while(count <= size ){ 
		int data = getData(size-1);
		//cout << data <<endl;
		insertAt(count, data);
		deleteAt(size);
		count++;
	}
	

	
	//duplicating
	for(int i = 0; i < size; i= i +2){
		//cout << getData(i) << endl;
		insertAt(i+1,getData(i));
		//print();
		
	}
	
}
