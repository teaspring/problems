/*
 * from oj.leetcode. given a binary tree, find the maximum path sum. the path may start and end at any node in the tree;
 *
 * test case:
 * 1. root has child,  val may be negetive, positive, zero.
 * 2. root without child, if its val is negative, the result has to be it.
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

int maxPath(TreeNode *par, int *pSum){
    if(!par)    return 0;
    int leftsum  = maxPath(par->left, pSum);
    int rightsum = maxPath(par->right, pSum);
    int mx = max(leftsum, rightsum);    //it is key of efficiency to conclude the process of left/right to max/min 
    int mn = min(leftsum, rightsum);

    *pSum = max(par->val + max(mx,0) + max(mn,0), *pSum);
    return max(par->val + max(mx,0), 0);
}

int maxPathSum(TreeNode *root){
    int res = root->val;    //res must be initialized by root's val!!! for test case that negative root without child
    maxPath(root, &res);
    return res;
}

int main(int, char**){
    TreeNode *p0 = new TreeNode(3);
    TreeNode *p1 = new TreeNode(-2);
    p0->left = p1;
    TreeNode *p2 = new TreeNode(0);
    p0->right = p2;
    TreeNode *p3 = new TreeNode(3);
    p1->left = p3;
    TreeNode *p4 = new TreeNode(4);
    p1->right = p4;
    TreeNode *p5 = new TreeNode(-1);
    p2->left = p5;
    TreeNode *p6 = new TreeNode(2);
    p2->right = p6;
    TreeNode *p7 = new TreeNode(4);
    p5->right = p7;

    printf("the max path sum is %d\n", maxPathSum(p0));
    return 0;
}
