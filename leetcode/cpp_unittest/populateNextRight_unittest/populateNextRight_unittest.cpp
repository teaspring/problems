#include "populateNextRight.cpp"
#include "gtest/gtest.h"

/*
 * void connect(TreeLinkNode *root)
 * */

/* ----------------- facility methods ----------------- */
void assertNextRight(TreeLinkNode *root){
    if(!root)    return;

    queue<TreeLinkNode*> qArr[2];
    int idx = 0;
    qArr[idx].push(root);

    while(!qArr[idx].empty()){

        do{
            TreeLinkNode *curr = qArr[idx].front();

            qArr[idx].pop();

            if(qArr[idx].empty()){
                EXPECT_EQ(NULL, curr->next);
            }else{
                EXPECT_EQ(qArr[idx].front()->val, curr->next->val);
            }

            Solution::pushChildren(curr, qArr[1 - idx]);

        }while(!qArr[idx].empty());

        idx = 1 - idx;
    }
}

void delTree(TreeLinkNode *root){
    if(!root)    return;

    delTree(root->left);
    delTree(root->right);

    root->left = NULL;
    root->right = NULL;

    delete root;
    root = NULL;
}

/* -------------- test body --------------- */
TEST(populateNextRightTest, Positive01){
    Solution s;

    TreeLinkNode *root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->right = new TreeLinkNode(3);
    root->left->left = new TreeLinkNode(4);
    root->left->right = new TreeLinkNode(5);
    root->right->left = new TreeLinkNode(6);
    root->right->right = new TreeLinkNode(7);

    s.connect(root);

    assertNextRight(root);

    delTree(root);
}
