/*
 * given a SLL, swap every two adjacent nodes and return its head
 * e.g. 1->2->3->4->5 => 2->1->4->3->5
 *
 * test case:
 * 1
 * 1->2
 * 1->2->3
 *
 * */
#include "../include/preliminary.h"

ListNode *swapPairs(ListNode *head){
    if(!head || !(head->next))    return head;
    ListNode *pre = 0, *l1 = head, *l2 = head->next, 
             *post = l2->next, *h=l2;
    while(1){
        if(pre)        pre->next = l2;        //swap
        l2->next = l1;
        l1->next = post;
        
        pre = l1;        //move forward
        l1 = post;
        if(!l1)        break;
        l2 = l1->next;
        if(!l2)        break;
        post = l2->next;
    }
    return h;
}

void test_01(){
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    displaySLL(swapPairs(l1));
}

void test_02(){
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    displaySLL(swapPairs(l1));
}

int main(int, char**){
    test_01();
    test_02();
    return 0;
}
