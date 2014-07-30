/*
 * given two sorted SLL(assume in ascending order), merge them to one SLL (in ascending order)
 *
 */

#include "stdio.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

/**
 * Definition for singly-linked list node.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class mergeSortedLists {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL)    return l2;
        if(l2 == NULL)    return l1;
        ListNode *h = new ListNode(0);    // use prehead to avoid extra process of real head
        ListNode *l = h->next;
        while(l1 != NULL || l2 != NULL){
            if(l1 == NULL || (l2 != NULL && l1->val > l2->val)){
                l = l2;
                l2 = l2->next;
            }else{
                l = l1;
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


#endif /* MERGESORTEDLIST_H_ */
