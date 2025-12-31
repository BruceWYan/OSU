/*
 * This file contains a simple implementation of a singly-linked list.  See
 * the documentation below for more information on the individual functions in
 * this implementation.
 */

#include <stdlib.h>
#include <assert.h>

#include "list.h"
#include "hash_table.h"

/*
 * This structure is used to represent a single node in a singly-linked list.
 * It is not defined in list.h, so it is not visible to the user.
 */
// struct node {
//   void* val;
//   struct node* next;
// };

// /*
//  * This structure is used to represent an entire singly-linked list.  Note that
//  * we're keeping track of just the head of the list here, for simplicity.
//  */
// struct list {
//   struct node* head;
// };

/*
 * This function allocates and initializes a new, empty linked list and
 * returns a pointer to it.
 */
struct list* list_create() {
  struct list* list = malloc(sizeof(struct list));
  list->head = NULL;
  return list;
}

/*
 * This function frees the memory associated with a linked list.  Freeing any
 * memory associated with values still stored in the list is the responsibility
 * of the caller.
 *
 * Params:
 *   list - the linked list to be destroyed.  May not be NULL.
 */
void list_free(struct list* list) {
  assert(list);

  /*
   * Free all individual nodes.
   */
  struct node* next, * curr = list->head;
  while (curr != NULL) {
    next = curr->next;
    free(curr->val);
    free(curr);
    curr = next;
  }

  free(list);
}

/*
 * This function inserts a new value into a given linked list.  The new element
 * is always inserted as the head of the list.
 *
 * Params:
 *   list - the linked list into which to insert an element.  May not be NULL.
 *   val - the value to be inserted.  Note that this parameter has type void*,
 *     which means that a pointer of any type can be passed.
 */
void list_insert(struct list* list, void* val) {
  assert(list);

  /*
   * Create new node and insert at head.
   */
  struct node* temp = malloc(sizeof(struct node));
  temp->val = val;
  temp->next = list->head;
  list->head = temp;
}

/*
 * This function removes an element with a specified value from a given
 * linked list.  If the specified value appears multiple times in the list,
 * only the *first* instance of that value (i.e. the one nearest to the head
 * of the list) is removed.  This function is passed a function pointer that
 * is used to compare the value `val` to be removed with the values stored in
 * the list to determine which element (if any) to remove.
 *
 * Params:
 *   list - the linked list from which to remove an element.  May not be NULL.
 *   val - the value to be removed.  Note that this parameter has type void*,
 *     which means that a pointer of any type can be passed.
 *   cmp - pointer to a function that can be passed two void* values from
 *     to compare them for equality, as described above.  If the two values
 *     passed are to be considered equal, this function should return 0.
 *     Otherwise, it should return a non-zero value.
 */
void list_remove(struct list* list, void* val, int (*cmp)(void* a, void* b)) {
  assert(list);

  struct node* prev = NULL, * curr = list->head;
  while (curr) {
    /*
     * If current node's value matches query value, update node prior to curr
     * to point around curr, then free curr and return.  This removes curr from
     * the list.
     */
    if (cmp(val, curr->val) == 0) {
      if (prev) {
        prev->next = curr->next;
      } else {
        list->head = curr->next;
      }
      free(curr);
      return;
    }
    prev = curr;
    curr = curr->next;
  }
}

/*
 * This returns the position (i.e. the 0-based "index") of the first instance
 * of a specified value within a given linked list (i.e. the one nearest to the
 * head of the list).  If the list does not contain the specified value, this
 * function returns the special value -1. This function is passed a function
 * pointer called `cmp` that is used to compare the value `val` to be located
 * with the values stored in the list to determine which node (if any) contains
 * `val`.
 *
 * Params:
 *   list - the linked list from which to remove an element.  May not be NULL.
 *   val - the value to be located.  Note that this parameter has type void*,
 *     which means that a pointer of any type can be passed.
 *   cmp - pointer to a function that can be passed two void* values from
 *     to compare them for equality, as described above.  If the two values
 *     passed are to be considered equal, this function should return 0.
 *     Otherwise, it should return a non-zero value.
 *
 * Return:
 *   This function returns the 0-based position of the first instance of `val`
 *    within `list`, as determined by the function `cmp` (i.e. the closest
 *    such instance to the head of the list) or -1 if `list` does not contain
 *    the value `val`.
 */
