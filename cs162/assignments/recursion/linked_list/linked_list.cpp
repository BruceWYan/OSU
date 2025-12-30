/**
** Program: linked_list.cpp
** Author: Bruce Yan
** Date: 12/##/2022
** Description: contains functions definitions for linked_list class
** Input: n/A
** Output: member function definitions
**/
#include "linked_list.h"
#include <iostream>
using namespace std;

/**
** Function: get_length
** Description: returns the length of a linked list
** Parameters: N/A
** Pre-Conditions: a linked list must exist 
** Post-Conditions: returns the length of a list
**/
int Linked_List::get_length(){
    //initialize length to 0
    this->length = 0;
    current = head;
    while(current != NULL){
        this->length++;
        current = current->next;
    }
    return this->length;
}

/**
** Function: print
** Description: prints the values in the list
** Parameters: N/A
** Pre-Conditions: linked list must exist 
** Post-Conditions: prints out values
**/   
void Linked_List::print(){
	current = head;
	while(current != NULL){
		cout << current->val << " ";
		current = current->next; 
	}
	cout << endl;
}

/**
** Function: clear
** Description: clears the list and any allocated memory in the heap
** Parameters: N/A
** Pre-Conditions: linked list must exist 
** Post-Conditions: clears memory of linked list
**/
void Linked_List::clear(){
    current = head;
    Node* temp = NULL;
    while(current != NULL){
        //temp recieves the next node in the list
        temp = current->next;
        //delete the current node
        delete current;
        //set the current node to the next node in the list
        current = temp;
    }
    head = NULL;
}
   
/**
** Function: push_front
** Description: adds a new value to the front of a linked list 
** Parameters: int
** Pre-Conditions: n is an integer 
** Post-Conditions: adds a new node to the front of the list
**/   
void Linked_List::push_front(int n){
    //creates a new node
    current = new Node;
    //set new node
    current->val = n;
    //set current node to point to the start of list
    current->next = head;
    //set the curent to be the new start of the list
    head = current;
} 

/**
** Function: push_back
** Description: adds a new value to the back of a linked list
** Parameters: int
** Pre-Conditions: n is an integer 
** Post-Conditions: adds a new node to the backc of the list
**/
void Linked_List::push_back(int n){
    current = head;
    //iterate through list
    while (current->next != NULL){
        current = current->next;
    }
    //at back of the list
    //set the node pointer at back of list to point to a new node			
    if (current->next == NULL){
        current->next = new Node;
        current = current->next;
        current->val = n;	
    }
} 

/**
** Function: insert 
** Description: add a node into a list at any index
** Parameters: int, unsigned int
** Pre-Conditions: unsigned int must be a positive int
** Post-Conditions: inserts a node into a list a certain index
**/
void Linked_List::insert(int val, unsigned int index){
    //set a counter
    int count = 0;
    //if the index provided is larger than the list, exit function
    if(index > get_length())
        return;
    //assign head to current node
    current = head; 
    //use push_front if we are inserting a node at front of the list
    if (index == 0)
        push_front(val);
    else {
        //iterate through list
        while(current->next != NULL){
            //stop at one before index
            if (count == index - 1)
                break;	
            //iterate through list
            current = current->next;	
            //place holder
            count++; 
        }
        //assign the next node in list to temp holder
        Node* temp = current->next;
        //previous node points to new node
        current->next = new Node;
        //set current node on the new node created
        current = current->next;
        current->val = val;
        //assign the new node the pointer to the next node in the list
        current->next =  temp;
    }
} 

/**
** Function: 
** Description: 
** Parameters: 
** Pre-Conditions: 
** Post-Conditions: 
**/
void Linked_List::merge_sort(Node* &source, bool sort_type){
    Node* list_head = source;
    Node* a;
    Node* b;

    //base case, if the list is size 0 or 1
    if ((list_head == NULL) || (list_head->next == NULL)) {
        return;
    }
    //this will split the list into two lists, a and b
    split_list(list_head, a, b);

    //keep sorting the sublists recursively until each list is size 1
    merge_sort(a, sort_type);
    merge_sort(b, sort_type);

    //once sorted out, merge
    //merge the lists
    source = merge(a, b, sort_type);
}

