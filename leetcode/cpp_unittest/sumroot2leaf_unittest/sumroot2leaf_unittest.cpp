#include "sumroot2leaf.cpp"
#include "gtest/gtest.h"

/*
 * sumroot2leaf.cpp:
 * int sumNumbers(TreeNode* root)
 *
 * preliminary.cpp:
 * struct TreeNode
 * delTree(TreeNode*)
 * */

/* ------------- test body -------------- */
TEST(sumroot2leaf_Test, Positive01){
    Solution s;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    EXPECT_EQ(12 + 13, s.sumNumbers(root));

    delTree(root);
}

TEST(sumroot2leaf_Test, Positive02){
    Solution s;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(0);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    EXPECT_EQ(121 + 120 + 134 + 135, s.sumNumbers(root));

    delTree(root);
}
