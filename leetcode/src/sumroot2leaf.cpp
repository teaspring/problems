/*
 * given a binary tree containing digits from 0-9. each root-to-leaf could represent a number.
 * an example is 1->2->3 which represents the number 123.
 *
 * both BFS and DFS can solve this problem
 * */

#include "../include/preliminary.h"

class Solution{

public:
    /*
     * BFS, with one more stack<> for traverse
     * */
    int sumNumbers_01(TreeNode *root){
        if(!root)    return 0;

        stack<TreeNode*> stk; // used for BFS traverse
        stk.push(root);

        int res = 0;

        vector<TreeNode*> snums; // path for root to leaf

        while(!stk.empty()){
            TreeNode *p = stk.top();
            stk.pop();

            // pop elements rom snums to keep its tail remains parent of p
            while(!snums.empty()
                && snums[snums.size() - 1]->left != p
                && snums[snums.size() - 1]->right != p){

                snums.pop_back();
            }

            snums.push_back(p);

            if(!(p->left) && !(p->right)){  // p is leaf
                res += sumList(snums);
                snums.pop_back();
            }

            // push right firstly then pop left first
            if(NULL != p->right)    stk.push(p->right);
            if(NULL != p->left)     stk.push(p->left);
        }

        return res;
    }

    /*
     * DFS, its logic is more complex than BFS
     * */
    int sumNumbers_02(TreeNode *root){
        if(!root)    return 0;

        int res = 0;

        vector<TreeNode*> path;
        path.push_back(root);

        TreeNode *p = root, *last = NULL;

        while(!path.empty()){
            p = path[path.size() - 1];

            if(last == p->right){  // left and right child of p have been traversed, skip p
                last = p;
                path.pop_back();
                continue;
            }

            if(last != p->left){
                while(NULL != p->left){ // traverse along the left child
                    p = p->left;
                    path.push_back(p);
                }
            }

            if(!(p->left) && !(p->right)){  // p is leaf, sum current path
                res += sumList(path);
                path.pop_back();
            }else if(NULL != p->right){  // right sub tree of p has not been traversed yet, push it
                path.push_back(p->right);
            }else{  // p has no right child, skip p
                path.pop_back();
            }

            last = p;
        }

        return res;
    }

private:
    /*
     * present the vector 1->2->3 as integer 123
     * */
    int sumList(const vector<TreeNode*>& path){
        int sum = 0;
        const int n = path.size();

        for(int i = 0; i < n; i++){
            sum  = sum * 10 + path[i]->val;
        }

        return sum;
    }
};

/* unit test is in ../cpp_unittest/sumroot2leaf_unittest */
