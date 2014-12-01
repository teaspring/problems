#include "sumtree.cpp"
#include "gtest/gtest.h"

// Test case: sumtreeTest
// Test name: negative
TEST(sumtreeTest, Negative){
    Solution s;
    TreeNode *h = new TreeNode(1);
    h->left = new TreeNode(2);
    h->left->right = new TreeNode(3);
    EXPECT_NO_THROW(s.convert2SumTree_I(h));
    EXPECT_EQ(5, h->val);
}

// Test case: sumtreeTest
// Test name: Positive
TEST(sumtreeTest, Positive){
    Solution s;
    TreeNode *h = new TreeNode(1);
    h->left = new TreeNode(2);
    h->right = new TreeNode(3);
    h->left->left = new TreeNode(4);
    h->left->right = new TreeNode(5);
    h->right->left = new TreeNode(6);
    h->right->right = new TreeNode(7);
    EXPECT_NO_THROW(s.convert2SumTree_I(h));
    EXPECT_EQ(27, h->val);
}
