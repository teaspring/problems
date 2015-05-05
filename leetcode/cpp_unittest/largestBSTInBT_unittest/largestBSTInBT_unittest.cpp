#include "largestBSTInBT.cpp"
#include "gtest/gtest.h"

/*
 * largestBSTInBT.cpp:
 * TreeNode* findLargestBST(TreeNode* root)
 *
 * preliminary.cpp:
 * struct TreeNode
 * delTree(TreeNode*)
 * */

// in-order iteration to assert two binary tree
void assertBinaryTree(TreeNode *p1, TreeNode *p2){
    if(!p1 || !p2){
        EXPECT_TRUE(!p1 && !p2);
        return;
    }

    EXPECT_EQ(p1->val, p2->val);
    assertBinaryTree(p1->left, p2->left);
    assertBinaryTree(p1->right, p2->right);
}

/* ------------- test body -------------- */
TEST(largestBSTInBT_Test, Positive01){
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

    TreeNode* result = s.findLargestBST(root);

    TreeNode *expected = new TreeNode(7);
    expected->left = new TreeNode(2);
    expected->left->left = new TreeNode(0);
    expected->left->right = new TreeNode(6);

    assertBinaryTree(expected, result);

    delTree(root);
    delTree(expected);
    delTree(result);
}
