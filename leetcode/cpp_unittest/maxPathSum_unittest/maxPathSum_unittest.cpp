#include "maxPathSum.cpp"
#include "gtest/gtest.h"

/*
 * int maxPathSum_01(TreeNode *root)
 * int maxPathSum_02(TreeNode *root)
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
TEST(maxPathSum01_Test, Positive01){
    Solution s;

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(-2);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(-1);
    root->right->right = new TreeNode(2);
    root->right->left->right = new TreeNode(4);

    int expected = 8;

    EXPECT_EQ(expected, s.maxPathSum_01(root));

    deleteBinaryTree(root);
}

TEST(maxPathSum02_Test, Positive01){
    Solution s;

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(-2);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(-1);
    root->right->right = new TreeNode(2);
    root->right->left->right = new TreeNode(4);

    int expected = 8;

    EXPECT_EQ(expected, s.maxPathSum_02(root));

    deleteBinaryTree(root);
}
