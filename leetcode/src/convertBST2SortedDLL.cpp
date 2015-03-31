/*
 * convert a binary search tree (BST) to a sorted circular double linked list (DLL) in-place.
 * consider the left and right of BST node as synonymous to be prev and next of a DLL node
 *
 * all of the 3 solutions use recurse.
 * solution 1 and 2 are modifications based on in-order traverse. solution 3 uses divide-and-conquer
 * */
#include "stdio.h"
#include <iostream>

using namespace std;

struct node{
    int val;
    node* left;  // to be prev for DLL
    node* right; // to be next for DLL
    node(int v): val(v), left(NULL), right(NULL){}
    virtual ~node(){
        left = NULL;
        right = NULL;
    }
};

class Solution{

public:
    /*
     * solution 1
     * */
    node* BST2SortedDLL_01(node* root){
        node *head = NULL;
        node *tail = getTail(root, &head);
        if(!head || !tail){
            return NULL;
        }

        tail->right = head;
        head->left = tail;
        return head;
    }

    /*
    * solution 2, modification based on recursive in-order traverse as well.
    * */
    node* BST2SortedDLL_02(node* root){
        node *prev = NULL;
        node *head = NULL;
        bstToDLL(root, &prev, &head);
        return head;
    }

    /*
    * solution 3, via divide-and-conque, from cslibrary.stanford.edu/109/TreeListRecursion.html.
    * */
    node* BST2SortedDLL_03(node* root){
        if(!root)        return NULL;

        node *aList = BST2SortedDLL_03(root->left); // left subtree becomes circular
        node *bList = BST2SortedDLL_03(root->right); // right subtree becomes circular

        root->left = root;  // root becomes self-circular
        root->right = root;

        aList = append(aList, root);
        aList = append(aList, bList);
        return aList;
    }

private:
    /*
     * used by solution 1
     * @param ppPrev: pointing to prev of curr ?
     * @return: tail node of converted DLL
     * */
    node* getTail(node* curr, node** pPrev){
        if(!curr)   return NULL;

        node* tail = getTail(curr->left, pPrev);
        if(!tail){
            if( !(*pPrev) ){
                *pPrev = curr;    // to be head of whole sorted DLL
            }else{
                (*pPrev)->right = curr;
                curr->left = *pPrev;
            }
        }else{
            tail->right = curr;
            curr->left = tail;
        }

        tail = NULL;
        tail = getTail(curr->right, &curr);
        return !tail ? curr : tail;
    }

    /*
     * used by solution 2
     * */
    void bstToDLL(node *p, node **pPrev, node **pHead){
        if(!p)        return;

        bstToDLL(p->left, pPrev, pHead); // *pPrev will be prev of all left sub tree
        p->left = *pPrev; // link p and its predecessor(*pPrev)
        if(*pPrev)
            (*pPrev)->right = p;
        else
            *pHead = p; // head of whole sorted DLL

        node *right = p->right; // save right of p

        (*pHead)->left = p; // p becomes "tail" of left sub tree. this link between p and *pHead enables circular
        p->right = *pHead;

        *pPrev = p; // p is prev of next function call
        bstToDLL(right, pPrev, pHead);
    }

    /*
     * used by solution 3
     * */
    void join(node* a, node* b){ // join a and b and a becomes prev of b
        a->right = b;
        b->left = a;
    }

    /*
     * merge two circular to one, a becomes head of whole merged circular
     * */
    node* append(node* a, node* b){
        if(!a)    return b;
        if(!b)    return a;

        node *aLast = a->left;
        node *bLast = b->left;

        join(aLast, b); // aLast is prev of b
        join(bLast, a); // bLast is prev of a
        return a;
    }
};

/* unit test is in ../cpp_unittest/convertBST2SortedDLL_unittest */
