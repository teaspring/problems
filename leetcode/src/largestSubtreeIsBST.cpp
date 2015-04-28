/*
 * given a binary tree, find the largest subtree which is BST. Note, a subtree has all of its descendants.
 *
 * Idea: 'bottom-up' solution.
 * if subtree with root A is not BST, any above nodes with A as its child cannot be BST
 *
 * NOTE:
 * recurse method calling is 'top-down' from root to child
 * "bottom-up" means denying child as BST will deny parent immediately
 * */
#include "../include/preliminary.h"

class Solution{

public:
    TreeNode *findLargestBSTSubtree(TreeNode *root){
        TreeNode *largestBST = NULL;
        int currMin = INT_MAX;  // invalid minimum
        int currMax = INT_MIN;  // invalid maximum
        int maxNodes = 0;

        findLargestBSTSubtree(root, currMin, currMax, maxNodes, &largestBST);
        return largestBST;
    }

private:
    /*
     * key is check root with min/max of its left subtree, and min/max of its right subtree
     *
     * @param p: in, current node to handle
     *
     * @return n: > 0  means count of largest subtree with root of p
     *            = -1 means it breaks the BST definition
     *            = 0  means it has no child
     *
     * @param min, inout: minimum value of subtree with root of p
     *        max, inout: maximum ~
     *        maxNodes, inout: global largest subtree node count
     *        pLargestBST, inout: root of global largest subtree
     * */
    int findLargestBSTSubtree(TreeNode *p, int &currMin, int &currMax, int &maxNodes, TreeNode **pLargestBST){
        if(!p)    return 0;

        int lSubMin = INT_MAX;  // invalid minimum
        int lSubMax = INT_MIN;  // invalid maximum
        int leftNodes = findLargestBSTSubtree(p->left, lSubMin, lSubMax, maxNodes, pLargestBST);

        int rSubMin = INT_MAX;
        int rSubMax = INT_MIN;
        int rightNodes = findLargestBSTSubtree(p->right, rSubMin, rSubMax, maxNodes, pLargestBST);

        bool isBST = true;

        if(leftNodes == -1 ||
            (leftNodes > 0 && !(p->val > lSubMax))){
                isBST = false;  // p and its left subtree breaks BST definition
        }

        if(rightNodes == -1 ||
            (rightNodes > 0 && !(p->val < rSubMin))){
                isBST = false;  // p and its right subtree breaks BST definition
        }

        if(!isBST)    return -1; // subtree beneath p is invalid BST, contributing nothing to above

        currMin = min(p->val, lSubMin);  // update currMin with min in left subtree
        currMax = max(p->val, rSubMax);  // update currMax with max in right subtree

        int totalNodes = 1 + leftNodes + rightNodes;
        if(totalNodes > maxNodes){
            maxNodes = totalNodes;
            *pLargestBST = p;
        }

        return totalNodes;
    }
};

/* unit test is in ../cpp_unittest/largestSubtreeIsBST_unittest */
