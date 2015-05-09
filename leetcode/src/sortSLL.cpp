/*
 * sort a single linked list.
 * to sort SLL, merge and insertion are two better options. this solution is  merge sort
 * */
#include "../include/preliminary.h"  // struct ListNode

class Solution{

public:
    /*
     * sort in ascending order, both valid head and tail have to return after sort
     * */
    ListNode* mergesort(ListNode *head){
        int n = 0;
        ListNode *h = head;

        while(h){
            h = h->next;
            ++n;
        }

        ListNode *h1 = NULL, *h2 = NULL, *tail = NULL;

        for(int len = 1; len < n;len *= 2){
            ListNode *prev = NULL;
            h = head;

            while(h != NULL){
                h1 = h;
                h2 = ruler(h1, len);
                h = ruler(h2, len);
                h1 = merge(h1, h2, tail);

                if(prev != NULL){
                    prev->next = h1;
                }else{
                    head = h1;
                }

                if(tail != NULL)    tail->next = h;

                prev = tail;
                tail = NULL;
            }
        }

        return head;
    }


private:
    /*
     *
     * */
    ListNode* ruler(ListNode *head, int len){
        if(!head)    return NULL;

        --len;  // if we want to return head->next, len should be reduced separately

        while(head->next != NULL && len>0){
            head = head->next;
            --len;
        }

        ListNode *res = head->next;
        head->next = NULL;  // cut the SLL in ruler of length len

        return res;
    }

    /*
     *
     * */
    ListNode* merge(ListNode *l1, ListNode *l2, ListNode* &tail){
        ListNode *h = NULL, *head = NULL;

        if(!l1)    return l2;    //immediately return without traverse, tail remains 0
        if(!l2)    return l1;

        if(l1->val < l2->val){
            h = head = l1;
            l1 = l1->next;
        }else{
            h = head = l2;
            l2 = l2->next;
        }

        while(l1 || l2){
            if(!l2 || (l1 && l1->val < l2->val)){
                h->next = l1;
                l1 = l1->next;
            }else{
                h->next = l2;
                l2 = l2->next;
            }

            h = h->next;
        }

        tail = h;

        return head;
    }
};

/* unit test is in ../cpp_unittest/sortSLL_unittest */
