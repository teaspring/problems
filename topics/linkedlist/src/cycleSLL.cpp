/*
 * from oj.leetcode
 * problem 1: given a SLL, determine if it has a cycle in it
 * test data:
 * {}
 * {1}, no cycle
 * {1}, tail connect to head
 *
 * problem 2: given a SLL, if it has a cycle, find the start node of cycle 
 *
 * 
 * */
 #include "../header/preliminary.h"

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

bool hasCycle(ListNode *head){
    if(!head)    return false;
    ListNode *n1 = head, *n2 = head;
    while(n1 && n1->next){            //note that this loop is do-while{}
        n1 = n1->next->next;
        n2 = n2->next;
        if(n1 == n2)        return true;
    }
    return false;
}

ListNode* findCycleStart(ListNode *head){
    if(!head)        return NULL;
    ListNode *n1 = head, *n2=head;
    while(n1 && n1->next){
        n1 = n1->next->next;
        n2 = n2->next;
        if(n1 == n2)    break;
    }
    if(!n1 || !(n1->next))        return NULL;
    n1 = head;
    while(n1 != n2){
        n1 = n1->next;
        n2 = n2->next;
    }
    return n1;
}

int main(int, char**){
    return 0;
}
