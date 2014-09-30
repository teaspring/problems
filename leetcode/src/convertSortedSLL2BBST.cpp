/*
 * from leetcode. given a SLL where elements are sorted in ascending order, convert it to a height balanced BST.
 *
 * note:different from convert a sorted array to ballanced BST, for single linked list, element cannot be accessed in O(1) time.
 * ----naive solution: 
 *  in each recurse, traverse half of the list's length to find middle element. time complexity: every
 *  recurse fixes one element, inside recurse, search for middle is O(lgn), in total time O(nlgn) ?
 * the disadvantage is in every recurse, the prehalf is traversed with nothing to do. this is a top-down method
 * ----best solution: 
 * inserting nodes following list's order, in that way, no longer need to find the middle. total time is O(n), this is a bottom-up method.
 * 
 * */
#include "../include/preliminary.h"

class Solution{
public:
    /*
     * recurse hides too much detail, careful to understand
     * */
    TreeNode* sortedSLL2BST(ListNode* head){
        if(!head)    return NULL;
        int n = 0;   // nodes count of SLL
        ListNode *h = head;
        while(h){
            n++;
            h = h->next;
        }
        h = head;
        return plug(h, 0, n);
    }

    /*
     * convert an array where elements sorted in ascending order to a height balanced BST
     * */
    TreeNode *sortedArray2BST(vector<int> &num){
        int n = num.size();
        if(n == 0)    return NULL;
        return plug(num, 0, n);
    }

private:
    /*
     * @param head: SLL head node which will be updated accordingly
     * @param start: inclusive index
     * @param end: exclusive index
     * */
    TreeNode *plug(ListNode* &head, int start, int end){
        if(start >= end)    return 0;
        int mid = start + (end-start)/2;    //same to (start+end)/2, avoids overflow
        TreeNode *lChild = plug(head, start, mid);
        TreeNode *curr = new TreeNode(head->val);    //once call create/insert one node
        curr->left = lChild;
        head = head->next;                                 //once call moves one step
        curr->right = plug(head, mid+1, end);
        return curr;
    }

    /*
     * facilitary method to convert sorted array to balanced BST
     * @param end: exclusive index
     * */
    TreeNode *plug(vector<int> &num, int start, int end){
        if(start >= end)    return NULL;
        int mid = start + (end - start)/2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left  = plug(num, start, mid);
        root->right = plug(num, mid+1, end);
        return root;
    }
};

int main(int, char**){
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    p1->next = p2;
    ListNode *p3 = new ListNode(3);
    p2->next = p3;
    ListNode *p4 = new ListNode(4);
    p3->next = p4;
    ListNode *p5 = new ListNode(5);
    p4->next = p5;
    ListNode *p6 = new ListNode(6);
    p5->next = p6;
    ListNode *p7 = new ListNode(7);
    p6->next = p7;
    ListNode *p8 = new ListNode(8);
    p7->next = p8;
    ListNode *p9 = new ListNode(9);
    p8->next = p9;
    ListNode *p10 = new ListNode(10);
    p9->next = p10;
    displaySLL(p1);
    ListNode *head = p1;
    Solution s;
    TreeNode *r = s.sortedSLL2BST(head);    //take note that 1st argument is ListNode *&, so it will be NULL when it returns
    showPre(r);
    showIn(r);

    int A[] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> num(A, A + sizeof(A)/sizeof(int));
    displayVector(num);
    TreeNode *q = s.sortedArray2BST(num);
    showPre(q);
    showIn(q);

    delSLL(p1);
    delTree(r);
    delTree(q);
    return 0;
}
