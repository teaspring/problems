#include "maxminDepth.cpp"
#include "gtest/gtest.h"

/*
 * int maxDepth(TreeNode *root)
 * int minDepth(TreeNode *root)
 * */

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
TEST(maxminDepth_Test, Positive01){
    Solution s;

    TreeNode *root = new TreeNode(15);
    root->left = new TreeNode(10);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(7);
    root->left->right->left = new TreeNode(2);
    root->left->right->right = new TreeNode(5);
    root->left->right->left->left = new TreeNode(0);
    root->left->right->left->right = new TreeNode(6);
    root->left->right->right->left = new TreeNode(3);

    int expectedMax = 5;
    int expectedMin = 2;

    EXPECT_EQ(expectedMax, s.maxDepth(root));
    EXPECT_EQ(expectedMin, s.minDepth(root));

    deleteBinaryTree(root);
}
