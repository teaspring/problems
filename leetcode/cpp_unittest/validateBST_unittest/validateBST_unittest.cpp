#include "validateBST.cpp"
#include "gtest/gtest.h"

/*
 * validateBST.cpp:
 * bool isValidBST(TreeNode* root)
 *
 * preliminary.cpp:
 * struct TreeNode
 * delTree(TreeNode*)
 * */

/* ------------- test body -------------- */
TEST(validateBST_Test, Positive01){
    Solution s;

    TreeNode *root = new TreeNode(15);
    root->left = new TreeNode(10);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(13);
    root->left->right->left = new TreeNode(11);
    root->right->left = new TreeNode(17);
    root->right->right = new TreeNode(25);
    root->right->left->right = new TreeNode(19);

    EXPECT_TRUE(s.isValidBST(root));

    delTree(root);
}

TEST(validateBST_Test, Negative01){
    Solution s;

    TreeNode *root = new TreeNode(15);
    root->left = new TreeNode(10);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(13);
    root->left->right->left = new TreeNode(11);
    root->right->left = new TreeNode(14);  // break BST
    root->right->right = new TreeNode(25);
    root->right->left->right = new TreeNode(19);

    EXPECT_FALSE(s.isValidBST(root));

    delTree(root);
}

TEST(validateBST_Test, Negative02){
    Solution s;

    TreeNode *root = new TreeNode(15);
    root->left = new TreeNode(10);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(16);  // break BST
    root->left->right->left = new TreeNode(11);
    root->right->left = new TreeNode(17);
    root->right->right = new TreeNode(25);
    root->right->left->right = new TreeNode(19);

    EXPECT_FALSE(s.isValidBST(root));

    delTree(root);
}

TEST(validateBST_Test, Negative03){
    Solution s;

    TreeNode *root = new TreeNode(15);
    root->left = new TreeNode(10);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(13);
    root->left->right->left = new TreeNode(11);
    root->right->left = new TreeNode(17);
    root->right->right = new TreeNode(25);
    root->right->left->right = new TreeNode(16);  // break BST

    EXPECT_FALSE(s.isValidBST(root));

    delTree(root);
}
