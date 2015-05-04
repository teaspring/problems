/*
 * given a SLL: L0->L1->L2->l3...->Ln-1->Ln, reorder it to: L0->Ln->L1->Ln-1->L2...
 * do it in-place without altering nodes' values
 * */

#include "../include/preliminary.h"

class Solution{

public:
    /*
     *
     * */
    void reorderSLL(ListNode *head){
        if(head == NULL)    return;

        ListNode *l1 = head, *l2 = head;

        while(l2 && l2->next){ // good idea: use slow & quick walker to find the middle node
            l1 = l1->next;

            l2 = l2->next;
            if(l2->next)    l2 = l2->next;
        }

        if(l1 == l2)    return;  // length is 1 or 2

        l2 = l1->next;

        l1->next = NULL;

        l2 = reverseSLL(l2);

        // now we have two SLL *head and *l2, merge them by inserting one by one
        ListNode *curr = head;

        l1 = curr->next;

        while(l2 && curr){  // curr is result of last l1
            curr->next = l2;
            curr = l2;

            if(l2)    l2 = l2->next;  // take care of the node move in order

            curr->next = l1;  // l1 is possible to be NULL

            curr = l1;

            if(l1)    l1 = l1->next;
        }
    }

    /*
     * reverse a SLL, solid implementation
     * */
    ListNode* reverseSLL(ListNode *head){
        if(!head)    return NULL;

        ListNode *curr = head, *cprev = NULL, *cnext = curr->next;

        while(cnext){
            curr->next = cprev;
            cprev = curr;

            curr = cnext;
            cnext = cnext->next;
        }

        curr->next = cprev;
        return curr;
    }
};

/* unit test is in ../cpp_unittest/reorderSLL_unittest */
