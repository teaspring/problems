/*
 * remove all elements from a SLL which has value val
 * 1->2->6->3->4->5->6, val=6  => 1->2->3->4->5
 * */
#include "../include/preliminary.h"

/*
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
*/

class Solution{
public:
    ListNode* removeSLLElements(ListNode *head, int x) {
        if(!head)    return NULL;

        ListNode *p = head, *pre = NULL;
        while(p) {
            ListNode *q = p->next;
            if(p->val == x) {
                p->next = NULL;
                if(head == p)    head = q;

                delete p;
                if(pre)    pre->next = q;
            } else {
                pre = p;
            }
            p = q;
        }
        return head;
    }

    // this is from discuss on oj.leetcode, it uses very few code line in payment of recurse. But it has no explicit 'delete' statements,
    // so it cannot be applied for C++ directly, otherwise, memory leak
    ListNode* removeElements(ListNode *head, int x) {
        if(!head)    return NULL;
        head->next = removeElements(head->next, x);
        return head->val == x ? head->next : head;
    }
};
