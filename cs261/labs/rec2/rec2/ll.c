#include <stdlib.h>

#include "ll.h"
#include <stdio.h>
#include <stdlib.h>

// struct node
// {
// 	int val;
// 	struct node *next;
// };


struct node* add_two_num (struct node* l1, struct node* l2)
{
	struct node* current1 = l1;
	struct node* current2 = l2;
	struct node* l3 = NULL;
	int bool = 0;
	int sum = 0;
	int val1 = 0;
	int val2 = 0;

	
	while(current1 != NULL || current2 != NULL){
		struct node* current3 = l3;
	
		//checks to see if one part of list is longer or shorter than other list
		if (current1 != NULL)
			val1 = current1->val;
		else 
			val1 = 0;
		if(current2 != NULL)
			val2 = current2->val;
		else 
			val2 = 0;
		
		//checks to see if a number has been carried over
		if (bool == 1){
			bool = 0;
			sum++;
		}

		//gives me sum
		if (val1 + val2 >= 10){
			bool = 1;
			sum += (val1 + val2) - 10;
		}
		else {
			sum += val1 + val2;
		}	
		
		//if the list is empty
		if (l3==NULL){
			struct node* current3 = malloc(sizeof(struct node));
			current3->val = sum;
			current3->next = l3;
			l3 = current3;
		}
		//else for the rest of the list
		while(current3 != NULL){
			if(current3->next == NULL){
				current3->next = malloc(sizeof(struct node));
				current3 = current3->next;
				current3->next = NULL;
				current3->val = sum;
			}
			current3 = current3->next;
		}
		//if the list ends earlier than the other one we do not continue the shorter list
		if (current1 != NULL)
			current1 = current1->next;
		if (current2  != NULL)
			current2 = current2->next; 
		sum = 0;
	}
	return l3;
	

}


