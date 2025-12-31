
/*
 * This file is where you should implement your binary search tree.  It already
 * contains skeletons of the functions you need to implement (along with
 * documentation for each function).  Feel free to implement any additional
 * functions you might need.  Also, don't forget to include your name and
 * @oregonstate.edu email address below.
 *
 * Name: Bruce Yan
 * Email: yanbr@oregonstate.edu
 * Citations: GeeksforGeeks
 */

#include <stdlib.h>

#include "bst.h"
#include "stack.h"

/*
 * This structure represents a single node in a BST.  In addition to containing
 * pointers to its two child nodes (i.e. `left` and `right`), it contains two
 * fields representing the data stored at this node.  The `key` field is an
 * integer value that should be used as an identifier for the data in this
 * node.  Nodes in the BST should be ordered based on this `key` field.  The
 * `value` field stores data associated with the key.
 *
 * You should not modify this structure.
 */
struct bst_node {
  int key;
  void* value;
  struct bst_node* left;
  struct bst_node* right;
};


/*
 * This structure represents an entire BST.  It specifically contains a
 * reference to the root node of the tree.
 *
 * You should not modify this structure.
 */
struct bst {
  struct bst_node* root;
};

struct bst_node* new_node(void* value, int key){
  struct bst_node* node = malloc(sizeof(struct bst_node));
  node->value = value;
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  return node;
}

/*
 * This function should allocate and initialize a new, empty, BST and return
 * a pointer to it.
 */
struct bst* bst_create() {
  struct bst* bst = malloc(sizeof(struct bst));
  bst->root = NULL;
  return bst;
}

/*
 * This function should free the memory associated with a BST.  While this
 * function should up all memory used in the BST itself, it should not free
 * any memory allocated to the pointer values stored in the BST.  This is the
 * responsibility of the caller.
 *
 * Params:
 *   bst - the BST to be destroyed.  May not be NULL.
 */
void bst_free(struct bst* bst) {
  //call my frees function to recursively traverse the tree to delete nodes
  frees(bst->root);
  //free the entire node
  free(bst);
  return;
}

//function name: delete
//description: helper fucntion that deletes a node recurseivey
//parameter: struct bst_node* node
//precondition: bst must exist 
//postcondition: free bst
void frees(struct bst_node* node){
  //base case: if node is empty, then exit function
  if (node == NULL)
    return;
  //recursively traverse left subtree 
  frees(node->left);
  //recurseively traverse right subtree
  frees(node->right);
  //once we have gotten to the base case, we will being freeing every node
  free(node);
}

/*
 * This function should return the total number of elements stored in a given
 * BST.
 *
 * Params:
 *   bst - the BST whose elements are to be counted.  May not be NULL.
 */
int bst_size(struct bst* bst) {
  return (size(bst->root));
 
}

//function name: size
//description: returns size of the bst recursively
//parameters: struct bst_node* node
//preconditions: node must exist
//postconditions; return an int
int size(struct bst_node* node){
  //base case
  if (node==NULL)
    return 0;
  //this will traverse the tree
  //once we have traverses the tree and have reached the base case
  //we will begin to add 1 
  else 
    return (size(node->left) + 1 + size(node->right));
}

/*
 * This function should insert a new key/value pair into the BST.  The key
 * should be used to order the key/value pair with respect to the other data
 * stored in the BST.  The value should be stored along with the key, once the
 * right location in the tree is found.
 *
 * Params:
 *   bst - the BST into which a new key/value pair is to be inserted.  May not
 *     be NULL.
 *   key - an integer value that should be used to order the key/value pair
 *     being inserted with respect to the other data in the BST.
 *   value - the value being inserted into the BST.  This should be stored in
 *     the BST alongside the key.  Note that this parameter has type void*,
 *     which means that a pointer of any type can be passed.
 */
void bst_insert(struct bst* bst, int key, void* value) {
  //assign bst root a new root if we add a new root 
  bst->root = insertion(bst->root, key, value);
  
}

//function name: insertion
//description: inserts a node into a bst
//parameters: struct bst_node* node, int key
//precondition: tree must exist
//post condition: inserts a node
struct bst_node* insertion(struct bst_node* node, int key, void* value){
    //if the tree is empty, then we assign the root a new node
    //base case
    if (node == NULL){
        return new_node(value, key);
    }
    
    //traverse through the tree 
    //once we get to the a leaf node, we will impliment the base case
    if (key < node->key)
        node->left = insertion(node->left, key, value); 
    else if (key > node->key)
        node->right = insertion(node->right, key, value );
    //return the root 
    return node;
}



