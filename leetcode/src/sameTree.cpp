/*
 * givena two binary trees, write a function to check it they are equal or not. The concept "equal" means they are structually
 * identical and the nodes have the same value.
 * */
#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

bool isSameTree(TreeNode *p, TreeNode *q){
    if(!p && !q)            return true;
    if(!p || !q)            return false;
    if(p->val != q->val)    return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

void test_01(){
    TreeNode *node1 = new TreeNode(1);
    node1->right = new TreeNode(2);

    TreeNode *node2 = new TreeNode(1);
    node2->right = new TreeNode(2);

    printf("%s\n", isSameTree(node1, node2) ? "true" : "false");
}

int main(int, char**){
    test_01();
    return 0;
}
