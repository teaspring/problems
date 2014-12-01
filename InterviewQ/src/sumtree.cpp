/*
 * convert a BST to a sum tree, 
 * concept 1:
 *    1            27
 *   / \         /   \
 *  2   3    =>  9   13
 * / \ / \      / \ / \
 *4  5 6  7     0 0 0  0
 * 
 * concept 2:
 *    1           1
 *   / \         /  \
 *  2   3    =>  2   5
 * / \ / \      / \ / \
 *4  5 6  7    4  9 15 22 
 * */
#include "stdio.h"
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    void convert2SumTree_I(TreeNode *head){
        if(!head)    return;
        convertNode(head);
        return;
    }

    int convertNode(TreeNode *head){
        if(!head)    return 0;
        int tmp = head->val;
        TreeNode *pl = head->left, *pr = head->right;
        int sum = convertNode(pl) + convertNode(pr);
        if(pl)    sum += pl->val;
        if(pr)    sum += pr->val;
        head->val = sum;
        return tmp;
    }

    void convert2SumTree_II(TreeNode *head){
        if(!head)    return;
        vector<TreeNode*> arr[2];
        int ind = 0;
        arr[ind].push_back(head);
        while(!arr[ind].empty()){
            int n = arr[ind].size();
            int sum = 0;
            for(int i=0; i<n; ++i){
                TreeNode *curr = arr[ind][i];
                if(curr->left)     arr[1-ind].push_back(curr->left);
                if(curr->right)    arr[1-ind].push_back(curr->right);
                curr->val += sum;
                sum = curr->val;
            }
            arr[ind].clear();
            ind = 1-ind;
        }
        return;
    }
};
