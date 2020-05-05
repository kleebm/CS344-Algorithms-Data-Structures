#include "avl.h"
#include <iostream>
#include <cstddef>

using namespace std;

AVL::AVL(){
	root = NULL;
}


//Methods used to calculate and print height of the tree
int height(node *n){
	if(n == NULL)
		return -1;
	else
		return n->height;
}

void AVL::showHeight(){
	cout<<height(root)<<endl;
}



//Methods used for printing out the nodes in order
void print_helper(node *r){
	if(r == NULL)
		return;

	print_helper(r->left_child);
	cout<<"student id: " << r->s->id <<endl;
	print_helper(r->right_child);
}

void AVL::printAll(){
	print_helper(root);
}


//Methods helping out the insert method
void computeBF(node *r){
	cout<<"bf calc"<<endl;
	r->height = max(height(r->left_child), height(r->right_child)) + 1;
	r->bf = height(r->left_child) - height(r->right_child);
	cout<<"done with BF calculation"<<endl;
}

node *leftRotate(node *x){
	cout<<"left rotate"<<endl;
	node *y = x->right_child;
	node *beta = y->left_child;

	y->left_child = x;
	x->right_child = beta;

	computeBF(x);
	computeBF(y);

	return y;
}

node *rightRotate(node *y){
	cout<<"right rotate"<<endl;
	node *x = y->left_child;
	node *beta = x->right_child;

	x->right_child = y;
	x->left_child = beta;

	computeBF(y);
	computeBF(x);

	return x;
}


node *balance(node *r){
	computeBF(r);
	cout<<"balance"<<endl;
	if(r->bf == 2 && r->left_child->bf >= 0)//left left
		return rightRotate(r);
	else if(r->bf == 2 && r->left_child->bf == -1){ //left right
		r->left_child = leftRotate(r->left_child);
		return leftRotate(r);
	}

	if(r->bf == -2 && r->right_child->bf <= 0){//right right
		return leftRotate(r);
	}
	else if(r->bf == 2 && r->right_child->bf == 1){//left right
		r->right_child = rightRotate(r->right_child);
		return leftRotate(r);
	}

	cout<<"Done with balance"<<endl;
	return r;
}



//Methods used for inserting a node into the tree
node* insert_helper(node *r, student *s){
	cout<<"insert helper"<<endl;
	if(r == NULL)
		return new node(s,0,0,NULL,NULL);
	if(s->id == r->s->id)
		return r;
	else if(s->id > r->s->id)
		r->right_child = insert_helper(r->right_child,s);
	else
		r->left_child = insert_helper(r->left_child,s);

	return balance(r);
}


void AVL::insert(student *s){
	root = insert_helper(root,s);
}
