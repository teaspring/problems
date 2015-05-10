/*
 * given a binary tree containing digits from 0-9. each root-to-leaf could represent a number.
 * an example is 1->2->3 which represents the number 123.
 * */

#include "../include/preliminary.h"

class Solution{

public:
    /*
     *
     * */
    int sumNumbers(TreeNode *root){
        if(!root)    return 0;

        stack<TreeNode*> stk;
        stk.push(root);

        int res = 0;

        stack<TreeNode*> snums;

        while(!stk.empty()){
            TreeNode *p = stk.top();
            stk.pop();

            while(!snums.empty()
                && snums.top()->left != p
                && snums.top()->right != p){

                snums.pop();
            }

            snums.push(p);

            if(!(p->left) && !(p->right)){  // reach leaf
                res += sumStackAsNumber(snums);
                snums.pop();
            }

            if(NULL != p->right)    stk.push(p->right);

            if(NULL != p->left)     stk.push(p->left);
        }

        return res;
    }

private:
    /*
     *
     * */
    int sumStackAsNumber(stack<TreeNode*>& stk){

        int sum = 0;
        stack<TreeNode*> stk2;
        int d = 1;

        while(!stk.empty()){
            stk2.push(stk.top());
            sum += d * stk.top()->val;
            stk.pop();

            d *= 10;
        }

        while(!stk2.empty()){
            stk.push(stk2.top());
            stk2.pop();
        }

        return sum;
    }
};

/* unit test is in ../cpp_unittest/sumroot2leaf_unittest */
