/*
 * given a binary tree, find the largest BST.
 * Note: the result BST may not be balanced; and it may or may not include all of its descendants
 * idea of this solution looks like "top-down". if root p's value breaks BST(compare with min and max), it cannot contribute
 * to parent as subtree. it has to consider as an independent subtree.
 * */

#include "../header/preliminary.h"

class Solution{
public:
    /*
     * since result BST may or may not include all of its descendants, we need to create copy of nodes dynamically.
     * but the release operation is not involved here.
     * @param p: in,
     *        min: in
     *        max: in
     *        maxNodes: inout
     *        largestBST: out,
     *        child: out
     * */
    int findLargestBST(TreeNode *p, int min, int max, int &maxNodes,
                TreeNode* &largestBST, TreeNode* &child){
        if(!p)    return 0;
        if(!(min < p->val) || !(max > p->val)){ // p's value breaks BST definition
            findLargestBST(p, INT_MIN, INT_MAX, maxNodes, largestBST, child);  // consider p an independent subtree
            return 0;   // return 0 means p cannot contribute to parent as subtree of BST
        }

        int totalNodes = 1;
        int leftNodes = findLargestBST(p->left, min, p->val, maxNodes, largestBST, child);
        TreeNode *leftChild = NULL;
        if(leftNodes > 0){
            leftChild = child;
            totalNodes += leftNodes;
        }
        int rightNodes = findLargestBST(p->right, p->val, max, maxNodes, largestBST, child);
        TreeNode *rightChild = NULL;
        if(rightNodes > 0){
            rightChild = child;
            totalNodes += rightNodes;
        }

        TreeNode *curr = new TreeNode(p->val);  // create copy to update child
        curr->left = leftChild;
        curr->right = rightChild;
        child = curr;    // pass curr as child to above tree

        if(maxNodes < totalNodes){  // update maxNodes and largestBST
            maxNodes = totalNodes;
            largestBST = curr;
        }
        return totalNodes;
    }

    TreeNode* findLargestBST(TreeNode* root){
        TreeNode* largestBST= NULL, *child = NULL;
        int maxNodes = INT_MIN;
        findLargestBST(root, INT_MIN, INT_MAX, maxNodes, largestBST, child);
        return largestBST;
    }
};

void test_01(){
    TreeNode *root = new TreeNode(15);
    root->right = new TreeNode(20);
    root->left = new TreeNode(10);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(7);
    root->left->right->left = new TreeNode(2);
    root->left->right->right = new TreeNode(5);
    root->left->right->left->left = new TreeNode(0);
    root->left->right->left->right = new TreeNode(8);
    root->left->right->right->left = new TreeNode(3);
    Solution s;
    TreeNode *p = s.findLargestBST(root);
    showPre(p);
    showIn(p);
}

int main(){
    test_01();
    return 0;
}
