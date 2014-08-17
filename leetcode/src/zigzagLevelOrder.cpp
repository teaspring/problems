/*
 * given a binary tree, return the zigzag level order traversal of its nodes' values.
 * (ie, firstly from left to right, then right to left for the next level and alternate between)
 * */

#include "stdio.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}    
};

class Solution{
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root){
        vector<vector<int> > res;
        if(!root)    return res;
        stack<TreeNode*> stks[2];
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
        vector<vector<int> > res = zigzagLevelOrder(root);
        displayVectorOfVector(res);
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
