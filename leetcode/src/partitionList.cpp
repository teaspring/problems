/*
 * given a linked list and a value, partition it such that all nodes less than x come before nodes greater than or equal to x
 * you should preserve the original relative order of the nodes in each of the two partition
 * given  1->4->3->2->5->2 and x = 3
 * return 1->2->2->4->3->5
 * */
#include "../header/preliminary.h"

ListNode* partition(ListNode *head, int x){
    if(!head || !(head->next))    return head;
    ListNode *curr = head, *post = head->next, *r = 0, *s = head, *toDel = 0;
    for(; post; curr = post, post = curr->next){
        if(curr->val < x  && post->val < x)     continue;
        if(curr->val >= x && post->val >= x)    continue;
        if(curr->val < x  && post->val >= x){ //position between r and s is the place to insert node less than x
            r = curr;
            s = post;
        }else{  // curr->val >= x and post < x, post is the node to insert ahead        
            toDel = post;
            post = post->next;
            curr->next = post;
            toDel->next = 0;
            if(r){
                r->next = toDel;
            }else{
                head = toDel;
            }
            toDel->next = s;
            r = toDel;
            toDel = 0;
        }
    }
    return head;
}

