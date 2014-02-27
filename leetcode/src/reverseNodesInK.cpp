/*
 * given a SLL, reverse the nodes of k at a time, return its modified head.if number less than k, remain them.
 * e.g 1->2->3->4->5,
 * k=2, 2->1->4->3->5
 * k=3, 3->2->1->4->5
 * {1}, k=2 => return {1}
 * */
#include "../header/preliminary.h"

void reverse(ListNode *pre, ListNode *h, ListNode *e, ListNode *post){ //pre->h->...->e->post => pre->e->...->h->post
    if(!h)    return;
    ListNode *l1 = h, *l2 = h->next, *after = l2->next;
    while(l2 != post){  //l1->l2->after => l1<-l2  after
        l2->next = l1;
        if(!after)        break;
        l1 = l2;    //move one step forward
        l2 = after;
        after = l2->next;
    }
    if(pre)        pre->next = e;
    h->next = post;
    return;
}

ListNode *reverseKGroups(ListNode *head, int k){
    if(!head || k<2)    return head;
    ListNode *pre=0, *h = head, *post=0;
    head = NULL;
    while(h != NULL){
        ListNode *e = h;
        int i = 0;
        for(i=1;i<k && e->next != NULL;++i){
            e = e->next;
        }
        if(i<k)        break;    //less than k nodes
        post = e->next;
        reverse(pre, h, e, post);
        if(!head)    head = e;    

        pre = h;    //after reverse, h becomes prev of post
        h = post;
    }
    if(!head)    return h;
    return head;
}

void test_01(){
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    l1->next = l2;
    ListNode *l3 = new ListNode(3);
    l2->next = l3;
    ListNode *l4 = new ListNode(4);
    l3->next = l4;
    ListNode *l5 = new ListNode(5);
    l4->next = l5;

    displaySLL(reverseKGroups(l1, 2));
}

void test_02(){
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    l1->next = l2;
    ListNode *l3 = new ListNode(3);
    l2->next = l3;
    ListNode *l4 = new ListNode(4);
    l3->next = l4;
    ListNode *l5 = new ListNode(5);
    l4->next = l5;

    displaySLL(reverseKGroups(l1, 3));
}

int main(int, char**){
    test_01();
    test_02();
    return 0;
}
