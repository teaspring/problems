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
     * once scan, and it does not handle case of k < n
     * */
    ListNode* rotateRight_01(ListNode *head, int k){
        if(!head)    return NULL;

        ListNode *l1 = head, *l2 = NULL;

        for(int i = 1; i < k && NULL != l1; i++){  // start from head, walk k-1 steps
            l1 = l1->next;
        }

        if(!l1)    return head;  // whole SLL has less than k nodes

        ListNode *pre1 = l1;  // prev node of l1
        l1 = l1->next;  // now l2 is k nodes ahead of l1

        ListNode *pre2 = NULL;  // prev node of l2
        l2 = head;   // now l2 is k nodes ahead of l1

        while(NULL != l1){ // move all 4 nodes by one step
            pre1 = l1;
            l1 = l1->next;

            pre2 = !pre2 ? head : l2;
            l2 = l2->next;
        }

        if(!pre2)    return head; // NOTE: pre2 == NULL tells while-clause has not accessed yet, it means k == n !

        pre2->next = NULL;  // new tail

        pre1->next = head;

        return l2;
    }

    /*
     * walking a loop, it supports case of k > n
     * */
    ListNode* rotateRight_02(ListNode *head, int k){
        if(!head)    return NULL;

        ListNode *l1 = head;
        int n = 1;  // nodes count of SLL

        while(NULL != l1->next){
            l1 = l1->next;
            n++;
        }

        if(n == k)    return head;

        l1->next = head;  // make it loop

        int t = abs(n - k);  // rest steps to walk

        while(t-- > 0){
            l1 = l1->next;
        }

        head = l1->next; // new head
        l1->next = NULL;  // cut the loop

        return head;
    }
};

/* unit test is in ../cpp_unittest/rotateList_unittest */
