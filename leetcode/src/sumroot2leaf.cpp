/*
 * given a binary tree containing digits from 0-9. each root-to-leaf could represent a number.
 * an example is 1->2->3 which represents the number 123.
 * */

#include "../header/preliminary.h"

int sumStackAsNumber(stack<TreeNode*>& stk){
    int sum=0;
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

int sumNumbers(TreeNode *root){
    if(root==NULL)    return 0;
    stack<TreeNode*> stk;
    stk.push(root);
    int res=0;
    stack<TreeNode*> snums;
    while(!stk.empty()){
        TreeNode *p = stk.top();
        stk.pop();
        while(!snums.empty() && snums.top()->left != p && snums.top()->right != p){
            snums.pop();
        }
        snums.push(p);
        if(p->left == NULL && p->right == NULL){    //reach leaf
            res += sumStackAsNumber(snums);
            snums.pop();
        }
        if(p->right != NULL)    stk.push(p->right);
        if(p->left != NULL)     stk.push(p->left);
    }
    return res;
}

void test_01(){
    TreeNode *p0 = new TreeNode(1);
    TreeNode *p1 = new TreeNode(2);
    TreeNode *p2 = new TreeNode(3);
    p0->left = p1;
    p0->right = p2;
    printf("%d\n ", sumNumbers(p0));
}

void test_02(){
    TreeNode *p0 = new TreeNode(1);
    TreeNode *p1 = new TreeNode(2);
    TreeNode *p2 = new TreeNode(3);
    p0->left = p1;
    p0->right = p2;
    TreeNode *p3 = new TreeNode(1);
    p1->left = p3;
    TreeNode *p4 = new TreeNode(0);
    p1->right = p4;
    TreeNode *p5 = new TreeNode(4);
    p2->left = p5;
    TreeNode *p6 = new TreeNode(5);
    p2->right = p6;
    printf("%d\n ", sumNumbers(p0));
}

int main(int, char**){
    test_02();
    return 0;
}