/*
 * This function should remove a key/value pair with a specified key from a
 * given BST.  If multiple values with the same key exist in the tree, this
 * function should remove the first one it encounters (i.e. the one closest to
 * the root of the tree).
 *
 * Params:
 *   bst - the BST from which a key/value pair is to be removed.  May not
 *     be NULL.
 *   key - the key of the key/value pair to be removed from the BST.
 */
void bst_remove(struct bst* bst, int key) {
  bst->root = delete(bst->root, key);
  return;
}

//function name: delete 
//description: deletes a node 
//parameters: struct bst_node* node, int key
//precondition: takes in a root node from bst 
//postcondition: returns a new root
struct bst_node* delete(struct bst_node* node, int key){
  //base case
  if (node == NULL)
    return NULL;
  //traverse down the tree
  if (key < node->key)
    node->left = delete(node->left, key);
  else if (key > node->key)
    node->right = delete(node->right, key);

  //action time!
  //once we get to the key we are looking for we take action
  else {
    struct bst_node* temp = NULL;
    
    //case if left child does not exist, then we store the right child
    if (node->left == NULL){
      temp = node->right;
      free(node);
      //we will assign our temp as the new root to the subtree
      return temp;
    }
    //same case as above
    else if (node->right == NULL){
      temp = node->left;
      free(node);
      //assign left child as the new root to the subtree 
      return temp;
    }

    //if then node we want to free has two children
    //get the smallest node to the right of node
    temp = smallest_node(node->right);
    //assign the node the in order successor from its right subtree
    node->value = temp->value;
    node->key = temp->key;
    //delete the node we reassigned 
    node->right = delete(node->right, temp->key);
  }
  return node;



}
//function name: smallest_node
//description: returns smalelset node of a give tree 
//parameters: struct bst_node* root
//precondition: root must exist
//postcondition: returns smallets node key
struct bst_node* smallest_node(struct bst_node* root){
  struct bst_node* current = root;
  //iterate the left subtree of any tree until we get to the last node
  while (current != NULL && current->left != NULL){
    current = current->left;
  }
  return current;
}



/*
 * This function should return the value associated with a specified key in a
 * given BST.  If multiple values with the same key exist in the tree, this
 * function should return the first one it encounters (i.e. the one closest to
 * the root of the tree).  If the BST does not contain the specified key, this
 * function should return NULL.
 *
 * Params:
 *   bst - the BST from which a key/value pair is to be removed.  May not
 *     be NULL.
 *   key - the key of the key/value pair whose value is to be returned.
 *
 * Return:
 *   Should return the value associated with the key `key` in `bst` or NULL,
 *   if the key `key` was not found in `bst`.
 */
void* bst_get(struct bst* bst, int key) {
  struct bst_node* node = bst->root;
  //iterate through the list
  while (node != NULL){
    //we will search though the tree iteratively 
    //move focus to the right node 
    if (key > node->key)
      node = node->right;
    //move focus to the left node 
    else if (key < node->key)
      node = node->left;
    //if our key matches then we return
    else 
      return node->value;
  }
}

/*****************************************************************************
 **
 ** BST puzzle functions
 **
 *****************************************************************************/

/*
 * This function should return the height of a given BST, which is the maximum
 * depth of any node in the tree (i.e. the number of edges in the path from
 * the root to that node).  Note that the height of an empty tree is -1 by
 * convention.
 *
 * Params:
 *   bst - the BST whose height is to be computed
 *
 * Return:
 *   Should return the height of bst.
 */
 int bst_height(struct bst* bst) {
  return height(bst->root);
 }

 //funciton name: height
 //description: finds the height recursively
 //parameters: struct bst_node* node
 //precondition: takes in a node pointer
 //postcondition: returns an int
 int height(struct bst_node* node){
  //base case
  //satisfies the need that if a tree is empty it is negative 1 height
  if (node == NULL)
    return -1;
  //traversal 
  else {
    //traversal through the tree
    int left_height = height(node->left);
    int right_height = height(node->right);

    //once we get through the tree, we will implement these conditions
    if(left_height > right_height)
      return left_height + 1;
    else
      return right_height + 1;
  }
 }
 

/*
 * This function should determine whether a specified value is a valid path
 * sum within a given BST.  In other words, this function should check whether
 * the given BST contains any path from the root to a leaf in which the keys
 * sum to the specified value.
 *
 * Params:
 *   bst - the BST whose paths sums to search
 *   sum - the value to search for among the path sums of `bst`
 *
 * Return:
 *   Should return 1 if `bst` contains any path from the root to a leaf in
 *   which the keys add up to `sum`.  Should return 0 otherwise.
 */
int bst_path_sum(struct bst* bst, int sum) {
  return path_sum(bst->root, sum);
}

