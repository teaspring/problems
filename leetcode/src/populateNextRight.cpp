/*
 * assume each binary tree node has one another pointer to next right node. write a function to connect this pointer of each node in a binary tree.
 *
 * e.g. 
 *    1                 1 -> null
 *   / \              /   \
 *  2   3   ==>      2 ->  3 -> null
 * / \ / \          / \   / \
 *4  5 6  7        4 ->5->6->7 -> null
 * 
 *
 * solution: BFS, traverse every horizontal level once, using two queue to save traversed node. this solution has no dependence on the binary tree shape, either perfect BST or not does not matter.
 * */

#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

struct TreeLinkNode{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL){}
};

typedef TreeLinkNode* pTLN;

void pushChildren(TreeLinkNode* root, queue<TreeLinkNode*>& q){
    if(!root)    return;
    if(root->left){
        q.push(root->left);
    }
    if(root->right){
        q.push(root->right);
    }
    return;
}

void connect(TreeLinkNode *root){
    if(!root)    return;
    queue<TreeLinkNode*> qArr[2];
    int idx = 0;
    qArr[idx].push(root);
    while(!qArr[idx].empty()){
        for(TreeLinkNode *curr = qArr[idx].front(), *last = NULL;  // remember queue.front() is the oldest element, eqauls to removed by pop()
            !qArr[idx].empty();
            last = curr, curr = qArr[idx].front())
        {
            qArr[idx].pop();
            pushChildren(curr, qArr[1-idx]);
            if(last)    last->next = curr;
        }
        idx = 1-idx;
    }
    return;
}


int main(int, char**){
    return 0;
}

