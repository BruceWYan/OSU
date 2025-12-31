/*
 * In this file, you will write the structures and functions needed to
 * implement a hash table.  Feel free to implement any helper functions
 * you need in this file to implement a hash table.  Make sure to add your
 * name and @oregonstate.edu email address below:
 *
 * Name: Bruce Yan
 * Email: yanbr@oregonstate.edu
 */

 /***
**Function Name: 
**Description: 
**Parameters: 
**Precondition: 
**Postcondition: 
***/

#include <stdlib.h>

#include "dynarray.h"
#include "list.h"
#include "hash_table.h"


/*
 * This is the structure that represents a hash table.  You must define
 * this struct to contain the data needed to implement a hash table.
 */
struct ht{
    int size;
    struct dynarray* table;
};

// struct ht_node{
//     void* key;
//     void* val;
// };


/*
 * This function should allocate and initialize an empty hash table and
 * return a pointer to it.
 */
struct ht* ht_create(){
    struct ht* ht = malloc(sizeof(struct ht));
    ht->size = 0;
    ht->table = dynarray_create();
    for (int i = 0; i < dynarray_capacity(ht->table); i++){
        struct list* bucket = list_create();
        dynarray_insert(ht->table, bucket);
    }
    return ht;
}

/***
**Function Name: ht_node_create()
**Description: create an ht node
**Parameters: void* value, void* key
**Precondition: N/A
**Postcondition: retea a ht_node
***/
struct ht_node* ht_node_create(void* value, void* key){
    struct ht_node* ht_node = malloc(sizeof(struct ht_node));
    ht_node->key = key;
    ht_node->val = value;
    return ht_node;
}

/*
 * This function should free the memory allocated to a given hash table.
 * Note that this function SHOULD NOT free the individual elements stored in
 * the hash table.  That is the responsibility of the caller.
 *
 * Params:
 *   ht - the hash table to be destroyed.  May not be NULL.
 */
void ht_free(struct ht* ht){
    for (int i = 0; i < dynarray_size(ht->table); i++){
        list_free(dynarray_get(ht->table, i));
    }
    dynarray_free(ht->table);
    free(ht);
    return;
}

/*
 * This function should return 1 if the specified hash table is empty and
 * 0 otherwise.
 *
 * Params:
 *   ht - the hash table whose emptiness is to be checked.  May not be
 *     NULL.
 *
 * Return:
 *   Should return 1 if ht is empty and 0 otherwise.
 */
int ht_isempty(struct ht* ht){
    if (ht->size == 0)
        return 1;
    return 0;
}


/*
 * This function returns the size of a given hash table (i.e. the number of
 * elements stored in it, not the capacity).
 */
int ht_size(struct ht* ht){
    return ht->size;
}


/*
 * This function takes a key, maps it to an integer index value in the hash table,
 * and returns it. The hash algorithm is totally up to you. Make sure to consider
 * Determinism, Uniformity, and Speed when design the hash algorithm
 *
 * Params:
 *   ht - the hash table into which to store the element.  May not be NULL.
 *   key - the key of the element to be stored
 *   convert - pointer to a function that can be passed the void* key from
 *     to convert it to a unique integer hashcode
 */
int ht_hash_func(struct ht* ht, void* key, int (*convert)(void*)){
    //convert the void*
    int hash = convert(key);
    //use the size of the ht to return an index for the key
    //using the ht->size also makes sure that the index is within bounds of our table
    int index = hash % dynarray_capacity(ht->table);
    return index;
}

/***
**Function Name: ht_rehash
**Description: rehash the values after resize
**Parameters: struct ht* ht
**Precondition: ht must exist
**Postcondition: rehashes the values, run time of O(N)
***/
void ht_rehash(struct ht* ht){
    //create a new array of link lists, O(N) runtime 
    int new_capacity = 2 * dynarray_capacity(ht->table);

    // struct dynarray* temp = dynarray_create();
    // for (int i = 0; i < new_capacity; i++){
    //     dynarray_insert(temp, list_create());
    // }

    void** new_data = malloc(new_capacity * sizeof(void*));
    for (int i = 0; i < new_capacity; i++)
        new_data[i] = list_create();

    
    //get the ht_nodes from our old array of linked lists 
    //once we have them we will rehash them and relocate them in our new array of linked lists
    for (int i = 0; i < dynarray_capacity(ht->table); i++){
        struct list* bucket = dynarray_get(ht->table, i);

        while (list_isempty(bucket) == 0){
            struct ht_node* node = list_retrieve(bucket);
            int index = *((int*)node->key) % new_capacity; 
            list_insert(new_data[index], node);
        }
        //once the first linked list in our old array has been looked through, we will free it
        list_free(bucket);
    }
    //resize our hash table with our new array and capacity

    dynarray_resize(ht->table, new_data, new_capacity);
}


