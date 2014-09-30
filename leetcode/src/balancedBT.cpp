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

    bool balancedDepth(TreeNode *root, int &depth){
        if(!root)    return true;
        int dl = 0, dr = 0;
        bool isleft = balancedDepth(root->left, dl);
        if(!isleft)    return false;
        bool isright = balancedDepth(root->right, dr);
        if(!isright)    return false;
        return max(dl, dr) - min(dl, dr) <= 1;
    }
};

int main(){
    return 0;
}

