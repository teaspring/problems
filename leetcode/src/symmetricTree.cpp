/*
 * given a binary tree, check whether it is a mirror of itself(symmetric around its center)
 * e.g
 *        1
 *      /   \
 *     2     2
 *    / \   / \
 *    3 4   4 3    is true
 *
 * test case:
 * 1
 * 1 # 2
 * */

#include "../include/preliminary.h"

class Solution{

public:
    /*
     * compare nodes in every level, between [0] and [n-1], [1] and [n-2]...
     * */
    bool isSymmetric_01(TreeNode *root){
        if(!root)    return true;

        vector<TreeNode*> vecArr[2];

        int idx = 0;

        vecArr[idx].push_back(root);
    
        while(!vecArr[idx].empty()){

            const int n = vecArr[idx].size();

            bool l2r = (idx == 0);  // flag of scanning from left to right or opposite

            // next level push in positive order, curr level push in reverse order, and curr level pop in positive order
            int i = l2r ? 0 : n-1;

            for(; i < n && i >= 0; l2r ? ++i : --i){

                TreeNode *curr = vecArr[idx][i];
                TreeNode *oppo = vecArr[idx][n-1 - i];

                if(!curr && !oppo)    continue;

                if( !curr || ! oppo || (curr->val != oppo->val))    break;

                pushChildren(curr, vecArr[1-idx], l2r);
            }

            if(i >=0 && i < n)    return false;

            vecArr[idx].clear();

            idx = 1-idx;
        }

        return true;
    }

    /*
     * recurse, the easiest and most elegent solution of all
     * */
    bool isSymmetric_02(TreeNode *root){
        if(!root)    return true;

        return helper(root->left, root->right);
    }

    /*
     * compare a vector by inorder traverse with NULL node saved as well
     * */
    bool isSymmetric_03(TreeNode *root){
        if(!root)    return true;

        // src TreeNode saves int, to support NULL node, vector must save char instead
        vector<char> vec;

        inorderTraversal(root, vec);

        int i = 0, j = vec.size() - 1;

        while(i < j){
            if(vec[i] != vec[j])    return false;

            ++i;
            --j;
        }

        return true;
    }

private:
    /*
     * used by solution 01
     * @param l2r decides whether to save left prior to right or reversely
     * */
    void pushChildren(TreeNode *root, vector<TreeNode*>& vec, bool l2r){    // NULL is pushed as well to take place
        if(!root)    return;

        if(l2r)    vec.push_back(root->left);

        vec.push_back(root->right);

        if(!l2r)    vec.push_back(root->left);
    }

    /*
     * used by solution 02
     * */
    bool helper(TreeNode *pa, TreeNode *pb){
        if(!pa && !pb)    return true;

        if(!pa || !pb)    return false;

        if(pa->val != pb->val)    return false;

        return helper(pa->left, pb->right) && helper(pa->right, pb->left);  // NOTE: it is mirror symmetric
    }

    /*
     * used by solution 3
     * */
    void inorderTraversal(TreeNode *root, vector<char>& vec){
        if(!root){  // save dummy char for NULL node
            vec.push_back('#');
            return;
        }

        if(!root->left && !root->right){  // root is leaf
            vec.push_back('0' + root->val);
        }else{
            inorderTraversal(root->left, vec);  // inroder - LVR

            vec.push_back('0' + root->val);

            inorderTraversal(root->right, vec);
        }
    }
};

/* unit test is in ../cpp_unittest/symmetricTree_unittest */
