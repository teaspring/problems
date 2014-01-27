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
#include "../header/preliminary.h"

/*
 * recurse hides too much detail, careful to understand
 * */
BinaryTree* sortedSLL2BST(ListNode* &list, int start, int end){
    if(start > end)    return 0;
    int mid = start + (end-start)/2;    //same to (start+end)/2, avoids overflow
    BinaryTree *leftChild = sortedSLL2BST(list, start, mid-1);
    BinaryTree *parent = new BinaryTree(list->val);    //once call create/insert one node
    parent->left = leftChild;
    list = list->next;                                 //once call moves one step
    parent->right = sortedSLL2BST(list, mid+1, end);
    return parent;
}

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
    BinaryTree *r = sortedSLL2BST(head, 0, 9);    //take note that 1st argument is ListNode *&, so it will be NULL when it returns 
    showPre(r);
    showIn(r);

    delSLL(p1);
    delBinaryTree(r);
    return 0;
}

