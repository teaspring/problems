/*
 * two elements of a BST are swapped by mistake. find them and recover the tree without changing the structure
 * use space O(1)
 * */
#include "../header/preliminary.h"

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

/*
 * idea: Morris inorder to traverse BST which output in ascending order. store the error node with its follower
 * */
void recoverTree(TreeNode *root){
    TreeNode *p = root, *tmp = NULL;
    TreeNode *pred = NULL, *pre1 = NULL, *cur1 = NULL, *pre2 = NULL, *cur2 = NULL;
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
                tmp->right = p;    // extra link up
                p = p->left;
            }else{
                pred = p;             // visit p
                tmp->right = NULL;    // release the extra link up
                p = p->right;
            }
        }


        if(pred && p && pred->val > p->val){  // in normal, pred should be greater then p
            if(!pre1){
                pre1 = pred;
                cur1 = p;
            }else{
                pre2 = pred;
                cur2 = p;
            }
            pred = NULL;
        }
    }

    if(pre1 && cur2){   // pre1 and cur2 in pair to swap
        swap(pre1->val, cur2->val);
    }else{    // now pre1 and cur1 in pair to swap
        swap(pre1->val, cur1->val);
    }
}

int main(){
    return 0;
}
