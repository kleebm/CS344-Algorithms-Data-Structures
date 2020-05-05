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
	cout<<"student id: " << r->s->id << endl;
	print_helper(r->right_child);
}

void AVL::printAll(){
	print_helper(root);
}


//Methods helping out the insert method
void computeBF(node *r){
	r->height = max(height(r->left_child), height(r->right_child)) + 1;
	r->bf = height(r->left_child) - height(r->right_child);
}

node *leftRotate(node *x){
	node *y = x->right_child;
	node *beta = y->left_child;

	y->left_child = x;
	x->right_child = beta;

	computeBF(x);
	computeBF(y);

	return y;
}

node *rightRotate(node *y){
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

	return r;
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

	return balance(r);
}

void AVL::insert(student *s){
	root = insert_helper(root,s);
}



//Methods used to delete elements
int findMin(node *r){
	if(r->left_child == NULL)
		return r->s->id;
	else
		return findMin(r->left_child);
}

node* remove_helper(node *r, int id){
	if(r == NULL)
		return NULL;

	else if(id > r->s->id){
		r->right_child = remove_helper(r->right_child,id);
		return r;
	}

	else if(id < r->s->id){
		r->left_child = remove_helper(r->left_child, id);
		return r;
	}

	else{
		if(r->left_child == NULL && r->right_child == NULL){
			delete r;
			return NULL;
		}

		else if(r->left_child == NULL){
			node *n = r->right_child;
			delete r;
			return n;
		}

		else if(r->right_child == NULL){
			node *n = r->left_child;
			delete r;
			return n;
		}

		else{
			r->s->id = findMin(r->right_child);
			r->right_child = remove_helper(r->right_child,r->s->id);
			return r;
		}

	}


}

void AVL::deleteID(int id){
	root = remove_helper(root,id);
	computeBF(root);
}


//methods for finding students gpa based on their id
float GPA_helper(node *r, int id){
	if(r->s->id == id)
		return r->s->gpa;

	else if(r->s->id > id)
		return GPA_helper(r->left_child,id);

	else if(r->s->id < id)
		return GPA_helper(r->right_child,id);

}

float AVL::GPA(int id){
	float gpa = GPA_helper(root,id);
}


//methods for finding max GPA
float max_helper(node *r,float max){
	if(r == NULL)
                return max;

        max = max_helper(r->left_child,max);
        if(r->s->gpa > max)
		max = r->s->gpa;
        max = max_helper(r->right_child,max);
	return max;

}

float AVL::maxGPA(){
	float max = max_helper(root,-1);
	return max;
}
