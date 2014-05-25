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

#include "stdio.h"
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

/*
 * solution 1, space O(n), time O(n)
 * */
void pushChildren(TreeNode *root, vector<TreeNode*>& vec, bool l2r){    // NULL is pushed as well to take place
    if(!root)    return;
    if(l2r){
        vec.push_back(root->left);
    }
    vec.push_back(root->right);
    if(!l2r){
        vec.push_back(root->left);
    }
    return;
}

bool isSymmetric_01(TreeNode *root){
    if(!root)    return true;
    vector<TreeNode*> vecArr[2];
    int idx = 0;
    vecArr[idx].push_back(root);
    
    while(!vecArr[idx].empty()){
        int n=vecArr[idx].size();
        bool l2r = (idx==0);
        int i = l2r ? 0 : n-1;   // next level push in positive order, curr level push in reverse order, and curr level pop in positive order
        for(; i < n && i >= 0; l2r ? ++i : --i){
            TreeNode *curr = vecArr[idx][i], *oppo = vecArr[idx][n-1-i];
            if(!curr && !oppo)    continue;
            if( !curr || ! oppo || (curr->val != oppo->val)){
                break; 
            }
            pushChildren(curr, vecArr[1-idx], l2r);
        }
        if(i >=0 && i<n)    return false;
        vecArr[idx].clear();
        idx = 1-idx;
    }
    return true;
}

/*
 * solution 2, elegant recurse !!!
 * */
bool helper(TreeNode *a, TreeNode *b){
    if(!a && !b)    return true;
    if(!a || !b)    return false;
    if(a->val != b->val)    return false;
    return helper(a->left, b->right) && helper(a->right, b->left);
}

bool isSymmetric_02(TreeNode *root){
    if(!root)    return true;
    return helper(root->left, root->right);
}

/*
 * solution 3, compare a vector by inorder traverse with NULL node saved as well
 * */
void inorderTraversal(TreeNode *root, vector<char>& vec){
    if(!root){
        vec.push_back('#');
        return;
    }
    if(!root->left && !root->right){
        vec.push_back('0' + root->val);
    }else{
        inorderTraversal(root->left, vec);
        vec.push_back('0' + root->val);
        inorderTraversal(root->right, vec);
    }
    return;
}

bool isSymmetric_03(TreeNode *root){
    if(!root)    return true;
    vector<char> vec;
    inorderTraversal(root, vec);

    int i=0, j=vec.size()-1;
    while(i<j){
        if(vec[i] != vec[j])    return false;
        ++i;
        --j;
    }
    return true;
}

/****** test ******/
void test_01(){
    TreeNode *node1 = new TreeNode(1);
    printf("%s\n", isSymmetric_03(node1) ? "true" : "false");
    return;
}

void test_02(){
    TreeNode *node1 = new TreeNode(1);
    node1->left = new TreeNode(2);
    printf("%s\n", isSymmetric_03(node1) ? "true" : "false");
    return;
}

int main(int, char**){
    test_01();
    test_02();
    return 0;
}
