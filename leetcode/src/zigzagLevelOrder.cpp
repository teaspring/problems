/*
 * given a binary tree,
 * 1. return zigzag level order traversal of its nodes' values.
 * (ie, firstly from left to right, then right to left for the next level and alternate between)
 * --->
 * <---
 * --->
 * <---
 *
 * 2. return level order traversal
 * --->
 * --->
 * --->
 * */

#include "stdio.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root){
        vector<vector<int> > res;
        if(!root)    return res;
        stack<TreeNode*> stks[2];   // key structure for zigzag level order
        bool isl2r = true;
        int i = 0;
        stks[i].push(root);
        while(!stks[i].empty()){
            vector<int> level;
            while(!stks[i].empty()){
                TreeNode* rt = stks[i].top();
                if(isl2r){
                    if(rt->left)     stks[1-i].push(rt->left);
                    if(rt->right)    stks[1-i].push(rt->right);
                }else{
                    if(rt->right)    stks[1-i].push(rt->right);        
                    if(rt->left)     stks[1-i].push(rt->left);
                }
                level.push_back(rt->val);
                stks[i].pop();
            }
            if(!level.empty())    res.push_back(level);
            isl2r = !isl2r;
            i = 1-i;
        }
        return res;
    }

    vector<vector<int> > levelOrder(TreeNode* root){
        vector<vector<int> >  res;
        if(!root)    return res;
        vector<TreeNode*>  arr[2];  // key structure for primary level order
        int i=0;
        arr[i].push_back(root);
        while(!arr[i].empty()){
            vector<int> level;
            int n = arr[i].size();
            for(int j=0; j<n; j++){
                TreeNode *curr = arr[i][j];
                if(curr->left)     arr[1-i].push_back(curr->left);
                if(curr->right)    arr[1-i].push_back(curr->right);
                level.push_back(curr->val);
            }
            res.push_back(level);
            arr[i].clear();
            i = 1-i;
        }
        return res;
    }

    void test_01(){
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(0);
        root->left->right = new TreeNode(4);
        root->right->left = new TreeNode(5);
        root->right->right = new TreeNode(7);
        root->right->left->left = new TreeNode(6);
        root->right->left->right = new TreeNode(10);
        root->right->right->left = new TreeNode(9);
        root->right->right->right = new TreeNode(8);
        vector<vector<int> > res1 = zigzagLevelOrder(root);
        displayVectorOfVector(res1);
        vector<vector<int> > res2 = levelOrder(root);
        displayVectorOfVector(res2);
    }

    void displayVector(vector<int>& vec){
        int n = vec.size();
        for(int i=0; i<n; i++){
            cout << vec[i] << " ";
        }
        cout << endl;
    }

    void displayVectorOfVector(vector<vector<int> >& matrix){
        for(int i=0; i < (int)matrix.size(); i++){
            displayVector(matrix[i]);
        }
    }
};

int main(){
    Solution s;
    s.test_01();
}
