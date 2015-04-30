/*
 * remove duplicates in a SLL
 *
 * 1->1->2->2->2->3     1->2->3
 * */

#include "../include/preliminary.h"

class Solution{

public:
    /*
     * problem I: for duplicate nodes, remove them other than one
     * input:  1->1->2
     * output: 1->2
     * */
    ListNode* remove(ListNode *head){
        if(!head)    return NULL;

        ListNode *pre = NULL, *curr = head;
        while(curr && curr->next){
            ListNode *post = curr->next;

            if(curr->val == post->val){ // if curr == post, remove curr
                if(!pre){
                    head = post;
                }else{
                    pre->next = post;
                }
                curr->next = NULL;
                delete curr;
            }else{
                pre = curr;
            }

            curr = post;
        }
        return head;
    }

    /*
     * problem II: given a sorted SLL, remove all the nodes with duplicates
     * input:  1->1->2
     * output: 2
     * */
    ListNode* removeII_1(ListNode *head){
        if(!head || !(head->next))    return head; // empty or only one node

        ListNode *pre = NULL, *curr = head->next;
        ListNode *start = head, *end = NULL;

        while(1){
            if(end && (!curr || curr->val != end->val)){ // duplicates nodes range is found
                if(!pre){
                    head = curr;
                }else{
                    pre->next = end->next;
                }

                end->next = NULL;  // cut a separate SLL of start to end, and delete them
                delPart(start);

                start = curr;
                end = NULL;
            }else if(curr){
                if(curr->val != start->val){ // duplicates nodes range has not appeared yet
                    pre = (!pre) ? start : pre->next;
                    start = start->next;
                }else{ // duplicates nodes range exists
                    end = curr;
                }
            }

            if(!curr)    break;
            curr = curr->next;
        }
        return head;
    }

    ListNode* removeII_2(ListNode *head){
        if(!head || !(head->next))    return head;

        ListNode *pre = NULL, *curr = head;
        ListNode *start = NULL, *end = NULL;

        while(curr){
            ListNode *post = curr->next;
            end = curr;

            if(!post || end->val != post->val){
                if(start){ // duplicates nodes range is found [start, end]
                    if(!pre){
                        head = post;
                    }else{
                        pre->next = post;
                    }
                    end->next = NULL;

                    delPart(start);
                    start = NULL;
                }else{  // duplicates nodes range has not appeared yet
                    pre = curr;
                }
            }else{  // duplicates nodes range exists
                if(!start)    start = end;
            }

            curr = post;
        }
        return head;
    }

private:
    void delPart(ListNode *start){
        for(ListNode *h = start; NULL != h;){
            ListNode *after = h->next;
            delete h;
            h = after;
        }
    }
};

/* unit test is in ../cpp_unittest/removeDuplicatesSLL_unittest */
