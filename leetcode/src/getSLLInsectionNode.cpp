/*
 * problem:
 * given two SLL, find the node at which the insection of two SLL begins
 * Req: time in O(n), and memory in O(1)
 * */

#include "../include/preliminary.h"

class Solution {
public:
    ListNode* getInsectionNode01(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)    return NULL;

        int lenA = lengthSLL(headA);
        int lenB = lengthSLL(headB);
        ListNode *pLong = NULL, *pShort = NULL;
        if(lenA > lenB) {
            pLong = headA;
            pShort = headB;
        } else {
            pLong = headB;
            pShort = headA;
        }

        int offset = abs(lenA - lenB);
        for (int i = 0; i < offset; i++) {
            pLong = pLong->next;
        }

        while(pLong && pShort) {
            if(pLong == pShort) {
                return pLong;
            }
            pLong = pLong->next;
            pShort = pShort->next;
        }
        return NULL;
    }

    /**
     * smart solution with mathematic idea
     * */
    ListNode* getInsectionNode02(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)    return NULL;

        ListNode *tailA = tailSLL(headA);
        tailA->next = headB;

        ListNode *l1 = headA, *l2 = headA; // move in l2 = 2X l1
        do {
            l1 = l1->next;
            if(!l2 || !(l2->next)) { // two SLL has no insection
                tailA->next = NULL;
                return NULL;
            }
            l2 = l2->next->next;
        } while(l1 != l2);

        l1 = headA;
        while(l1 != l2) {
            l1 = l1->next;
            l2 = l2->next;
        }

        tailA->next = NULL;
        return l1;
    }

private:
    int lengthSLL(ListNode* head) {
        ListNode *p = head;
        int l = 0;
        while(p) {
            l++;
            p = p->next;
        }
        return l;
    }

    ListNode* tailSLL(ListNode* head) {
        ListNode *p = head;
        while(p->next) {
            p = p->next;
        }
        return p;
    }
};