int list_position(struct list* list, void* val, int (*cmp)(void* a, void* b)) {
  assert(list);

  struct node* curr = list->head;
  int i = 0;
  while (curr) {
    /*
     * If curr's value matches the query value, return the position of curr.
     */
    if (cmp(val, curr->val) == 0) {
      return i;
    }

    curr = curr->next;
    i++;
  }

  /*
   * If we got all the way through the list and no element matched `val`, then
   * `val` didn't exist in the list, so return -1.
   */
  return -1;
}

/*
 * This function should reverse the order of the nodes in a given linked list.
 * The reversal should be done *in place*, i.e. within the existing list, and
 * new memory should not be allocated to accomplish the reversal.  You should
 * be able to accomplish the reversal with a single pass through the list.
 *
 * Params:
 *   list - the linked list to be reversed.  May not be NULL.  When this
 *     function returns this should contain the reversed list.
 */
void list_reverse(struct list* list) {
  assert(list);

  /*
   * Reverse the list by reversing the individual nodes, making each node's
   * next pointer point to what used to be the previous node.  Move the list's
   * head pointer through the list as we iterate from node to node, so at the
   * end of the iteration, the head pointer will end up pointing to what used
   * to be the tail of the list.
   */
  struct node* next, * curr = list->head, * prev = NULL;
  while (curr) {
    next = curr->next;
    curr->next = prev;
    list->head = prev = curr;
    curr = next;
  }
}

/***
**Function Name: list_retrieve
**Description: removes the first node in the list and returns it
**Parameters: struct list* list, int capacity, int index
**Precondition: list must exist
**Postcondition: removes and returns, has O(1) runtime
***/
void* list_retrieve(struct list* list){
  //initialize
  struct node* current = list->head;
  //set the head to the next node
  list->head = current->next;
  //get the value we want to return
  void* retrieve = current->val;
  free(current);
  //releaseee meee
  return retrieve;
}  

/***
**Function Name: list_find
**Description: find a value 
**Parameters: struct list* list, void* val
**Precondition: list must exist
**Postcondition: returns a val that it finds, run time complexity O(4) = O(1)
***/
void* list_find(struct list* list, void* val) {
  //initialize nodes
  struct node* current = list->head;
  //iterate through lists
  while(current){
    //declare an ht node pointer to access values we want to find
    struct ht_node* node = current->val; 
    //cast as int pointers and then dereference to compare values
    if(*((int*)node->key) == *((int*)val)){
      return node->val;
    }
    //nexxttt please!
    current = current->next;
  }
  //if don't find it we got null
  return NULL;
}

/***
**Function Name: list_remove_ht
**Description: find a value and removes it 
**Parameters: struct list* list, void* val
**Precondition: list must exist
**Postcondition: removes a value, since list should be no longer than 4 nodes, we have runtime O(4) = O(1)
***/
void list_remove_ht(struct list* list, void* val){
  //initialize variables
  struct node* prev = NULL, * current = list->head;
  //iterate through the list
  while (current) {
    //declare an ht_node to get the value we want to compare
    struct ht_node* node = current->val; 
    //cast as an int pointer, then dereference
    if(*((int*)node->key) == *((int*)val)){
      //if node we want to remove is not at the beginning else we fix the head 
      if (prev) 
        prev->next = current->next;
      else 
        list->head = current->next;
      //freeee meeeeee
      free(current->val);
      free(current);
      return;
    }
    //keep going, you got this!!
    prev = current;
    current = current->next;
  }
}

/***
**Function Name: list_isempty
**Description: retrieves head of list, if pointing to NULL return 1, list is empty
**Parameters: struct list* list
**Precondition: list must exist
**Postcondition: checksd if a list is empty
***/
int list_isempty(struct list* list){
  if (list->head == NULL){
    return 1;
  }
  return 0;
}
