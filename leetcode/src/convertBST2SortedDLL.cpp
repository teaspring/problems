/*
 * from leetcode. convert a BST to a sorted circular DLL in-place. think of the left and right pointers as synonymous to the 
 * previous and next pointers in a DLL
 * all of the 3 solutions here use recursion.solution 1 and 2 are modifications based on in-order traverse. solution 3 uses divide-and-conquer
 * */
#include "stdio.h"
#include <iostream>

using namespace std;

struct node{
    int val;
    node* left;        //to be prev for DLL
    node* right;    //to be next for DLL
    node(int v):val(v),left(0),right(0){}
    virtual ~node(){
        left = 0;
        right = 0;
    }
};

void outputDLL(node* pEnd, int asc){        //asc = 1 for ascending from head, and 0 for descending from tail
    if(pEnd==0)    return;
    node *curr = pEnd;
    printf("the sorted DLL in ascending are: ");
    printf("%d", curr->val);
    curr = asc ? curr->right : curr->left;
    while(curr != pEnd){
        printf(" -> %d", curr->val);
        curr = asc ? curr->right : curr->left;
    }
    printf("\n");
    return;
}

/*
 * implementation of my own
 * */
node* getTail(node* curr, node*& pPrev){
    if(curr==0)        return 0;
    node* tmp = getTail(curr->left, pPrev);
    if(tmp==0){
        if(pPrev==0){
            pPrev = curr;    //head of sorted DLL
        }else{
            pPrev->right = curr;
            curr->left = pPrev;
        }
    }else{
        tmp->right = curr;
        curr->left = tmp;
    }

    tmp = getTail(curr->right, curr);
    return tmp==0 ? curr : tmp;
}

node* BST2SortedDLL_01(node* root){
    node *head = 0, *tail = 0;
    tail = getTail(root, head);
    if(head==0 || tail==0){
        return 0;
    }
    tail->right = head;
    head->left = tail;
    return head;
}

/*
 * author's implementation. modification based on recursive in-order traverse as well.
 * */
void bstToDLL(node *p, node*& prev, node*& head){
    if(!p)        return;
    bstToDLL(p->left, prev, head);
    p->left = prev;        //link p and its predecessor(prev)
    if(prev)
      prev->right = p;
    else
      head = p;

    node *right = p->right;     //head stays as the real "head" of DLL, it linked to p in every statement call. as a result, it is linked to 
    head->left = p;             //real "tail" in final function call
    p->right = head;

    prev = p;        //p as the prev of next function call
    bstToDLL(right, prev, head);
}

node* BST2SortedDLL_02(node* root){
    node *prev = 0;
    node *head = 0;
    bstToDLL(root, prev, head);
    return head;
}

/*
 * solution with idea of divide-and-conque, from cslibrary.stanford.edu/109/TreeListRecursion.html.
 * */
void join(node* a, node* b){    //link a to b as predecessor of b
    a->right = b;
    b->left = a;
}

node* append(node* a, node* b){//convert alast->a,blast->b to alast->b, blast->a 
    if(a==0)    return b;
    if(b==0)    return a;
    node *aLast = a->left;
    node *bLast = b->left;
    join(aLast, b);
    join(bLast, a);
    return a;
}

node* BST2SortedDLL_03(node* root){
    if(root==0)        return 0;
    node *aList = BST2SortedDLL_03(root->left);
    node *bList = BST2SortedDLL_03(root->right);
    root->left = root;        //unlink root to append to left half, and append right half to left half seperately 
    root->right = root;
    aList = append(aList, root);
    aList = append(aList, bList);
    return aList;
}

/*
 * test
 * */
int main(int, char**){
    node *p4 = new node(4);
    node *p6 = new node(6);
    p4->right = p6;
    node *p5 = new node(5);
    p6->left = p5;
    node *p7 = new node(7);
    p6->right = p7;
    node *p2 = new node(2);
    p4->left = p2;
    node *p1 = new node(1);
    p2->left = p1;
    node *p3 = new node(3);
    p2->right = p3;
    
    node* h = BST2SortedDLL_03(p4);
    outputDLL(h, 1);
    outputDLL(h, 0);

    delete p4;
    delete p5;
    delete p2;
    delete p1;
    delete p3;
    return 0;
}
