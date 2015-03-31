/*
 * given a SLL where elements are sorted in ascending order, convert it to a height balanced BST.
 *
 * note: different from convert a sorted array to ballanced BST, for SLL, element cannot be accessed in O(1) time.
 * 
 * recommended solution:
 * inserting nodes following list's order, in that way, no longer need to find the middle. time O(n), bottom-up
 * */
#include "../include/preliminary.h"

class Solution{
public:
    /*
     * recurse hides too much detail, careful to understand
     * */
    TreeNode* sortedSLL2BBST(ListNode* head){
        if(!head)    return NULL;

        int n = 0;   // length of SLL
        ListNode *h = head;
        while(h){
            n++;
            h = h->next;
        }
        h = head;

        return plug(&h, 0, n);
    }

    /*
     * convert an array where elements sorted in ascending order to a height balanced BST
     * */
    TreeNode *sortedArray2BBST(vector<int> &num){
        int n = num.size();
        if(n == 0)    return NULL;

        return plug(num, 0, n);
    }

private:
    /*
     * @param pHead: pointing to head of sub range
     * @param [start, end): range boundary
     * */
    TreeNode *plug(ListNode **pHead, int start, int end){
        if(start >= end)    return NULL;

        int mid = start + (end - start) / 2;
        TreeNode *lChild = plug(pHead, start, mid); // after all the inner recurses return, pHead has moved to middle

        TreeNode *curr = new TreeNode((*pHead)->val);
        curr->left = lChild;

        *pHead = (*pHead)->next;  // moves one node forward
        curr->right = plug(pHead, mid + 1, end);
        return curr;
    }

    /*
     * convert sorted array [start, end) to a balanced BST
     * */
    TreeNode *plug(vector<int> &num, int start, int end){
        if(start >= end)    return NULL;

        int mid = start + (end - start)/2;
        TreeNode *root = new TreeNode(num[mid]);

        root->left  = plug(num, start, mid);
        root->right = plug(num, mid + 1, end);
        return root;
    }
};
/* unit test is in ../cpp_unittest/convertSortedSLL2BBST */
