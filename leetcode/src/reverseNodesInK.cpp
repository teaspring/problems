/*
 * given a SLL, reverse the nodes of k at a time, return its modified head.if number less than k, remain them.
 *
 * e.g 1->2->3->4->5,
 * k = 2, return 2->1->4->3->5
 * k = 3, return 3->2->1->4->5
 *
 * for {1}, k = 2 return {1}
 *
 * */
#include "../include/preliminary.h"

class Solution{

public:
    /*
     *
     * */
    ListNode* reverseKGroups(ListNode *head, int k){
        if(!head || k < 2)    return head;

        ListNode *pre = NULL, *h = head, *post = NULL;

        head = NULL;

        while(h != NULL){
            ListNode *ln = h;

            int i = 1;
            for(; i < k && ln->next != NULL; ++i){
                ln = ln->next;
            }

            if(i < k)    break;  // remaining nodes is less than k

            post = ln->next;

            ListNode* nh = reverse(h, post);

            if(!pre){
                head = nh;
            }else{
                pre->next = nh;
            }

            pre = h;  // after reverse, h becomes exclusive prev of next partial SLL

            h = post; // inclusive head of next partial SLL
        }

        if(!head)    return h;  // whole length is less than k, nothing happened

        return head;
    }

private:
    /*
     * @param ListNode *h: inclusive head of this partial SLL
     *        ListNode *post: exclusive end of this partial SLL
     * @return: new head of reversed SLL
     * */
    ListNode* reverse(ListNode *h, ListNode *post){
        if(!h)    return NULL;

        ListNode *l1 = h, *l2 = h->next, *after = l2->next;

        while(l2 != post){  // once loop clause to process l2

            l2->next = l1;

            l1 = l2;

            l2 = after;

            if(!after)    break;

            after = l2->next;
        }

        h->next = post;

        return l1;
    }
};

/* unit test is in ../cpp_unittest/reverseNodesInK_unittest */
