/*
 * In this file, you will write the structures and functions needed to
 * implement a priority queue.  Feel free to implement any helper functions
 * you need in this file to implement a priority queue.  Make sure to add your
 * name and @oregonstate.edu email address below:
 *
 * Name: Bruce Yan
 * Email: yanbr@oregonstate.edu
 */

#include <stdlib.h>

#include "pq.h"
#include "dynarray.h"

/*
 * This is the structure that represents a priority queue.  You must define
 * this struct to contain the data needed to implement a priority queue.
 */
struct pq{
	struct dynarray* arr;
};

//this is the struct that represents a node for a pq
struct pq_node{
	void* val;
	int priority;
};

/*
 * This function should allocate and initialize an empty priority queue and
 * return a pointer to it.
 */
struct pq* pq_create() {
	struct pq* pq = malloc(sizeof(struct pq));
	pq->arr = dynarray_create();
	return pq;
}


//functions: pq_node_create
//description: allocates memory for a pq_node and store values into it
//parameters: int priority, void* val
//preconditions: variables must exist
//postconditions: returns a pointer to a pq_node
struct pq_node* pq_node_create(int priority, void* val){
	struct pq_node* new_node = malloc(sizeof(struct pq_node));
	new_node->priority = priority;
	new_node->val = val;
	return new_node;
}


/*
 * This function should free the memory allocated to a given priority queue.
 * Note that this function SHOULD NOT free the individual elements stored in
 * the priority queue.  That is the responsibility of the caller.
 *
 * Params:
 *   pq - the priority queue to be destroyed.  May not be NULL.
 */
void pq_free(struct pq* pq) {
	dynarray_free(pq->arr);
	pq->arr = NULL;
	free(pq);
	pq = NULL;
}


/*
 * This function should return 1 if the specified priority queue is empty and
 * 0 otherwise.
 *
 * Params:
 *   pq - the priority queue whose emptiness is to be checked.  May not be
 *     NULL.
 *
 * Return:
 *   Should return 1 if pq is empty and 0 otherwise.
 */
int pq_isempty(struct pq* pq) {
	if (dynarray_isempty(pq->arr))
		return 1;
	else 
		return 0;
}


/*
 * This function should insert a given element into a priority queue with a
 * specified priority value.  Note that in this implementation, LOWER priority
 * values are assigned to elements with HIGHER priority.  In other words, the
 * element in the priority queue with the LOWEST priority value should be the
 * FIRST one returned.
 *
 * Params:
 *   pq - the priority queue into which to insert an element.  May not be
 *     NULL.
 *   value - the value to be inserted into pq.
 *   priority - the priority value to be assigned to the newly-inserted
 *     element.  Note that in this implementation, LOWER priority values
 *     should correspond to elements with HIGHER priority.  In other words,
 *     the element in the priority queue with the LOWEST priority value should
 *     be the FIRST one returned.
 */
void pq_insert(struct pq* pq, void* value, int priority) {
	struct pq_node* node = pq_node_create(priority, value);
	//insert a value
	dynarray_insert(pq->arr, node);
	//percolate upppp, up and awayyy
	spirited_away(pq, dynarray_size(pq->arr) - 1);
}

//function name: spirited_away
//description: perculation function used when inserting
//parameters: struct pq* pq, int child_index
//preconditions: the inputs must exist
//postconditions: inserted node gets spirited away to the top
void spirited_away(struct pq* pq, int child_index){
	while (child_index > 0){
		//find the parent index given the leaf node
		int parent_index = (child_index - 1)/2;
		//get the parent node and child nodes
		struct pq_node* parent = dynarray_get(pq->arr, parent_index);
		struct pq_node* child = dynarray_get(pq->arr, child_index);
		//swap 
		if(parent->priority > child->priority){
			dynarray_swap(pq->arr, parent_index, child_index);
			child_index = parent_index;
		}
		//keep swaping until we don't 
		else
			break;
	}	
}

//function name: percolate_down
//description: moves root node down to heap sort
//parameters: struct pq* pq, parent_index
//preconditions: numbers 
//postconditions: organizes the heap 
void percolate_down(struct pq* pq, int parent_index){
	//gives index of left and right childs of our node 
	int left_c_index = (2 * parent_index) + 1;
	int right_c_index = (2 * parent_index) + 2;
	//initialize min index variable
	int min_index = 0;

	//both children have to exist
	if(right_c_index < dynarray_size(pq->arr) && left_c_index < dynarray_size(pq->arr)){
		//initialize children
		struct pq_node* l_child = dynarray_get(pq->arr, left_c_index);
		struct pq_node* r_child = dynarray_get(pq->arr, right_c_index);
		//find the smallest child
		if (l_child->priority < r_child->priority)
			min_index = left_c_index;
		else
			min_index = right_c_index;
	}
	//if right child doesn't exist
	//since we insert nodes from left to right on the bottom, 
	//there should not exist an instance where a right child exists and a left child does not
	else if(right_c_index >= dynarray_size(pq->arr)){
		//if left child doesn exists then we stop 
		if (left_c_index >= dynarray_size(pq->arr))
			return;
		//if left child does exist then we set min value to the left child
		else{
			min_index = left_c_index;
		}
	}

	//initialize parent and min_child nodes
	struct pq_node* parent = dynarray_get(pq->arr, parent_index);
	struct pq_node* min_child = dynarray_get(pq->arr, min_index);

	//compare parent and smallest child
	if(parent->priority > min_child->priority){
		dynarray_swap(pq->arr, parent_index, min_index);
		//continue to perculate down the rest of the subtree
		percolate_down(pq, min_index);
	}
	
}


/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */
void* pq_first(struct pq* pq) {
	struct pq_node* node = dynarray_get(pq->arr, 0);
	return node->val;
}


/*
 * This function should return the priority value of the first item in a
 * priority queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a priority value.  May not be
 *     NULL or empty.
 *
 * Return:
 *   Should return the priority value of the first item in pq, i.e. the item
 *   with LOWEST priority value.
 */
int pq_first_priority(struct pq* pq) {
	struct pq_node* node = dynarray_get(pq->arr, 0);
	return node->priority;
}


/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value, and then remove that item
 * from the queue.
 *
 * Params:
 *   pq - the priority queue from which to remove a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */
void* pq_remove_first(struct pq* pq) {
	struct pq_node* node = dynarray_get(pq->arr, 0);
	//get the val we want to return once removed
	void* first_val = node->val;

	//find last index
	int last_index = dynarray_size(pq->arr) - 1;
	//swap the first first and last nodes together
	dynarray_swap(pq->arr, 0, last_index);

	//free the memory allocated in the first node, which is now in the end of the array
	free(dynarray_get(pq->arr, last_index));
	//remove the last_index and decrease the size
	dynarray_remove(pq->arr, last_index);

	//reorder the array by percolating the swapped value
	if (dynarray_size(pq->arr) > 0){
		percolate_down(pq, 0);
	}

	return first_val;
}
