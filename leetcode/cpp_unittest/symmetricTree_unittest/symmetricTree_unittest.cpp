#include "symmetricTree.cpp"
#include "gtest/gtest.h"

/*
 * symmetricTree.cpp:
 * bool isSymmetric_01(TreeNode* root)
 * bool isSymmetric_02(TreeNode* root)
 * bool isSymmetric_03(TreeNode* root)
 *
 * preliminary.cpp:
 * struct TreeNode
 * delTree(TreeNode*)
 * */

/* ------------- solution 1 test cases ------------- */
TEST(symmetricTree01_Test, Positive01){
    Solution s;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    EXPECT_TRUE(s.isSymmetric_01(root));

    delTree(root);
}

TEST(symmetricTree01_Test, Positive02){
    Solution s;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    root->left->left->left = new TreeNode(5);
    root->left->left->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);
    root->right->left->right = new TreeNode(7);
    root->right->right->right = new TreeNode(5);
    root->right->right->right->left = new TreeNode(6);

    EXPECT_TRUE(s.isSymmetric_01(root));

    delTree(root);
}

TEST(symmetricTree01_Test, Negative01){
    Solution s;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    EXPECT_FALSE(s.isSymmetric_01(root));

    delTree(root);
}

/* ------------- solution 2 test cases ------------- */
TEST(symmetricTree02_Test, Positive01){
    Solution s;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    EXPECT_TRUE(s.isSymmetric_02(root));

    delTree(root);
}

TEST(symmetricTree02_Test, Positive02){
    Solution s;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    root->left->left->left = new TreeNode(5);
    root->left->left->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);
    root->right->left->right = new TreeNode(7);
    root->right->right->right = new TreeNode(5);
    root->right->right->right->left = new TreeNode(6);

    EXPECT_TRUE(s.isSymmetric_02(root));

    delTree(root);
}

TEST(symmetricTree02_Test, Negative01){
    Solution s;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);

    EXPECT_FALSE(s.isSymmetric_02(root));

    delTree(root);
}

/* ------------- solution 3 test cases ------------- */
TEST(symmetricTree03_Test, Positive01){
    Solution s;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    EXPECT_TRUE(s.isSymmetric_03(root));

    delTree(root);
}

TEST(symmetricTree03_Test, Positive02){
    Solution s;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    root->left->left->left = new TreeNode(5);
    root->left->left->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);
    root->right->left->right = new TreeNode(7);
    root->right->right->right = new TreeNode(5);
    root->right->right->right->left = new TreeNode(6);

    EXPECT_TRUE(s.isSymmetric_03(root));

    delTree(root);
}

TEST(symmetricTree03_Test, Negative01){
    Solution s;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    EXPECT_FALSE(s.isSymmetric_03(root));

    delTree(root);
}

