/*
 * merge k sorted linked lists and return it as one sorted list. Analyze its complexity
 * */
#include "../include/preliminary.h"

using namespace std;

class Solution{
public:
    /*
     *
     * */
    ListNode* mergeKLists(vector<ListNode*>& lists){
        if(lists.empty())    return NULL;

        const int n = lists.size();
        int i = 0;
        while(i < n && lists[i] == NULL){
            i++;
        }

        if(i == n)    return NULL;

        ListNode *l1 = lists[i++];
        for(; i < n; i++){
            ListNode *l2 = lists[i];
            l1 = merge(l1, l2);
        }

        return l1;
    }

private:
    /*
     * l1 and l2 are heads of two sorted SLL
     * */
    ListNode* merge(ListNode *l1, ListNode *l2){
        ListNode *h = NULL, *head = NULL;

        if(!l1)    return l2;
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

        return head;
    }
};

/* unit test is in ../cpp_unittest/mergeKSortedList_unittest */
