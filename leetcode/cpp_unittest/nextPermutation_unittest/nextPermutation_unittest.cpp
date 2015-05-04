#include "nextPermutation.cpp"
#include "gtest/gtest.h"

/*
 * void nextPermutation(vector<int>&)
 * */

void assertList(vector<int> &expected, vector<int> &result){
    EXPECT_EQ(expected.size(), result.size());

    const int n = expected.size();
    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i], result[i]);
    }
}

/* -------------- test body --------------- */
TEST(nextPermutationTest, Positive01){
    Solution s;

    const int rows = 6, cols = 3;
    int arr[][cols] = {
        {1, 2, 3},
        {1, 3, 2},
        {2, 1, 3},
        {2, 3, 1},
        {3, 1, 2},
        {3, 2, 1}};

    for(int i = 0; i < rows; i++){
        vector<int> num(arr[i], arr[i] + cols);
        s.nextPermutation(num);

        int j = (i+1) % rows;
        vector<int> expected(arr[j], arr[j] + cols);

        assertList(expected, num);

        expected.clear();
        num.clear();
    }
}

TEST(nextPermutationTest, Positive02){
    Solution s;

    const int rows = 24, cols = 4;
    int arr[][cols] = {
        {1, 2, 3, 4},
        {1, 2, 4, 3},
        {1, 3, 2, 4},
        {1, 3, 4, 2},
        {1, 4, 2, 3},
        {1, 4, 3, 2},
        {2, 1, 3, 4},
        {2, 1, 4, 3},
        {2, 3, 1, 4},
        {2, 3, 4, 1},
        {2, 4, 1, 3},
        {2, 4, 3, 1},
        {3, 1, 2, 4},
        {3, 1, 4, 2},
        {3, 2, 1, 4},
        {3, 2, 4, 1},
        {3, 4, 1, 2},
        {3, 4, 2, 1},
        {4, 1, 2, 3},
        {4, 1, 3, 2},
        {4, 2, 1, 3},
        {4, 2, 3, 1},
        {4, 3, 1, 2},
        {4, 3, 2, 1}};

    for(int i = 0; i < rows; i++){
        vector<int> num(arr[i], arr[i] + cols);
        s.nextPermutation(num);

        int j = (i+1) % rows;
        vector<int> expected(arr[j], arr[j] + cols);

        assertList(expected, num);

        expected.clear();
        num.clear();
    }
}
