/*
 * given a binary tree and a sum
 * I. determine if the tree has a root-to-leaf path such that adding up all the values of path equals the sum
 * II. find all root-to-leaf paths where each path's sum equals the given sum
 * */
#include "../include/preliminary.h"

class Solution{

public:
    /*
     * for problem I
     * */
    bool hasPathSum(TreeNode *root, int sum){
        if(!root)    return false;

        sum -= root->val;

        if(root->left == NULL && root->right == NULL && sum == 0)   return true;

        if(root->left != NULL  && hasPathSum(root->left, sum))     return true;

        if(root->right != NULL && hasPathSum(root->right, sum))    return true;

        return false;
    }

    /*
     * for problem II
     * */
    vector<vector<int> > pathSum(TreeNode *root, int sum){
        vector<vector<int> > res;
        if(!root)    return res;

        vector<int> vec;
        branchSum(res, vec, sum, root);

        return res;
    }

private:
    /*
     * used by pathSum()
     * */
    void branchSum(vector<vector<int> >& res, vector<int>& vec, int sum, TreeNode *par){
        if(!par)    return;

        vec.push_back(par->val);

        sum -= par->val;

        if(par->left != NULL){
            branchSum(res, vec, sum, par->left);
        }

        if(par->right != NULL){
            branchSum(res, vec, sum, par->right);
        }

        if(par->left == NULL && par->right == NULL && sum==0){
            res.push_back(vec);
        }

        vec.pop_back();
    }
};

/* unit test is in ../cpp_unittest/pathSum_unittest */
