/*
 * merge k sorted linked lists and return it as one sorted list. Analyze its complexity
 * */
#include "../include/preliminary.h"

using namespace std;

ListNode* merge(ListNode *l1, ListNode *l2, ListNode* &tail){
    ListNode *h=0, *head=0;
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
    tail = h;
    return head;
}

ListNode* mergeKLists(vector<ListNode*>& lists){
    int n = lists.size();
    if(n<1)    return NULL;
    int i=0;
    while(i<n && lists[i]==NULL){
        i++;
    }
    if(i==n)    return NULL;
    ListNode *l1 = lists[i++];
    for(;i<n;i++){
        ListNode *l2 = lists[i], *tail = 0;
        l1 = merge(l1, l2, tail);
    }
    return l1;
}

int main(int, char**){
    return 0;
}
