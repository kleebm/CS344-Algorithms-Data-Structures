#include "stack.h"

Dual_stack::Dual_stack(){
	int max_size = 10;

//	elements = new int [max_size];
	//arr1 = new int[max_size];
	int current_size_first = 0;
	//arr2 = new int[max_size];
	int current_size_second = 0;
}

Dual_stack::~Dual_stack(){
	
}

void Dual_stack::push_first(int elem){
	elements[current_size_first] = elem;
	current_size_first++;
}

int Dual_stack::pop_first(){
	current_size_first--;
	return elements[current_size_first];
}

bool Dual_stack::is_empty_first(){
	return current_size_first == 0;	
}

bool Dual_stack::is_full(){
	if(current_size_first + current_size_second > 10  ){
		return true;
	}
	else if(current_size_first == 10 || current_size_second == 10){
		return true;
	}
	else
		return false;
}

void Dual_stack::push_second(int elem){
	elements[10 - current_size_second] = elem;
	current_size_second++;
}

int Dual_stack::pop_second(){
	current_size_second--;
	return elements[10 - current_size_second];
}

bool Dual_stack::is_empty_second(){
	return current_size_second == 0;
}


