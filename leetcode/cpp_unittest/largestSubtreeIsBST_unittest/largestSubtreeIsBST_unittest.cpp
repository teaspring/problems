#include "largestSubtreeIsBST.cpp"
#include "gtest/gtest.h"

/*
 * TreeNode* findLargestBSTSubtree(TreeNode* root)
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

// clean with post-order iteration
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
TEST(largestSubtreeIsBST_Test, Positive01){
    Solution s;

    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->left = new TreeNode(7);

    // NOTE: result is existing node from tree of root instead of new created, so it does not need delete
    TreeNode* result = s.findLargestBSTSubtree(root);

    TreeNode *expected = new TreeNode(5);
    expected->left = new TreeNode(1);
    expected->right = new TreeNode(8);

    assertBinaryTree(expected, result);

    result = NULL;
    deleteBinaryTree(root);
    deleteBinaryTree(expected);
}

TEST(largestSubtreeIsBST_Test, Positive02){
    Solution s;

    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);

    TreeNode* result = s.findLargestBSTSubtree(root);

    TreeNode *expected = new TreeNode(5);
    expected->left = new TreeNode(1);
    expected->right = new TreeNode(8);

    assertBinaryTree(expected, result);

    result = NULL;
    deleteBinaryTree(root);
    deleteBinaryTree(expected);
}

TEST(largestSubtreeIsBST_Test, Positive03){
    Solution s;

    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->right = new TreeNode(11);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(17);

    TreeNode* result = s.findLargestBSTSubtree(root);

    TreeNode *expected = new TreeNode(15);
    expected->left = new TreeNode(11);
    expected->right = new TreeNode(17);

    assertBinaryTree(expected, result);

    result = NULL;
    deleteBinaryTree(root);
    deleteBinaryTree(expected);
}

TEST(largestSubtreeIsBST_Test, Positive04){
    Solution s;

    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
	root->left->left = new TreeNode(12);
    root->left->right = new TreeNode(11);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(11);

    TreeNode* result = s.findLargestBSTSubtree(root);

    TreeNode *expected = new TreeNode(15);
    expected->left = new TreeNode(11);

    assertBinaryTree(expected, result);

    result = NULL;
    deleteBinaryTree(root);
    deleteBinaryTree(expected);
}