//function name: path_sum
//description: recursivley traverses through the bst to see if a sum matchs one of the values
//parameters: struct bst_node* node, int sum
//pre-condition: takes in a nost from a bst and a sum
//post-condition: return 1 or 0
int path_sum(struct bst_node* node, int sum){
  //base case
  if (node == NULL )
    return 0;
  //dereference void pointer to an int
  int val = *((int*)node->value);
  //if the node value we are looking for is our current
  if (node->left == NULL && node->right == NULL && sum - val == 0)
    return 1;
  //traverse through the tree, if we find a value we are looking for in 
  //either subtree, we will return 
  return path_sum(node->left, sum - val) || path_sum(node->right, sum - val);
}
  


/*
 * This function should compute a range sum in a given BST.  Specifically, it
 * should compute the sum of all keys in the BST between a given lower bound
 * and a given upper bound.  For full credit, you should not process any subtree
 * whose keys cannot be included in the range sum.
 *
 * Params:
 *   bst - the BST within which to compute a range sum
 *   lower - the lower bound of the range over which to compute a sum; this
 *     should be considered an *inclusive* bound; in other words a key that's
 *     equal to this bound should be included in the sum
 *   upper - the upper bound of the range over which to compute a sum; this
 *     should be considered an *inclusive* bound; in other words a key that's
 *     equal to this bound should be included in the sum
 *
 * Return:
 *   Should return the sum of all keys in `bst` between `lower` and `upper`.
 */
int bst_range_sum(struct bst* bst, int lower, int upper) {
  int sum = 0;
  range_sum(bst->root, lower, upper, &sum);
  return sum;
}
//function name: range_sum
//description: recursively finds the sum of of a range
//parameters: struct bst_node* node, int lower, int upper, int sum
//preconditions: parameters inputted must exist
//postcondition: returns an int
void range_sum(struct bst_node* root, int lower, int upper, int *sum){
  //base case 
  if (root == NULL)
    return;

  //traverse through the tree
  range_sum(root->left, lower, upper, sum);
  range_sum(root->right, lower, upper, sum);

  //dereference void*
  //if our current node is between our bounds we will add it to our sum
  if (*((int*)root->value) >= lower && *((int*)root->value) <= upper)
    *sum += *((int*)root->value);

}


/*****************************************************************************
 **
 ** BST iterator definition (extra credit only)
 **
 *****************************************************************************/

/*
 * Structure used to represent a binary search tree iterator.  It contains
 * only a reference to a stack to be used to implement the iterator.
 *
 * You should not modify this structure.
 */
struct bst_iterator {
  struct stack* stack;
};

/*
 * This function should allocate and initialize an iterator over a specified
 * BST and return a pointer to that iterator.
 *
 * Params:
 *   bst - the BST for over which to create an iterator.  May not be NULL.
 */
struct bst_iterator* bst_iterator_create(struct bst* bst) {
  /*
   * FIXME:
   */
  return NULL;
}

/*
 * This function should free all memory allocated to a given BST iterator.
 * It should NOT free any memory associated with the BST itself.  This is the
 * responsibility of the caller.
 *
 * Params:
 *   iter - the BST iterator to be destroyed.  May not be NULL.
 */
void bst_iterator_free(struct bst_iterator* iter) {
  /*
   * FIXME:
   */
  return;
}

/*
 * This function should indicate whether a given BST iterator has more nodes
 * to visit.  It should specifically return 1 (true) if the iterator has at
 * least one more node to visit or 0 (false) if it does not have any more
 * nodes to visit.
 *
 * Param:
 *   iter - the BST iterator to be checked for remaining nodes to visit.  May
 *     not be NULL.
 */
int bst_iterator_has_next(struct bst_iterator* iter) {
  /*
   * FIXME:
   */
  return 0;
}

/*
 * This function should return both the value and key associated with the
 * current node pointed to by the specified BST iterator and advnce the
 * iterator to point to the next node in the BST (in in-order order).
 *
 * Because a function can't return two things, the key associated with the
 * current node should be returned the normal way, while its value should be
 * returned via the argument `value`.  Specifically, the argument `value`
 * is a pointer to a void pointer.  The current BST node's value (a void
 * pointer) should be stored at the address represented by `value` (i.e. by
 * dereferencing `value`).  This will look something like this:
 *
 *   *value = current_node->value;
 *
 * Parameters:
 *   iter - BST iterator.  The key and value associated with this iterator's
 *     current node should be returned, and the iterator should be updated to
 *     point to the next node in the BST (in in-order order).  May not be NULL.
 *   value - pointer at which the current BST node's value should be stored
 *     before this function returns.
 *
 * Return:
 *   This function should return the key associated with the current BST node
 *   pointed to by `iter`.
 */
int bst_iterator_next(struct bst_iterator* iter, void** value) {
  /*
   * FIXME:
   */
  if (value) {
    *value = NULL;
  }
  return 0;
}
