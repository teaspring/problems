/*
 * Solution::inOrderIterate(TreeNode* root)
 * */

#include "binaryTreeIterate.cpp"
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

void postorderIterate(TreeNode *root, vector<int>& output) {
    if(!root)    return;
    postorderIterate(root->left, output);
    postorderIterate(root->right, output);
    output.push_back(root->val);
}

void delTree(TreeNode* root) {
    if(!root)    return;
    delTree(root->left);
    delTree(root->right);
    delete root;
    root = NULL;
}

/*----------- test case of inOrderIterate() ------------*/
TEST(inOrderIterateTest, Positive01){
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

    Solution s;
    vector<int> result = s.inOrderIterate(root);

    assertList(expected, result);
    delTree(root);
}

TEST(inOrderIterateTest, Positive02){
    TreeNode *root = new TreeNode(12);
    root->left = new TreeNode(8);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(10);
    root->left->left->left = new TreeNode(1);

    vector<int> expected;
    inorderIterate(root, expected);

    Solution s;
    vector<int> result = s.inOrderIterate(root);

    assertList(expected, result);
    delTree(root);
}

TEST(inOrderIterateTest, Edge01){
    TreeNode *root = new TreeNode(1);

    Solution s;
    vector<int> res = s.inOrderIterate(root);
    EXPECT_EQ(1, res.size());
    EXPECT_EQ(1, res[0]);
}

TEST(inOrderIterateTest, Edge02){
    TreeNode *root = new TreeNode(12);
    root->right = new TreeNode(3);

    vector<int> expected;
    inorderIterate(root, expected);

    Solution s;
    vector<int> result = s.inOrderIterate(root);

    assertList(expected, result);
    delTree(root);
}

TEST(inOrderIterateTest, Edge03){
    TreeNode *root = new TreeNode(12);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);

    vector<int> expected;
    inorderIterate(root, expected);

    Solution s;
    vector<int> result = s.inOrderIterate(root);

    assertList(expected, result);
    delTree(root);
}

/*----------- test cases of postOrderIterate() --------------*/
TEST(postOrderIterateTest, Positive01){
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
    postorderIterate(root, expected);

    Solution s;
    vector<int> result = s.postOrderIterate(root);

    assertList(expected, result);
    delTree(root);
}

TEST(postOrderIterateTest, Positive02){
    TreeNode *root = new TreeNode(12);
    root->left = new TreeNode(8);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(10);
    root->left->left->left = new TreeNode(1);

    vector<int> expected;
    postorderIterate(root, expected);

    Solution s;
    vector<int> result = s.postOrderIterate(root);

    assertList(expected, result);
    delTree(root);
}

TEST(postOrderIterateTest, Edge01){
    TreeNode *root = new TreeNode(1);

    Solution s;
    vector<int> res = s.postOrderIterate(root);
    EXPECT_EQ(1, res.size());
    EXPECT_EQ(1, res[0]);
}

TEST(postOrderIterateTest, Edge02){
    TreeNode *root = new TreeNode(12);
    root->right = new TreeNode(3);

    vector<int> expected;
    postorderIterate(root, expected);

    Solution s;
    vector<int> result = s.postOrderIterate(root);

    assertList(expected, result);
    delTree(root);
}

TEST(postOrderIterateTest, Edge03){
    TreeNode *root = new TreeNode(12);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);

    vector<int> expected;
    postorderIterate(root, expected);

    Solution s;
    vector<int> result = s.postOrderIterate(root);

    assertList(expected, result);
    delTree(root);
}
