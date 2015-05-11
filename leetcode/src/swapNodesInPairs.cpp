/*
 * given a SLL, swap every two adjacent nodes and return its head
 * e.g. 1->2->3->4->5 => 2->1->4->3->5
 *
 * test case:
 * 1
 * 1->2
 * 1->2->3
 *
 * */
#include "../include/preliminary.h"

class Solution{

public:
    /*
     *
     * */
    ListNode *swapPairs(ListNode *head){
        if(!head || !(head->next))    return head;

        ListNode *pre = NULL, *l1 = head, *l2 = head->next;
        ListNode *post = l2->next, *h = l2;

        while(1){
            // swap -> l1 -> l2 -> to -> l2 -> l1 ->
            if(NULL != pre)    pre->next = l2;

            l2->next = l1;
            l1->next = post;
        
            pre = l1;  // move forward
            l1 = post;

            if(!l1)    break;
            l2 = l1->next;

            if(!l2)    break;
            post = l2->next;
        }

        return h;
    }
};

/* unit test is in ../cpp_unittest/swapNodesInPairs_unittest */
