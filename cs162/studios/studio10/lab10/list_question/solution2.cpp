#include <iostream>

#include "list.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *temp = head;

    ListNode *prev = NULL;
    if (temp != NULL && temp->val == n){
        head = temp->next; 
        delete temp;
        return head;
    }

    else{
        while (temp != NULL && temp->val != n){
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL){
            return head;
        }
        prev->next = temp->next;
        delete temp;
    }
    return head;
}
