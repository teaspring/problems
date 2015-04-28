/*
 * given a binary tree, find the largest BST.
 * Note: the result BST may not be balanced; and it may or may not include all of its descendants
 *
 * idea of this solution looks like "top-down". if root p's value breaks BST(compare with min and max),
 * it cannot contribute to parent as subtree. it has to be considered as an independent subtree.
 * */
#include "../include/preliminary.h"

class Solution{

public:
    TreeNode* findLargestBST(TreeNode* root){
        TreeNode *largestBST= NULL, *child = NULL;
        int maxNodes = INT_MIN;

        findLargestBST(root, INT_MIN, INT_MAX, maxNodes, &largestBST, &child);
        return largestBST;
    }

private:
    /*
     * since result BST may or may not include all of its descendants, we need to create copy of nodes dynamically.
     * but the release operation is not involved here.
     *
     * @param p: in,
     *        min: in
     *        max: in
     *        maxNodes: inout
     *        largestBST: out,
     *        child: out  # very important, it is passed to above to tree as child
     * @return: total nodes in valid BST with root of p
     * */
    int findLargestBST(TreeNode *p, int min, int max, int &maxNodes,
                TreeNode **pLargestBST, TreeNode **pChild){
        if(!p)    return 0;

        if(!(min < p->val && p->val < max)){ // p's value breaks BST definition
            findLargestBST(p, INT_MIN, INT_MAX, maxNodes, pLargestBST, pChild);  // consider p an independent subtree
            return 0;   // return 0 means p cannot contribute to parent as subtree of BST
        }

        TreeNode *curr = new TreeNode(p->val);  // create copy to update child
        int totalNodes = 1; // p is countable

        int leftNodes = findLargestBST(p->left, min, p->val, maxNodes, pLargestBST, pChild);
        if(leftNodes > 0){
            curr->left = *pChild;
            totalNodes += leftNodes;
        }

        int rightNodes = findLargestBST(p->right, p->val, max, maxNodes, pLargestBST, pChild);
        if(rightNodes > 0){
            curr->right = *pChild;
            totalNodes += rightNodes;
        }

        if(maxNodes < totalNodes){  // update maxNodes and largestBST
            maxNodes = totalNodes;
            *pLargestBST = curr;
        }

        *pChild = curr; // this is purpose of @param child: it can be passed to above tree as child
        return totalNodes;
    }
};

/* unit test is in ../cpp_unittest/largestBSTInBT_unittest */
