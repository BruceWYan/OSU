/**
** Program: linked_list.h
** Author: Bruce Yan
** Date: 12/04/2022
** Description: contains the .h file for linked_list class
** Input: n/A
** Output: contains member variables and functions 
**/
#ifndef LINKED_LIST
#define LINKED_LIST

#include "node.h"


class Linked_List {
	private:
		unsigned int length; // the number of nodes contained in the list
		Node* head; // a pointer to the first node in the list
		Node* current; 
		Node* previous; 
		void merge_sort(Node* &, bool);
		Node* merge(Node* &, Node* &, bool);
		void split_list(Node* &, Node* &, Node* &);

	public:

		int get_length(); // note: there is no set_length(unsigned int) (the reasoning should be intuitive)
		void print(); // output a list of all integers contained within the list
		void clear(); // delete the entire list (remove all nodes and reset length to 0)
		void push_front(int);
		void push_back(int);
		void insert(int, unsigned int);// insert a new value in the list at the specified index
		void sort_ascending(); // sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm
		// Note: it's okay if sort_ascending() calls a recursive private function to perform the sorting.
		void sort_descending(); // sort the nodes in descending order
		Node* get_head();
};
bool is_prime(int);
unsigned int count_prime(Linked_List&); //count and return the number of prime numbers within the list

#endif
