#include "balancedBT.cpp"
#include "gtest/gtest.h"

/* bool Solution::isBalanced(TreeNode *root) */

TEST(balancedBTTest, Positive){
    Solution s;

    TreeNode *head = new TreeNode(0);
    head->left = new TreeNode(1);
    head->right = new TreeNode(2);

    head->left->left = new TreeNode(3);

    EXPECT_TRUE(s.isBalanced(head));
}

TEST(balancedBTTest, Negative){
    Solution s;

    TreeNode *head = new TreeNode(0);
    head->left = new TreeNode(1);
    head->right = new TreeNode(2);

    head->left->left = new TreeNode(3);
    head->left->left->right = new TreeNode(4);

    EXPECT_FALSE(s.isBalanced(head));
}
