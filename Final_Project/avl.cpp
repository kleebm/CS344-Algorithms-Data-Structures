#include "avl.h"
#include <iostream>

AVL::AVL(){
	root = NULL;
}


/*
//Methods used to calculate and print height of the tree
int height(node *n){
	if(n == NULL)
		return -1;
	else
		return n->height;
}

void AVL::showHeight(){
	cout<<"The height of the tree is: " <<height(root)<<endl;
}
*/


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


//Methods used for inserting a node into the tree
node* insert_helper(node *r, student *s){
	if(r == NULL)
		return new node(s,0,0,NULL,NULL);
	if(s->id == r->s->id)
		return r;
	else if(s->id > r->s->id)
		r->right_child = insert_helper(r->right_child,s);
	else
		r->left_child = insert_helper(r->left_child,s);

//	return balance(r);
}


void AVL::insert(student *s){
	insert_helper(root,s);
}
