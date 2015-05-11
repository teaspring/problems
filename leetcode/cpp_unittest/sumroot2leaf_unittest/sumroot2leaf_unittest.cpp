#include "sumroot2leaf.cpp"
#include "gtest/gtest.h"

/*
 * sumroot2leaf.cpp:
 * int sumNumbers_01(TreeNode* root)
 * int sumNumbers_02(TreeNode* root)
 *
 * preliminary.cpp:
 * struct TreeNode
 * delTree(TreeNode*)
 * */

/* ------------- test body -------------- */
TEST(sumroot2leaf01_Test, Positive01){
    Solution s;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    EXPECT_EQ(12 + 13, s.sumNumbers_01(root));

    delTree(root);
}

TEST(sumroot2leaf01_Test, Positive02){
    Solution s;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(0);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    EXPECT_EQ(121 + 120 + 134 + 135, s.sumNumbers_01(root));

    delTree(root);
}

TEST(sumroot2leaf01_Test, Positive03){
    Solution s;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);
    root->left->right->left->right = new TreeNode(8);
    root->right->left->right = new TreeNode(8);
    root->right->right->right = new TreeNode(9);

    EXPECT_EQ(1246 + 12578 + 1368 + 1379, s.sumNumbers_01(root));

    delTree(root);
}

TEST(sumroot2leaf02_Test, Positive01){
    Solution s;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    EXPECT_EQ(12 + 13, s.sumNumbers_02(root));

    delTree(root);
}

TEST(sumroot2leaf02_Test, Positive02){
    Solution s;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(0);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    EXPECT_EQ(121 + 120 + 134 + 135, s.sumNumbers_02(root));

    delTree(root);
}

TEST(sumroot2leaf02_Test, Positive03){
    Solution s;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);
    root->left->right->left->right = new TreeNode(8);
    root->right->left->right = new TreeNode(8);
    root->right->right->right = new TreeNode(9);

    EXPECT_EQ(1246 + 12578 + 1368 + 1379, s.sumNumbers_02(root));

    delTree(root);
}