/*
Rehash
    void** new_data = malloc(sizeof(void*) * (2 * old_capacity))
    
    insert lists into our new array i.e. for loop list_create()

    loop through old array
        get the bucket(list) at the index 
        get the ht_element of the first element in the bucket (list_pop i.e. return the first value and remove the node)
        while(bucket is not empty)
            hash index 
            list insert (new_array[hash index], ht_element)

        free(bucket)
    free(old_array)

    Go into hash table, access the dynarray and access that data and change it to point to new_data nad also capacity



*/

/*
 * This function should insert a given element into a hash table with a
 * specified key.  Note that you cannot have two same keys in one hash table.
 * If the key already exists, update the value associated with the key.  
 * This function is passed a function pointer that is used to convert the key (void*) 
 * to a unique hashcode (int). 
 * Resolution of collisions is requried, use either chaining or open addressing.
 * If using chaining, double the number of buckets when the load factor is >= 4
 * If using open addressing, double the array capacity when the load factor is >= 0.75
 * load factor = (number of elements) / (hash table capacity)
 *
 * Params:
 *   ht - the hash table into which to insert an element.  May not be NULL.
 *   key - the key of the element
 *   value - the value to be inserted into ht.
 *   convert - pointer to a function that can be passed the void* key from
 *     to convert it to a unique integer hashcode
 */

void ht_insert(struct ht* ht, void* key, void* value, int (*convert)(void*)){
    //find our hash code index
    int index = ht_hash_func(ht, key, convert);

    //condition to check if our value we want to insert already exists
    if (NULL != ht_lookup(ht, key, convert)){
        //get the value we looked up
        int* look = ht_lookup(ht, key, convert);
        //if the values does exist we will not insert
        if (*(look) == *((int*)key))
            return;
    }
    
    //insert our values and keys
    //get the bucket we want to insert into based on our index
    struct list* bucket = dynarray_get(ht->table, index);
    //create an ht_node
    struct ht_node* node = ht_node_create(value, key);
    //insert our node into our bucket
    list_insert(bucket, node);
    //increase the elements
    ht->size++;

    //check load factor to rehash and resize
    int load_factor = ht->size / dynarray_capacity(ht->table);
    if(load_factor >= 4)
        ht_rehash(ht);
}

/*
 * This function should search for a given element in a hash table with a
 * specified key provided.   
 * This function is passed a function pointer that is used to convert the key (void*) 
 * to a unique hashcode (int). 
 * If the key is found, return the corresponding value (void*) of the element,
 * otherwise, return NULL
 *
 * Params:
 *   ht - the hash table into which to loop up for an element.  May not be NULL.
 *   key - the key of the element to search for
 *   convert - pointer to a function that can be passed the void* key from
 *     to convert it to a unique integer hashcode
 */
void* ht_lookup(struct ht* ht, void* key, int (*convert)(void*)){
    int index = ht_hash_func(ht, key, convert);
    //get the bucket we that has our key we are looking for
    struct list* bucket = dynarray_get(ht->table, index);
    //traverse through the list to find our value and return it
    return list_find(bucket, key);
}


/*
 * This function should remove a given element in a hash table with a
 * specified key provided.   
 * This function is passed a function pointer that is used to convert the key (void*) 
 * to a unique hashcode (int). 
 * If the key is found, remove the element and return, otherwise, do nothing and return 
 *
 * Params:
 *   ht - the hash table into which to remove an element.  May not be NULL.
 *   key - the key of the element to remove
 *   convert - pointer to a function that can be passed the void* key from
 *     to convert it to a unique integer hashcode
 */
void ht_remove(struct ht* ht, void* key, int (*convert)(void*)){
    int index = ht_hash_func(ht, key, convert);
    //get the bucket that has our value we want to remove
    struct list* bucket = dynarray_get(ht->table, index);
    //remove ht node in our bucket
    list_remove_ht(bucket, key);
    //decrease the number of elements
    ht->size--;
    return;
} 
