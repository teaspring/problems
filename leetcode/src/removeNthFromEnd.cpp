/*
 * given a SLL, remove the Nth node from the end of list and return its head.
 *
 * test data:
 * 1->2->3->4->5, n=2, after the removal, the SLL becomes 1->2->3->5
 * 1, 1,
 * 1->2, 2
 * 1->2, 1
 * */

#include "../include/preliminary.h"

ListNode* removeNth2End(ListNode *head, int n){
    if(!head)    return NULL;
    if(n==1){    //n==1 must be processed specially
        ListNode *pr = NULL, *l = head;
        while(l->next != NULL){
            pr = l;
            l = l->next;
        }
        if(pr)    pr->next = NULL;
        delete l;
        return !pr ? NULL : head;
    }

    ListNode *p1 = head;
    for(int i=1;i<n && p1 != NULL;i++){ //n>1 so p1 and p2 cannot be same node
        p1 = p1->next;
    }
    if(!p1)        return NULL;
    ListNode *p2 = head, *prev = NULL;
    while(p1->next != NULL){
        prev = p2;
        p2 = p2->next;    //p2 is Nth node ahead of p1
        p1 = p1->next;
    }
    ListNode *h = head;    //define another node pointer instead
    if(prev != NULL){
        prev->next = p2->next;
    }else{
        h = p2->next;
    }
    p2->next = NULL;
    delete p2;
    return h;
}

void test_01(){
    ListNode *p0 = new ListNode(0);
    ListNode *p1 = new ListNode(1);
    p0->next = p1;
    ListNode *p2 = new ListNode(2);
    p1->next = p2;
    displaySLL(p0);
    ListNode *h = removeNth2End(p0, 2);
    displaySLL(h);
    delSLL(h);
}

void test_02(){
    ListNode *p0 = new ListNode(0);
    ListNode *p1 = new ListNode(1);
    p0->next = p1;
    displaySLL(p0);
    ListNode *h = removeNth2End(p0, 1);
    displaySLL(h);
    delSLL(h);
}

void test_03(){
    ListNode *p0 = new ListNode(0);
    ListNode *p1 = new ListNode(1);
    p0->next = p1;
    displaySLL(p0);
    ListNode *h = removeNth2End(p0, 2);
    displaySLL(h);
    delSLL(h);
}

void test_04(){
    ListNode *p0 = new ListNode(0);
    displaySLL(p0);
    ListNode *h = removeNth2End(p0, 1);
    displaySLL(h);
    delSLL(h);
}

int main(int, char**){
    test_01();
    test_02();
    test_03();
    test_04();
    return 0;
}
