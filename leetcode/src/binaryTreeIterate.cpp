/*
 * in-order, post-order, and pre-order iterate without recurse
 *
 * Points:
 * 1. we want L firstly. so the falling down along L side in every time recurse is necessary
 * 2. when visited, p is V of itself certainly, but as L or R of its parent depends the precedence
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
            while(p->left) {  // until the one without L child
                stk.push(p);
                p = p->left;
            }
            res.push_back(p->val); // as V

            while(!(p->right)) { // if no R child
                if(stk.empty())    return res;

                p = stk.top();  // so the new node is parent of visited p, of which the visited p as L child
                stk.pop();
                res.push_back(p->val); // visited as V
            }

            p = p->right;
        }
    }

    // LRV
    // we want L firstly. after falling down along the left side, p is either V or L of its parent.
    // for LRV, the own val of p cannot be retrieved immediately.
    vector<int> postOrderIterate(TreeNode* root) {
        vector<int> res;
        if(!root)    return res;

        stack<TreeNode*> stk;
        TreeNode *p = root, *q = NULL;
        while(1) {
            while(p->left) {  // until the one without L child
                stk.push(p);
                p = p->left;
            }

            while(!(p->right)   // if no R child
                  || p->right == q) {  // if R child is visited already
                res.push_back(p->val);  // visited as V
                q = p;

                if(stk.empty())    return res;
                p = stk.top();
                stk.pop();
            }

            stk.push(p);  // R child is not visited yet, p node has to be saved now

            p = p->right;
        }
    }
};
