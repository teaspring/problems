/*
 * implement an iterator over a binary search tree(BST). the iterator will be initialized with root node
 * design some data structure to implement below methods:
 * next() will return the next smallest number in the BST.
 * hasNext() tells whether we have a next smallest
 *
 * both methods should be in time O(1) and in memory O(h), where h is the height of the BST
 * */
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * basically, it is based on in-order iterate
 * */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        curr = NULL;
        if(!root)    return;

        TreeNode *p = root;
        while(p->left) {
            stk.push(p);
            p = p->left;
        }
        stk.push(p);  // remember to push p to stack
    }

    bool hasNext() {
        return !stk.empty() || (curr && curr->right);  // don't forget case of NULL root
    }

    int next() {
        if (!curr) {
            curr = stk.top();
            stk.pop();
            return curr->val;
        }

        if (!(curr->right)) {
            curr = stk.top();
            stk.pop();
            return curr->val;
        } else {
            curr = curr->right;
            while(curr->left) {
                stk.push(curr);
                curr = curr->left;
            }
            return curr->val;
        }
    }

private:
    stack<TreeNode*> stk;
    TreeNode* curr;  // last iterated node
};

/**
 * this BSTIterator will be called like:
 * BSTIterator i = BSTIterator(root);
 * while(i.hasNext())    cout << i.next();
 * */
