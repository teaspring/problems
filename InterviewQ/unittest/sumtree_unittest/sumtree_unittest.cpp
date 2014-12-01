#include "sumtree.cpp"
#include "gtest/gtest.h"

// Test case: sumtreeI_Test
// Test name: negative
TEST(sumtreeI_Test, Negative){
    Solution s;
    TreeNode *h = new TreeNode(1);
    h->left = new TreeNode(2);
    h->left->right = new TreeNode(3);
    EXPECT_NO_THROW(s.convert2SumTree_I(h));
    EXPECT_EQ(5, h->val);
}

// Test case: sumtreeI_Test
// Test name: Positive
TEST(sumtreeI_Test, Positive){
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

// Test case: sumtreeII_Test
// Test name: positive
TEST(sumtreeII_Test, Positive){
    Solution s;
    TreeNode *h = new TreeNode(1);
    h->left = new TreeNode(2);
    h->right = new TreeNode(3);
    h->left->left = new TreeNode(4);
    h->left->right = new TreeNode(5);
    h->right->left = new TreeNode(6);
    h->right->right = new TreeNode(7);
    
    EXPECT_NO_THROW(s.convert2SumTree_II(h));
    EXPECT_EQ(1, h->val);
    EXPECT_EQ(5, h->right->val);
    EXPECT_EQ(9, h->left->right->val);
    EXPECT_EQ(15, h->right->left->val);
    EXPECT_EQ(22, h->right->right->val);
}
