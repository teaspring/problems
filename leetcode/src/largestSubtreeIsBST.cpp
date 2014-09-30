/*
 * given a binary tree, find the largest subtree which is BST. Note, a subtree all of its descendants.
 * Idea: 'bottom-up' solution. when subtree with node A is validated not BST, and node above A with A as child will not be BST definitely
 * NOTE: recurse method calling is 'top-down' from root to child with no doubt. "bottom-up" means denying child as BST will deny parent immediately
 * */
#include "../include/preliminary.h"

class Solution{
public:
    /*
     * @param p: in, current node to handle
     * @return : node count of largest subtree with root of p
     * @param min, inout: minimum value of subtree with root of p
     *        max, inout: maximum ...
     *        maxNodes, inout: global largest subtree node count
     *        largestBST, inout: root of global largest subtree
     * */
    int findLargestBSTSubtree(TreeNode *p, int &min, int &max,
                int &maxNodes, TreeNode* &largestBST){
        if(!p)    return 0;
        bool isBST = true;
        int leftNodes = findLargestBSTSubtree(p->left, min, max, maxNodes, largestBST);
        int currMin = (leftNodes == 0) ? p->val : min;
        if(leftNodes == -1 ||
           (leftNodes != 0 && p->val <= min)){
            isBST = false;
        }
        int rightNodes = findLargestBSTSubtree(p->right, min, max, maxNodes, largestBST);
        int currMax = (rightNodes == 0) ? p->val : max;
        if(rightNodes == -1 ||
           (rightNodes != 0 && p->val >= min)){
            isBST = false;
        }
        if(isBST){
            min = currMin;
            max = currMax;
            int totalNodes = leftNodes + rightNodes + 1;
            if(totalNodes > maxNodes){
                maxNodes = totalNodes;
                largestBST = p;
            }
            return totalNodes;
        }else{
            return -1;   // this subtree with root of p is not BST
        }
    }

    TreeNode *findLargestBSTSubtree(TreeNode *root){
        TreeNode *largestBST = NULL;
        int min = 0, max = 0;
        int maxNodes = 0;
        findLargestBSTSubtree(root, min, max, maxNodes, largestBST);
        return largestBST;
    }
};

void test_01(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);
    Solution s;
    TreeNode *p = s.findLargestBSTSubtree(root);
    showPre(p);
    showIn(p);
}

int main(){
    test_01();
    return 0;
}
