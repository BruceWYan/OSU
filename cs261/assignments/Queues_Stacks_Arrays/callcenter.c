#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
#include "stack.h"


/*
 * Define your call struct here.
 */
//this struct keeps track of each individual call
struct call{
	int id; 
	char name[256]; //stores array of char for name size 256, only 255 characters
	char reason[1028]; //stores array of char for call reason size 1028, only 1027 characters
};

//this struct keeps track of the queue and stack that we create for the callcenter
struct callcenter{
	struct queue* q;
	struct stack* s;
};

/**
** Function: callcenter_create
** Description: creates a callcenter
** Parameters: n/a
** Pre-Conditions: createa callccenter
** Post-Conditions: allocated memory
**/
struct callcenter* callcenter_create(){
	struct callcenter* callcenter = malloc(sizeof(struct callcenter));
	callcenter->q = queue_create();
	callcenter->s = stack_create();
	return callcenter;
}

/** Function: display_callcenter
** Description: display options
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: displays text
**/
void display_callcenter(){
	printf("[1] Receive a new call\n");
	printf("[2] Answer a call\n");
	printf("[3] Current state of the stack - answered calls\n");
	printf("[4] Current state of the queue - calls to be answered\n");
	printf("[5] Quit\n");
}



/** Function: get_option
** Description: gets option from user 
** Parameters: n/a
** Pre-Conditions: takes in input
** Post-Conditions: returns int
**/
int get_option(){
	int option = 0;
	printf("Choose an option: ");
	//pass the users input into the option
	scanf("%d", &option);
	return option;
}

/** Function: check_queue
** Description: checks the queue if there are values in there
** Parameters: struct queue* q
** Pre-Conditions: checks input
** Post-Conditions: returns statement
**/
void check_queue(struct queue* q){
	if (queue_isempty(q) == 0){
		printf("The call has been successfully added to the queue!\n");
	}
	else
		printf("uh oh\n");
}

/** Function: add_caller
** Description: adds caller to queue
** Parameters: struct queue* q, int* id
** Pre-Conditions: queue must exists
** Post-Conditions: enques caller type
**/
void add_caller(struct callcenter* cc, int* id){
	struct call* call = malloc(sizeof(struct call));
	call->id = *id;
	printf("Enter caller's name: ");
	getchar();
	fgets(call->name, 256, stdin);
	printf("Enter call reason: ");
	fgets(call->reason, 1028, stdin);
	//inserts caller information into the queue
	queue_enqueue(cc->q, call);
	check_queue(cc->q);
}

/** Function: display_caller
** Description: display caller information
** Parameters: void* caller
** Pre-Conditions: takes generic pointer
** Post-Conditions: display caller information
**/
void display_caller(void* caller){
	struct call* call = caller;
	printf("Call ID: %d\n", call->id);
	printf("Caller's name: %s\n", call->name);
	printf("Call reason: %s\n", call->reason);
}   

/** Function: answer_call
** Description: answers call 
** Parameters: struct queue* q, struct stack* s
** Pre-Conditions: queue and stack must exist
** Post-Conditions: remove caller from queue and add to stack
**/
void answer_call(struct callcenter* cc){
	if (queue_isempty(cc->q) == 0){
		//gets the dequeued caller and rmeoves from queue
		void* caller = queue_dequeue(cc->q);
		//insert caller into the stack
		stack_push(cc->s, caller);
		printf("The following call has been answered and added to the stack\n");
		//display caler information
		display_caller(caller);
	}
	else 
		printf("No more calls need to be answered at the moment!\n");
	
}

/** Function: state_ofstack
** Description: displays the state of the stack
** Parameters: struct stack* s
** Pre-Conditions: stack must exist
** Post-Conditions: display top to stack
**/
void state_ofstack(struct callcenter* cc){
	printf("Number of calls answered: %d\n", stack_size(cc->s));
	if (stack_size(cc->s) > 0){
		//display caller information
		printf("Details of the last call: \n");
		display_caller(stack_top(cc->s));
	}
}

/** Function: state_ofqueue
** Description: displaysthe state of the queue
** Parameters: struct queue* q
** Pre-Conditions: queue must exist
** Post-Conditions: display front of queue
**/
void state_ofqueue(struct callcenter* cc){
	printf("number of calls to be answered: %d\n", queue_size(cc->q));
	if (queue_size(cc->q) > 0){
		//display caller infromation
		printf("Details of next call to be answered: \n");
		display_caller(queue_front(cc->q));
	}
}

/** Function: quit_callcenter
** Description: quit the callcenter
** Parameters: n/a
** Pre-Conditions: displays message
** Post-Conditions: return 1
**/
int quit_callcenter(){
	printf("Thank you for using our callcenter!\n");
	return 1;
}

/** Function: call_center
** Description: handles options that user give
** Parameters: struct queue* q, struct stack*s, int* id, int option, int* quit
** Pre-Conditions: user must pass in an option
** Post-Conditions: runs different functions
**/
void call_center(struct callcenter* cc, int* id, int option, int* quit){
	if (option == 1){
		add_caller(cc, id);
		*id = *id+=1; 
	}
	else if (option == 2){
		answer_call(cc);
	}
	else if (option == 3){
		state_ofstack(cc);
	}
	else if (option == 4){
		state_ofqueue(cc);
	}
	else if (option == 5){
		*quit = quit_callcenter();
	}
}
/**
** Function: callcenter_free
** Description: frees the queue and stack
** Parameters: struct queue* q, struct stack* s
** Pre-Conditions: queue and stack must exist
** Post-Conditions: free allocated memory
**/
void callcenter_free(struct callcenter* cc){
	//frees memory of call individual in stck and queue
	for(int i = 0; i < queue_size(cc->q); i++){
		free(queue_dequeue(cc->q));
	}
	for (int i = 0; i< stack_size(cc->s); i++){
		free(stack_pop(cc->s));
	}
	queue_free(cc->q);
	stack_free(cc->s);
	free(cc);
}



int main(int argc, char const *argv[]) {
	int id = 1, quitting = 0, option = 0;
	int* id_ptr = &id, *quit_ptr = &quitting;
	struct callcenter* cc = callcenter_create();

	do{
		display_callcenter();
		option = get_option();
		call_center(cc, id_ptr, option, quit_ptr);
	}while(quitting == 0);
	
	callcenter_free(cc);
	return 0;
}
