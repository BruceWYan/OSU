/*
 * In this file, you'll implement Dijkstra's algorithm to find the least
 * expensive paths in the graph defined in `airports.dat`.  Don't forget to
 * include your name and @oregonstate.edu email address below.
 *
 * Name: Bruce Yan
 * Email: yanbr@oregonstate.edu
 */

#include <stdio.h>
#include <stdlib.h>
#include "pq.h"

#define DATA_FILE "airports.dat"
#define START_NODE 0

struct node{
	int cost;
	int prev;
	int current;
};


//function: matrix create
//description: cretaes a matrix and assigns each value in the matrix 0 
//parameters: int n_nodes
//precondition: nodes can not be less than 0
//postcondition: returns a matrix
struct node** matrix_create(int n_nodes){
	//allocation memory to the heap
	struct node** adj_matrix = malloc(sizeof(struct node*) * n_nodes);
	struct node* temp;

	//assign into nodes in 2d array
	for(int i =0; i < n_nodes; i++){
		temp = malloc(sizeof(struct node) * n_nodes);
		for(int j = 0; j < n_nodes; j++){
			temp[j].cost = 0;
			temp[j].prev = 0;
			temp[j].current = 0;
		}
		adj_matrix[i] = temp;
	}
	//return array
	return adj_matrix;
}

//function: print_paths_toheaven
//description: prints the paths that we find 
//parameters: struct node** adj_matrix, int prev[], int i
//preconditions: takes in variables
//postcondition: prints out to dispaly
void print_paths_toheaven(struct node** adj_matrix, int prev[], int i){
	if (prev[i] == 0){
		printf("Path: 0->");
		return;
	}

	print_paths_toheaven(adj_matrix, prev, prev[i]);
	printf("%d->", prev[i]);
	return;
}

int main(int argc, char const *argv[]) {
	/*
	 * Open file and read the first two int: num of nodes, num of edges
	 */
	int n_nodes, n_edges;
	FILE* file = fopen(DATA_FILE, "r");
	fscanf(file, " %d %d ", &n_nodes, &n_edges);

	struct node** adj_matrix = matrix_create(n_nodes);

	for (int i = 0; i < n_edges; i++){
		//initialize variables
		int start_i, destination_j, cost;
		
		//store values from file to vairable
		fscanf(file, " %d %d %d", &start_i, &destination_j, &cost);

		//create paths in the matric 
		adj_matrix[start_i][destination_j].cost = cost;
		adj_matrix[start_i][destination_j].prev = start_i;
		adj_matrix[start_i][destination_j].current = destination_j;

	}

	//initialize array for prev and cost values
	int cost[n_nodes];
	int prev[n_nodes];
	for (int i = 0; i < n_nodes; i++){
		//keeps track of the cost to get from node 0 to node i 
		cost[i] = __INT_MAX__; //initialize each element with a large value
		prev[i] = -1; //initialize each with -1
	}


	struct pq* queue = pq_create();
	//our source for our graph is at the 0 node
	struct node* start = &adj_matrix[0][0];	
	
	//insert our source into the pq
	pq_insert(queue, start, 0);

	//while the pq is not empty we will go thorugh our while loop
	while(pq_isempty(queue) == 0){
		// we will assign the first cost of our highest priority node to c
		//this prioiryt integer represents cost to get to 
		int c = pq_first_priority(queue);
		//we will get the highest priority node and remove it
		struct node* node = pq_remove_first(queue);
		//checks if the cost c of the current node is less than the cost of the current node in the cost array. 
		//this will always be the case
		if (c < cost[node->current]){
			//assign the cost of our current node a new one 
			cost[node->current] = c;
			//keep track of our prev node
			prev[node->current] = node->prev;
			
			for (int i =0; i < n_nodes; i++){
				//checks to see if our current node has any other paths
				if (adj_matrix[node->current][i].cost > 0){
					int c_i = adj_matrix[node->current][i].cost;
					//insert the price chaiinnnnn
					//the price will keep adding on to each other as it continues to run
					pq_insert(queue, &adj_matrix[node->current][i], c + c_i);
				}

			}

		}
	}

	//prints the paths
	printf("\n");
	for(int i = 0; i < n_nodes; i++){
		printf("Node %d:\nCost: %d\n", i, cost[i]);

		print_paths_toheaven(adj_matrix, prev, i);
		printf("%d \n\n", i);
	}

	//free the 2d array (adj_matrix)
	for(int i = 0; i < n_nodes; i++){
		free(adj_matrix[i]);
	}
	free(adj_matrix);

	//free the pq 
	pq_free(queue);
	
	/*
	 * Write your code here to find the
	 * least-cost paths from node 0 to all other nodes in the graph.  Make sure
	 * to print out the least-cost paths you find at the end.
	 *
	 * FIXME: 
 	 */


	fclose(file);

	 
  return 0;
}
