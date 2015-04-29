/*
 * given two sorted SLL(assume in ascending order), merge them to one SLL (in ascending order)
 */
#include "../include/preliminary.h"

class Solution{

public:
    ListNode* mergeList(ListNode *l1, ListNode *l2) {
        if(!l1)    return l2;
        if(!l2)    return l1;

        ListNode *h = new ListNode(0);    // use prehead to avoid extra process of real head
        ListNode *l = h;

        while(l1 != NULL || l2 != NULL){
            if(!l1 || (l2 != NULL && l1->val > l2->val)){
                l->next = l2;
                l2 = l2->next;
            }else{
                l->next = l1;
                l1 = l1->next;
            }

            l = l->next;
        }

        l = h->next;
        h->next = NULL;
        delete h;

        return l;
    }
};

/* unit test is in ../cpp_unittest/mergeSortedList_unittest */
