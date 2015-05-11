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

#include "../include/preliminary.h"

using namespace std;

class Solution{

public:
    /*
     *
     * */
    vector<vector<int> > zigzagLevelOrder(TreeNode* root){
        vector<vector<int> > res;
        if(!root)    return res;

        stack<TreeNode*> stks[2];   // structure for zigzag level order
        int now = 0;
        stks[now].push(root);

        bool isl2r = true;

        while(!stks[now].empty()){
            vector<int> level;

            while(!stks[now].empty()){
                TreeNode* rt = stks[now].top();

                if(isl2r){
                    if(rt->left)     stks[1-now].push(rt->left);
                    if(rt->right)    stks[1-now].push(rt->right);
                }else{
                    if(rt->right)    stks[1-now].push(rt->right);
                    if(rt->left)     stks[1-now].push(rt->left);
                }

                level.push_back(rt->val);

                stks[now].pop();
            }

            if(!level.empty())    res.push_back(level);

            isl2r = !isl2r;
            now = 1 - now;
        }
        return res;
    }

    /*
     *
     * */
    vector<vector<int> > levelOrder(TreeNode* root){
        vector<vector<int> >  res;
        if(!root)    return res;

        vector<TreeNode*>  arr[2];  // key structure for primary level order
        int now = 0;
        arr[now].push_back(root);

        while(!arr[now].empty()){

            vector<int> level;
            const int n = arr[now].size();

            for(int j = 0; j < n; j++){
                TreeNode *curr = arr[now][j];

                if(NULL != curr->left)     arr[1-now].push_back(curr->left);

                if(NULL != curr->right)    arr[1-now].push_back(curr->right);

                level.push_back(curr->val);
            }

            res.push_back(level);
            arr[now].clear();

            now = 1 - now;
        }

        return res;
    }
};

/* unit test is in ../cpp_unittest/zigzagLevelOrder_unittest */
