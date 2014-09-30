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
        return valid(root, mk, mr);
    }

    /*
     * @param  lfoot: most leaf leaf value
     * @param  rfoot: most right leaf value
     * */
    bool valid(TreeNode *root, int lfoot, int rfoot){
        if(!root)    return true;
        if(!(root->left) && !(root->right)){
             lfoot = rfoot = root->val;
        }
        if(root->left  && !(root->left->val < root->val))     return false;
        if(root->right && !(root->right->val > root->val))    return false;
        int ll = lr = root->val;    // default value of ll and lr if without left child
        int rl = rr = root->val;    // default value of rl and rr if without right child
        if(root->left){
            if(!valid(root->left, ll, lr) || !(lr < root->val))    return false;
        }
        if(root->right){
            if(!valid(root->right. rl, rr) || !(rl > root->val))    return false;
        }
        lfoot = ll;
        rfoot = rr;
        return true;
    }
};
