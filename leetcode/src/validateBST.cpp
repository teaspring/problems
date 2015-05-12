/*
 * given a binary tree, validate whether it is a binary search tree
 * NOTE: the idea beneath the solution is "bottom-up": when a subtree with root A is not BST, its parent with A as left/right child
 * will not be BST definitely
 * */

#include "../include/preliminary.h"

class Solution{

public:
    bool isValidBST(TreeNode *root){
        int ml = 0, mr = 0;
        return valid(root, ml, mr);
    }

private:
    /*
     * @param  lfoot: value of most left leaf
     * @param  rfoot: value of most right leaf
     * */
    bool valid(TreeNode *root, int &lfoot, int &rfoot){
        if(!root)    return true;

        if(!(root->left) && !(root->right)){
             lfoot = rfoot = root->val;
             return true;
        }

        int ll = root->val;  // default
        int lr = ll;

        if(NULL != root->left){
            if(!valid(root->left, ll, lr) || !(lr < root->val))    return false;
        }

        int rl = root->val;  // default
        int rr = rl;

        if(NULL != root->right){
            if(!valid(root->right, rl, rr) || !(rl > root->val))    return false;
        }

        lfoot = ll;
        rfoot = rr;

        return true;
    }
};

/* unit test is in ../cpp_unittest/validateBST_unittest */
