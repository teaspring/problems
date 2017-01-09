/*
 * given a list, rotate the list to right by k places, where K >= 0
 *
 * open question:
 * if k > n, what will happen ?
 *
 * test case:
 * 1->2->3->4->5, k = 2, return 4->5->1->2->3
 * */
#include "../include/preliminary.h"

class Solution{
public:
    /*
     * walking a loop, it supports case of k > n
     * */
    ListNode* rotateRight(ListNode *head, int k){
        if(!head)    return NULL;

        ListNode *l1 = head;
        int n = 1;  // nodes count of SLL

        while(l1->next){
            l1 = l1->next;
            n++;
        }
        k %= n;
        if(k == 0)    return head;

        l1->next = head;  // make it loop

        int t = n - k;
        while(t-- > 0){
            l1 = l1->next;
        }

        head = l1->next; // new head
        l1->next = NULL;  // cut the loop

        return head;
    }
};

/* unit test is in ../cpp_unittest/rotateList_unittest */
