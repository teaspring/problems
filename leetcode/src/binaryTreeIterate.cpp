/*
 * in-order, post-order, and pre-order iterate without recurse
 * */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    // LVR
    vector<int> inOrderIterate(TreeNode* root) {
        vector<int> res;
        if(!root)    return res;

        stack<TreeNode*> stk;
        TreeNode *p = root;
        while(1) {
            while(p->left) {
                stk.push(p);
                p = p->left;
            }
            res.push_back(p->val);

            while(!(p->right)) {
                if(stk.empty())    return res;

                p = stk.top();
                stk.pop();
                res.push_back(p->val);
            }
            p = p->right;
        }
    }

    // LRV
    vector<int> postOrderIterate(TreeNode* root) {
        vector<int> res;
        if(!root)    return res;

        stack<TreeNode*> stk;
        TreeNode *p = root, *q = root;
        while(1) {
            while(p->left) {
                stk.push(p);
                p = p->left;
            }

            while(!(p->right) || p->right == q) {
                res.push_back(p->val);
                q = p;

                if(stk.empty())    return res;
                p = stk.top();
                stk.pop();
            }
            stk.push(p);
            p = p->right;
        }
    }
};
