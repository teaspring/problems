/*
 * given a SLL: L0->L1->L2->l3...->Ln-1->Ln, reorder it to: L0->Ln->L1->Ln-1->L2...
 * do it in-place without altering nodes' values
 * */

#include "../include/preliminary.h"

class Solution{

public:
    void reorderSLL(ListNode *head){
        if(head == NULL)    return;

        ListNode *l2 = halveSLL(head);
        l2 = reverseSLL(l2);
        mergeSLL(head, l2);
    }

    /**
     * halve a SLL, return the head node of 2nd half
     * */
    ListNode* halveSLL(ListNode *head) {
        if(!head)    return NULL;

        ListNode *l1 = head, *l2 = head;  // eventually cut post to l1 node
        while(l2 && l2->next) {
            l2 = l2->next->next;
            if(l2)    l1 = l1->next;
        }

        ListNode *headOfHalf = l1->next;
        l1->next = NULL;
        return headOfHalf;
    }

    /*
     * reverse a SLL
     * */
    ListNode* reverseSLL(ListNode *head) {
        if(!head)    return NULL;

        ListNode *curr = head, *cprev = NULL, *cnext = curr->next;
        while(cnext) {
            curr->next = cprev;

            cprev = curr;
            curr = cnext;
            cnext = cnext->next;
        }

        curr->next = cprev;
        return curr;
    }

    /**
     * merge 2 SLL one node by another
     * */
    void mergeSLL(ListNode *l1, ListNode *l2){
        ListNode *p = l1, *q = NULL;  // moving in SLL l1 as p->q

        while(p){
            q = p->next;
            if(!l2)    break;
            ListNode *t = l2->next;

            p->next = l2;
            l2->next = q;

            p = q;
            l2 = t;
        }
    }
};

/* unit test is in ../cpp_unittest/reorderSLL_unittest */
