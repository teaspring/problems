/*
 * given a binary and a sum
 * I. determine if the tree has a root-to-leaf path such that adding up all the values of path equals the sum
 * II. find all root-to-leaf paths where each path's sum equals the given sum
 * */
#include "../include/preliminary.h"

/*
 * I
 * */
bool hasPathSum(TreeNode *root, int sum){
    if(!root)    return false;
    if(root->left == NULL && root->right == NULL && sum == 0)   return true;
    sum -= root->val;
    if(root->left != NULL  && hasPathSum(root->left, sum))     return true;
    if(root->right != NULL && hasPathSum(root->right, sum))    return true;
    return false;
}

/*
 * II
 * */
void addStk(vector<vector<int> >& res, stack<int>& stk){
    stack<int> stk2;
    while(!stk.empty()){
        stk2.push(stk.top());
        stk.pop();
    }
    vector<int> vec;
    while(!stk2.empty()){
        stk.push(stk2.top());
        vec.push_back(stk.top());
        stk2.pop();
    }
    res.push_back(vec);
    return;
}

void branchSum(vector<vector<int> >& res, stack<int>& stk, int sum, TreeNode *par){
    if(!par)    return;
    stk.push(par->val);
    sum -= par->val;
    if(par->left != NULL){
        branchSum(res, stk, sum, par->left);
    }
    if(par->right != NULL){
        branchSum(res, stk, sum, par->right);
    }
    if(par->left == NULL && par->right == NULL && sum==0){
        addStk(res, stk);
    }
    stk.pop();
    return;
}

vector<vector<int> > pathSum(TreeNode *root, int sum){
    vector<vector<int> > res;
    if(!root)    return res;
    stack<int> stk;
    branchSum(res, stk, sum, root);
    return res;
}

int main(int, char**){
    return 0;
}
