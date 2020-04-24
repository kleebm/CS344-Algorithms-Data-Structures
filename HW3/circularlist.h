#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

struct node{
	int process_id;
	float percentage;
	node *next;
	node(int id, float percent, node *n)
	{process_id = id; percentage = percent; next = n;}
};

class Linkedlist{
	private:
		node *rear;//get rid of front
	public:
		Linkedlist();
		~Linkedlist();
		bool is_empty();
		void insertRear(int id);
		void deleteFront();
		void run_a_process();
};

#endif
