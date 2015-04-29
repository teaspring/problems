#include "recoverBST.cpp"
#include "gtest/gtest.h"

/*
 * void recoverTree(TreeNode* root)
 * */

// simple iteration (pre-order) to assert whether BST remains correct
void assertBSTOrder(TreeNode *root){
    if(!root)    return;

    if(NULL != root->left){
        EXPECT_TRUE(root->left->val < root->val);
    }

    if(NULL != root->right){
        EXPECT_TRUE(root->right->val > root->val);
    }

    assertBSTOrder(root->left);
    assertBSTOrder(root->right);
}

// clean
void deleteBinaryTree(TreeNode* root){
    if(!root)    return;

    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);

    root->left = NULL;
    root->right = NULL;
    delete root;
    root = NULL;
}

/* ------------- test body -------------- */
TEST(recoverBST_Test, Positive01){
    Solution s;

    TreeNode *root = new TreeNode(15);
    root->left = new TreeNode(10);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(16);
    root->right->left = new TreeNode(17);
    root->right->right = new TreeNode(25);
    root->right->left->left = new TreeNode(12);

    s.recoverTree(root);

    assertBSTOrder(root);

    deleteBinaryTree(root);
}
