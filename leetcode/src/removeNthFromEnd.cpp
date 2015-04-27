/*
 * given a SLL, remove the Nth node from the end of list and return its head.
 *
 * test data:
 * 1->2->3->4->5, n=2, return head of SLL 1->2->3->5
 * 1, n=1,
 * 1->2, n=2
 * 1->2, n=1
 * */

#include "../include/preliminary.h"

class Solution{

public:
    /*
     * move p1 and p2 together where p2 of Nth back from p1
     * */
    ListNode* removeNthFromEnd(ListNode *head, int n){
        if(!head)    return NULL;

        ListNode *p1 = head; // p1 is the leading node
        for(int i = 1; i < n && p1 != NULL; i++){ // n > 1 so p1 and p2 cannot be same node
            p1 = p1->next;
        }

        if(!p1)    return NULL; // out of range

        ListNode *p2 = NULL, *prev = NULL;  // p2 is the Nth from p1, prev is pre of p2
        while(p1 != NULL){  // when p1 becomes NULL, p2 is the one to delete
            p1 = p1->next;
            prev = p2;
            p2 = ( !p2 ? head : p2->next);
        }

        if(prev != NULL){
            prev->next = p2->next;
        }else{ // prev is NULL, head is the one to delete
            head = p2->next;
        }

        p2->next = NULL;
        delete p2;

        return head;
    }
};

/* unit test is in ../cpp_unittest/removeNthFromEnd_unittest */
