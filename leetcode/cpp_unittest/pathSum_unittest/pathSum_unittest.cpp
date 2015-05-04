/*
 * bool hasPathSum(TreeNode *root, int sum)
 * vector<vector<int> > pathSum(TreeNode *root, int sum)
 * */

#include "pathSum.cpp"
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

void assertDuoList(vector<vector<int> >& expected, vector<vector<int> >& result){
    EXPECT_EQ(expected.size(), result.size());

    sort(expected.begin(), expected.end());
    sort(result.begin(), result.end());

    const int n = expected.size();
    for(int i = 0; i < n; i++){
        assertList(expected[i], result[i]);
    }
}

/*---------------------- test case ----------------------*/
TEST(pathSumTest, Positive01){
    Solution s;

    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(12);
    root->left->right = new TreeNode(11);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(17);

    int sum = 26;
    EXPECT_TRUE(s.hasPathSum(root, sum));

    delTree(root);
}

TEST(pathSumTest, Positive02){
    Solution s;

    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(12);

    int sum = 15;
    EXPECT_FALSE(s.hasPathSum(root, sum));

    delTree(root);
}

TEST(pathSumIITest, Positive01){
    Solution s;

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(1);
    root->left->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(3);
    root->right->right->right = new TreeNode(1);

    int sum = 15;

    int arr0[] = {5, 8, 1, 1};
    int arr1[] = {5, 8, 2};
    int arr2[] = {5, 3, 4, 3};
    int arr3[] = {5, 3, 7};

    vector<vector<int> > expected;
    expected.push_back(vector<int>(arr0, arr0 + sizeof(arr0) / sizeof(int)));
    expected.push_back(vector<int>(arr1, arr1 + sizeof(arr1) / sizeof(int)));
    expected.push_back(vector<int>(arr2, arr2 + sizeof(arr2) / sizeof(int)));
    expected.push_back(vector<int>(arr3, arr3 + sizeof(arr3) / sizeof(int)));

    vector<vector<int> > result = s.pathSum(root, sum);

    assertDuoList(expected, result);

    expected.clear();
    result.clear();
    delTree(root);
}

