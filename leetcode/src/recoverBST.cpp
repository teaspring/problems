/*
 * two elements of a BST are swapped by mistake. find them and recover the tree without changing the structure
 * use space O(1)
 * */
#include "../include/preliminary.h"

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

/*
 * idea: Morris inorder to traverse BST in ascending order. store the swapped nodes
 * */
void recoverTree(TreeNode *root){
    TreeNode *p = root, *tmp = NULL, *pred = NULL;
    TreeNode *cur1 = NULL, *cur2 = NULL;  // two swapped nodes to recover
    while(p){
        if(p->left == NULL){
            pred = p;    // visit p
            p = p->right;
        }else{
            tmp = p->left;    // find the right most leaf of left half
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

        if(pred && p && pred->val > p->val){  // in normal, pred should be greater then p
            if(!cur1)    cur1 = pred;  // 1st swapped node
            cur2 = p;  // anyway, it must be the 2nd swapped node
            pred = NULL;  // defensive coding
        }
    }
    swap(cur1->val, cur2->val);
}

int main(){
    return 0;
}
