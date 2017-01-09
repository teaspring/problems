/*
 * from oj.leetcode. given a binary tree, find the maximum path sum. the path may start and end at any node in the tree;
 *
 * test case:
 * 1. root has child,  val may be negetive, positive, zero.
 * 2. root without child, if its val is negative, the result has to be it.
 * */
#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    int maxPathSum(TreeNode *root){
        int res = root->val;    // res must be initialized by root's val! for test case that negative root without child
        maxPath(root, &res);
        return res;
    }

private:
    /*
     * return: max sum of path which ends at *root
     * @param pSum: max sum of any path existing in the tree beneath *root
     * */
    int maxPath(TreeNode *root, int *pSum){
        if(!root)    return 0;

        int leftsum  = maxPath(root->left, pSum);
        int rightsum = maxPath(root->right, pSum);
        *pSum = max(*pSum, root->val + max(leftsum, 0) + max(rightsum, 0));

        int mx = max(leftsum, rightsum);
        return max(root->val + max(mx, 0), 0);
    }
};