/**
** Function: merge
** Description: merge two lists together recursively either in ascending or descending order
** Parameters: Node* &, Node* &, bool
** Pre-Conditions: ascending is either true or false
** Post-Conditions: if ascedning is true, merge lists together in ascending order, vice versa
**/
Node* Linked_List::merge(Node* &a, Node* &b, bool ascending){
    Node* sorted_list = NULL;
    //base case
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    //sorts with descending or ascending order
    if (ascending == false && a->val > b->val || ascending == true && a->val < b->val){
        //sets greater or lesser value to front of list
        sorted_list = a;
        //call funtion recursively which then sets a value to be next in the list
        sorted_list->next = merge(a->next, b, ascending);
    }
    else {
        sorted_list = b;
        sorted_list->next = merge(a, b->next, ascending);
    }
    return sorted_list;
}

/**
** Function: split_list
** Description: split a linked list in half
** Parameters: Node* &, Node* &, Node* &
** Pre-Conditions: takes in Node* by reference, they must all exist
** Post-Conditions: change Node* reference
**/
void Linked_List::split_list(Node* &source, Node* &start, Node* &middle){
    previous = source;
    current = source->next;
    //current reaches the end of list before previous
    //when current reaches the end previous reachs the node beforet he midpoint
    while (current != NULL) {
        //advances current once
        current = current->next;
        if (current != NULL) {
            //advances previous once
            previous = previous->next;
            //advances current again
            current = current->next;
        }
    }
    //previous is before the midpoint in the list
    //start will get the start of the list
    start = source;
    //middle gets the start of the middle of the list
    middle = previous->next;
    //set previous->next to NULL
    //start now points to the first half of the list rather than the whole list
    previous->next = NULL;
}

/**
** Function: sort_ascending
** Description: sort a linked list in ascending order
** Parameters: N/A
** Pre-Conditions: merge_sort bool parameter is set to true 
** Post-Conditions: sorts list in ascending order 
**/
void Linked_List::sort_ascending(){
    //if ascending then assign true in merge_sort
    merge_sort(head, true);
}

/**
** Function: sort_descending
** Description: sort a linked list in descending order
** Parameters: N/A
** Pre-Conditions: merge_sort bool parameter is set to false 
** Post-Conditions: sorts list in descending order
**/
void Linked_List::sort_descending(){
    //if not sort ascending, then we will assign false in merge_sort
    merge_sort(head, false);
} 

/**
** Function: get_head
** Description: accessor function
** Parameters: N/A
** Pre-Conditions: access private attributes
** Post-Conditions: returns head
**/
Node* Linked_List::get_head(){
    return head; 
}

/**
** Function: is_prime
** Description: checks a number to see if they are prime
** Parameters: int
** Pre-Conditions: must take a positive integer 
** Post-Conditions: return true or false
**/
bool is_prime(int n){
    if (n <= 1)
        return false;

    //start loop at 2 
    for (int i = 2; i < n; i++){
        //if at anypoint n is divisible by a number i, then we do not have a prime number
        if (n % i == 0)
            return false;        
    }
    return true;
}

/**
** Function: count_prime
** Description: counts the number of prime numbers in a linked list
** Parameters: Linked_List &
** Pre-Conditions: Takes in a linked list that exists
** Post-Conditions: returns the amount of prime numbers in a list
**/
unsigned int count_prime(Linked_List& l){
    Node* current = l.get_head();
    unsigned int count = 0;

    while(current != NULL){
        if (is_prime(current->val)){
            count++;
        }
        current = current->next;
    }
    return count;
} 

