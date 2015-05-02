/*
 * from oj.leetcode. given a binary tree, find the maximum path sum. the path may start and end at any node in the tree;
 *
 * test case:
 * 1. root has child,  val may be negetive, positive, zero.
 * 2. root without child, if its val is negative, the result has to be itself.
 * */
#include "../include/preliminary.h"

class Solution{

public:
    int maxPathSum_01(TreeNode *root){
        int res = root->val;    //res must be initialized by root's val!!! for test case that negative root without child
        maxPath(root, &res);
        return res;
    }

    int maxPathSum_02(TreeNode *root){
        if(!root)    return 0;

        int res = root->val;
        DFS(root, res);
        return res;
    }

private:
    /*
     * my own solution, DFS actually
     * */
    int maxPath(TreeNode *par, int *pSum){
        if(!par)    return 0;

        int leftsum  = maxPath(par->left, pSum);
        int rightsum = maxPath(par->right, pSum);

        int mx = max(leftsum, rightsum);    //it is key of efficiency to conclude the process of left/right to max/min 
        int mn = min(leftsum, rightsum);

        if(mx <= 0){     //both mx/min can not contribute to max path sum beneath *par 
            if(par->val > *pSum){
                *pSum = par->val;
            }
            return par->val > 0 ? par->val : 0;
        }else if(mn > 0){ //both mx/mn can contribute to max path sum beneath *par, but only mx contributes the one above *par
            if(par->val + mx + mn > *pSum){
                *pSum = par->val + mx + mn;
            }
            return (par->val + mx) > 0 ? (par->val + mx) : 0;
        }else{
            if(par->val + mx > *pSum){
                *pSum = par->val + mx;
            }
            return (par->val + mx) > 0 ? (par->val + mx) : 0;
        }
    }


    /*
     * from internet, Geek style. Implement same idea with much less and simple code
     * */
    int DFS(TreeNode *root, int &ret){
        if(!root)    return 0;

        int maxl = DFS(root->left, ret);
        int maxr = DFS(root->right, ret);

        ret = max(ret, root->val + max(0, maxl) + max(0, maxr));    //elegent code, worth to follow
        return max(0, root->val + max(0, max(maxl, maxr)));
    }
};

/* unit test is in ../cpp_unittest/maxPathSum_unittest */
