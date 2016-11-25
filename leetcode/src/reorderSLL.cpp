/*
 * problem:
 * given a SLL: L0->L1->L2->l3...->Ln-1->Ln, reorder it to: L0->Ln->L1->Ln-1->L2...
 * do it in-place without altering nodes' values
 *
 * additional:
 * how to recover such reorder operation?
 * */

#include "../include/preliminary.h"

class Solution{

public:
    void reorderSLL(ListNode *head) {
        if(!head)    return;

        ListNode *l2 = halveSLL(head);
        l2 = reverseSLL(l2);
        mergeSLL(head, l2);
    }

    /**
     * recover the reorder operation
     * */
    void recoverReorderSLL(ListNode *head) {
        if(!head)    return;

        ListNode *l2 = splitOddEvenSLL(head);
        l2 = reverseSLL(l2);
        appendSLL(head, l2);
    }

    /**
     * halve a SLL, return the head node of 2nd half
     * */
    ListNode* halveSLL(ListNode *head) {
        if(!head)    return NULL;

        ListNode *p = head, *q = head;  // eventually cut after p
        while(q && q->next) {
            q = q->next->next;
            if(q)    p = p->next;
        }

        ListNode *headOfHalf = p->next;
        p->next = NULL;
        return headOfHalf;
    }

    /*
     * reverse a SLL
     * */
    ListNode* reverseSLL(ListNode *head) {
        if(!head)    return NULL;

        ListNode *q = head, *p = NULL; // p is previous of q
        while(q) {
            ListNode *t = q->next;
            q->next = p;

            p = q;
            q = t;
        }
        return p;
    }

    /**
     * merge 2 SLL one node by another; l1 is the head of new merged SLL
     * */
    void mergeSLL(ListNode *l1, ListNode *l2){
        ListNode *p = l1;

        while(p){
            ListNode *q = p->next;
            if(!l2)    break;
            ListNode *t = l2->next;

            p->next = l2;
            l2->next = q;

            p = q;
            l2 = t;
        }
    }

    /**
     * split the SLL with odds and evens
     * return head of evens SLL
     * */
    ListNode* splitOddEvenSLL(ListNode *head) {
        if(!head || !(head->next))    return NULL;

        ListNode *p = head;
        ListNode *newHead = NULL;
        ListNode *q = NULL;

        while(p && p->next) {
            ListNode *t = p->next;
            p->next = t->next;
            p = p->next;
            t->next = NULL;  // t becomes isolated node

            if(!q) {
                newHead = t;
                q = newHead;
            } else {
                q->next = t;
                q = q->next;
            }
        }
        return newHead;
    }

    /**
     * append SLL l2 to tail of SLL l1
     * */
    void appendSLL(ListNode *l1, ListNode *l2) {
        ListNode *p = l1;
        while(p->next) {
            p = p->next;
        }
        p->next = l2;
        return;
    }
};

/* unit test is in ../cpp_unittest/reorderSLL_unittest */
