/*
 * given a binary tree, flatten it to a linked list in-place.
 * e.g 
 *        1           1
 *      /   \          \
 *     2     5     =>   2
 *    / \     \          \
 *   3   4     6          3
 *                         \
 *                          4
 *                           \
 *                            5
 *                             \
 *                              6
 * */

#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

void flatten(TreeNode *root){
    if(!root)    return;
    TreeNode *curr = NULL, *last = NULL;
    stack<TreeNode*> stk;
    stk.push(root);
    while(!stk.empty()){
        curr = stk.top();
        stk.pop();
        if(curr->right)        stk.push(curr->right);
        if(curr->left)         stk.push(curr->left);
        if(last){
            last->right = curr;
            last->left = NULL;
        }
        last = curr;
    }
    return;
}

int main(int, char**){
    return 0;
}
