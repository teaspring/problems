/*
 * given a linked list and a value, partition it such that all nodes less than x come before nodes greater than or equal to x
 * you should preserve the original relative order of the nodes in each of the two partition
 * given  1->4->3->2->5->2 and x = 3
 * return 1->2->2->4->3->5
 * */
#include "../include/preliminary.h"

class Solution{

public:
    /*
     * this operation reminds once scan during quick sort. but swap in SLL is more complex than elements
     * */
    ListNode* partition(ListNode *head, int x){
        if(!head || !(head->next))    return head;

        ListNode *curr = head, *post = head->next;
        ListNode *r = NULL, *s = head;

        for(; NULL != post; curr = post, post = post->next){
            if(curr->val < x  && post->val < x)     continue;

            if(curr->val >= x && post->val >= x)    continue;

            if(curr->val < x  && post->val >= x){  // between r and s is where to insert node less than x
                r = curr;
                s = post;
                continue;
            }else{  // curr >= x && post < x, post is the one to insert ahead
                ListNode *it = post;

                curr->next = post->next; // post-next is a new element which has not been verified yet
                post = curr;

                it->next = NULL;

                if(!r){
                    head = it;
                }else{
                    r->next = it;
                }

                it->next = s;
                r = it;

                it = NULL;
            }
        }

        return head;
    }
};

/* unit test is in ../cpp_unittest/partitionList_unittest */
