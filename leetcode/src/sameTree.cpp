/*
 * givena two binary trees, write a function to check it they are equal or not. The concept "equal" means they are structually
 * identical and the nodes have the same value.
 * */
#include "../include/preliminary.h"

class Solution{

public:
    /*
     * easy recurs
     * */
    bool isSameTree(TreeNode *p, TreeNode *q){
        if(!p && !q)            return true;

        if(!p || !q)            return false;

        if(p->val != q->val)    return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

/* unit test is in ../cpp_unittest/sameTree_unittest */
