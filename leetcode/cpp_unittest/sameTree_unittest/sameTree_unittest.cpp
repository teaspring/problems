#include "sameTree.cpp"
#include "gtest/gtest.h"

/*
 * sameTree.cpp:
 * bool isSameTree(TreeNode* root1, TreeNode* root2)
 *
 * preliminary.cpp:
 * struct TreeNode
 * delTree(TreeNode*)
 * */

/* ------------- test body -------------- */
TEST(sameTree_Test, Positive01){
    Solution s;

    TreeNode *root1 = new TreeNode(15);
    root1->left = new TreeNode(10);
    root1->right = new TreeNode(20);
    root1->left->left = new TreeNode(5);
    root1->left->right = new TreeNode(7);
    root1->left->right->left = new TreeNode(2);
    root1->left->right->right = new TreeNode(5);
    root1->left->right->left->left = new TreeNode(0);
    root1->left->right->left->right = new TreeNode(6);
    root1->left->right->right->left = new TreeNode(3);

    TreeNode *root2 = new TreeNode(15);
    root2->left = new TreeNode(10);
    root2->right = new TreeNode(20);
    root2->left->left = new TreeNode(5);
    root2->left->right = new TreeNode(7);
    root2->left->right->left = new TreeNode(2);
    root2->left->right->right = new TreeNode(5);
    root2->left->right->left->left = new TreeNode(0);
    root2->left->right->left->right = new TreeNode(6);
    root2->left->right->right->left = new TreeNode(3);

    EXPECT_TRUE(s.isSameTree(root1, root2));

    delTree(root1);
    delTree(root2);
}

TEST(sameTree_Test, Negative01){
    Solution s;

    TreeNode *root1 = new TreeNode(15);
    root1->left = new TreeNode(10);
    root1->right = new TreeNode(20);
    root1->left->left = new TreeNode(5);
    root1->left->right = new TreeNode(7);
    root1->left->right->left = new TreeNode(2);
    root1->left->right->right = new TreeNode(-1);

    TreeNode *root2 = new TreeNode(15);
    root2->left = new TreeNode(10);
    root2->right = new TreeNode(20);
    root2->left->left = new TreeNode(5);
    root2->left->right = new TreeNode(7);
    root2->left->right->left = new TreeNode(2);

    EXPECT_FALSE(s.isSameTree(root1, root2));

    delTree(root1);
    delTree(root2);
}

TEST(sameTree_Test, Negative02){
    Solution s;

    TreeNode *root1 = new TreeNode(15);
    root1->left = new TreeNode(10);
    root1->right = new TreeNode(20);
    root1->left->left = new TreeNode(5);
    root1->left->right = new TreeNode(7);
    root1->left->right->left = new TreeNode(2);
    root1->left->right->right = new TreeNode(-1);

    TreeNode *root2 = new TreeNode(15);
    root2->left = new TreeNode(10);
    root2->right = new TreeNode(20);
    root2->left->left = new TreeNode(5);
    root2->left->right = new TreeNode(7);
    root2->left->right->left = new TreeNode(2);
    root1->left->right->right = new TreeNode(0);

    EXPECT_FALSE(s.isSameTree(root1, root2));

    delTree(root1);
    delTree(root2);
}
