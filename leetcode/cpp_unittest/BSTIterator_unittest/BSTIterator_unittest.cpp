/*
 * BSTIterator i = BSTIterator(root)
 * while(i.hasNext())    cout << i.next();
 * */

#include "BSTIterator.cpp"
#include "gtest/gtest.h"

/*
 * customized methods to facilitate test method
 * */
void assertList(vector<int>& expected, vector<int>& result){
    EXPECT_EQ(expected.size(), result.size());

    const int n = expected.size();
    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i], result[i]);
    }
}

void inorderIterate(TreeNode* root, vector<int>& output) {
    if(!root)    return;
    inorderIterate(root->left, output);
    output.push_back(root->val);
    inorderIterate(root->right, output);
}

void delTree(TreeNode* root) {
    if(!root)    return;
    delTree(root->left);
    delTree(root->right);
    delete root;
    root = NULL;
}

/*---------------------- test case ----------------------*/
TEST(BSTIteratorTest, Positive01){
    TreeNode *root = new TreeNode(12);
    root->left = new TreeNode(8);
    root->right = new TreeNode(16);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(10);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(18);
    root->left->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->left = new TreeNode(4);
    root->left->left->right->right = new TreeNode(6);

    vector<int> expected;
    inorderIterate(root, expected);

    vector<int> result;
    BSTIterator i = BSTIterator(root);
    while(i.hasNext()) {
        result.push_back(i.next());
    }

    assertList(expected, result);
    delTree(root);
}

TEST(BSTIteratorTest, Negative01){
    TreeNode *root = NULL;

    BSTIterator i = BSTIterator(root);
    EXPECT_FALSE(i.hasNext());
}

TEST(BSTIteratorTest, Edge01){
    TreeNode *root = new TreeNode(1);

    BSTIterator i = BSTIterator(root);
    EXPECT_EQ(1, i.next());
    EXPECT_FALSE(i.hasNext());
}
