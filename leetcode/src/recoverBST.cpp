/*
 * two elements of a BST are swapped by mistake. find them and recover the tree without changing the structure
 * use space O(1)
 * */
#include "../include/preliminary.h"

class Solution{

public:
    /*
     * idea: Morris inorder to traverse BST in ascending order. store the swapped nodes
     * */
    void recoverTree(TreeNode *root){
        TreeNode *p = root;  // cursor for Morris-Inorder iteration
        TreeNode *pred = NULL; // prev of p in in-order iteration path
        TreeNode *cur1 = NULL, *cur2 = NULL;  // two mistaken nodes to recover

        while(NULL != p){
            if(p->left == NULL){
                pred = p;    // visit p
                p = p->right;
            }else{
                TreeNode *tmp = p->left;    // find the right most leaf of left half
                while(tmp->right != NULL
                    && tmp->right != p){
                    tmp = tmp->right;
                }

                if(tmp->right == NULL){
                    tmp->right = p;  // extra link up
                    p = p->left;
                }else{
                    pred = p;       // visit p
                    tmp->right = NULL;  // release the extra link up
                    p = p->right;
                }
            }

            /*
             * the mistaken two nodes on in-order path will have two cases:
             * 1.one following the other(below clause will be enterd just once), like 1 - '3' - '2' - 4
             * 2.not continuous (below clause will be enterer twice), like 1 - '4' - 3 - '2' - 5
             *
             * for 1st case, cur1 is '3'(pred) and cur2 is '2'(p)
             * for 2nd case, cur1 is '4'(pred for 1st time), cur2 is assigned twice which is '2'(p) after 2nd time assignment
             * */
            if(pred && p && pred->val > p->val){  // if no mistake, pred should be always less than p
                if(!cur1)    cur1 = pred;  // 1st swapped node
                cur2 = p;
                pred = NULL;  // may be useless but defensive coding
            }
        }

        swap(cur1->val, cur2->val); // must achieve it via swap value of nodes
    }

private:
    void swap(int &a, int &b){
        int tmp = a;
        a = b;
        b = tmp;
    }
};

/* unit test is in ../cpp_unittest/recoverBST_unittest */
