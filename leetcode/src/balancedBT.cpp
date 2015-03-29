/*
 * given a binary tree, determine if it is height-balanced
 * concept: depth of the two subtrees of any nodes never differ more than 1
 * */
#include "../include/preliminary.h"


class Solution{
public:
    bool isBalanced(TreeNode *root){
        int d = 0;
        return balancedDepth(root, d);
    }

private:
    bool balancedDepth(TreeNode *root, int &depth){
        if(!root)    return true;

        int dl = 1, dr = 1;

        if(!balancedDepth(root->left, dl))    return false;

        if(!balancedDepth(root->right, dr))    return false;

        depth += max(dl, dr);
        return max(dl, dr) - min(dl, dr) <= 1;
    }
};
