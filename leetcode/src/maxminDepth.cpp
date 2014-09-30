/*
 * given a binary tree, find the maximum depth and minimum depth
 * */
#include "../include/preliminary.h"

class Solution{
public:
    int maxDepth(TreeNode *root){
        if(!root)    return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    int minDepth(TreeNode *root){
        if(!root)    return 0;
        int childmin = 0;
        if(!(root->left) && !(root->right)){
            childmin = 0;
        }else if(!(root->left)){
            childmin = minDepth(root->right);
        }else if(!(root->right)){
            childmin = minDepth(root->left);
        }else{
            childmin = min(minDepth(root->left), minDepth(root->right));
        }
        return 1 + childmin;
    }

};

int main(){
    return 0;
}
