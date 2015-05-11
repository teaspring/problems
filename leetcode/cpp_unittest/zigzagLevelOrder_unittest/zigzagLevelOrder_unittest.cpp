#include "zigzagLevelOrder.cpp"
#include "gtest/gtest.h"

/*
 * zigzagLevelOrder.cpp:
 * vector<vector<int> > zigzagLevelOrder(TreeNode *root)
 * vector<vector<int> > levelOrder(TreeNode *root)
 *
 * preliminary.h:
 * struct TreeNode
 * delTree(TreeNode*)
 * */

void assertDuoVector(vector<vector<int> >& expected, vector<vector<int> >& result){
    EXPECT_EQ(expected.size(), result.size());
    const int n = expected.size();

    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i].size(), result[i].size());

        const int m = expected[i].size();

        for(int j = 0; j < m; j++){
            EXPECT_EQ(expected[i][j], result[i][j]);
        }
    }
}

/* ------------- zigzagLevelOrder() test cases ------------*/
TEST(zigzagLevelOrderTest, Positive01){
    Solution s;

    // result
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(11);
    root->right->left->right = new TreeNode(14);
    root->right->right->left = new TreeNode(16);

    vector<vector<int> > result = s.zigzagLevelOrder(root);

    // expected
    int arr0[] = {1};
    int arr1[] = {3, 2};
    int arr2[] = {4, 5, 6, 7};
    int arr3[] = {16, 14, 11, 10, 9};

    vector<vector<int> > expected;
    expected.push_back(vector<int>(arr0, arr0 + sizeof(arr0) / sizeof(int)));
    expected.push_back(vector<int>(arr1, arr1 + sizeof(arr1) / sizeof(int)));
    expected.push_back(vector<int>(arr2, arr2 + sizeof(arr2) / sizeof(int)));
    expected.push_back(vector<int>(arr3, arr3 + sizeof(arr3) / sizeof(int)));

    assertDuoVector(expected, result);

    delTree(root);;
    expected.clear();
    result.clear();
}

TEST(zigzagLevelOrderTest, Positive02){
    Solution s;

    // result
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->left->left = new TreeNode(6);
    root->right->left->right = new TreeNode(10);
    root->right->right->left = new TreeNode(9);
    root->right->right->right = new TreeNode(8);

    vector<vector<int> > result = s.zigzagLevelOrder(root);

    // expected
    int arr0[] = {1};
    int arr1[] = {3, 2};
    int arr2[] = {0, 4, 5, 7};
    int arr3[] = {8, 9, 10, 6};

    vector<vector<int> > expected;
    expected.push_back(vector<int>(arr0, arr0 + sizeof(arr0) / sizeof(int)));
    expected.push_back(vector<int>(arr1, arr1 + sizeof(arr1) / sizeof(int)));
    expected.push_back(vector<int>(arr2, arr2 + sizeof(arr2) / sizeof(int)));
    expected.push_back(vector<int>(arr3, arr3 + sizeof(arr3) / sizeof(int)));

    assertDuoVector(expected, result);

    delTree(root);;
    expected.clear();
    result.clear();
}

/* ------------- levelOrder() test cases ------------*/
TEST(levelOrderTest, Positive01){
    Solution s;

    // result
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(11);
    root->right->left->right = new TreeNode(14);
    root->right->right->left = new TreeNode(16);

    vector<vector<int> > result = s.levelOrder(root);

    // expected
    int arr0[] = {1};
    int arr1[] = {2, 3};
    int arr2[] = {4, 5, 6, 7};
    int arr3[] = {9, 10, 11, 14, 16};

    vector<vector<int> > expected;
    expected.push_back(vector<int>(arr0, arr0 + sizeof(arr0) / sizeof(int)));
    expected.push_back(vector<int>(arr1, arr1 + sizeof(arr1) / sizeof(int)));
    expected.push_back(vector<int>(arr2, arr2 + sizeof(arr2) / sizeof(int)));
    expected.push_back(vector<int>(arr3, arr3 + sizeof(arr3) / sizeof(int)));

    assertDuoVector(expected, result);

    delTree(root);;
    expected.clear();
    result.clear();
}

TEST(levelOrderTest, Positive02){
    Solution s;

    // result
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->left->left = new TreeNode(6);
    root->right->left->right = new TreeNode(10);
    root->right->right->left = new TreeNode(9);
    root->right->right->right = new TreeNode(8);

    vector<vector<int> > result = s.levelOrder(root);

    // expected
    int arr0[] = {1};
    int arr1[] = {2, 3};
    int arr2[] = {0, 4, 5, 7};
    int arr3[] = {6, 10, 9, 8};

    vector<vector<int> > expected;
    expected.push_back(vector<int>(arr0, arr0 + sizeof(arr0) / sizeof(int)));
    expected.push_back(vector<int>(arr1, arr1 + sizeof(arr1) / sizeof(int)));
    expected.push_back(vector<int>(arr2, arr2 + sizeof(arr2) / sizeof(int)));
    expected.push_back(vector<int>(arr3, arr3 + sizeof(arr3) / sizeof(int)));

    assertDuoVector(expected, result);

    delTree(root);;
    expected.clear();
    result.clear();
}
