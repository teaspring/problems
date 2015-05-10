#include "combinationsum.cpp"
#include "gtest/gtest.h"

/*
 * vector<vector<int> > Solution::combinationSum(vector<int> candidates, int target)
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

/*---------------------- test cases ----------------------*/
TEST(combinationsumTest, Positive01){
    Solution s;

    int target = 7;
    int arr[] = {2, 3, 7};
    vector<int> candidates(arr, arr + sizeof(arr) / sizeof(int));

    int opt1[] = {2, 2, 3};
    int opt2[] = {7};

    vector<vector<int> > expected;
    expected.push_back(vector<int>(opt1, opt1 + sizeof(opt1) / sizeof(int)));
    expected.push_back(vector<int>(opt2, opt2 + sizeof(opt2) / sizeof(int)));

    vector<vector<int> > result = s.combinationSum(candidates, target);

    sort(expected.begin(), expected.end());
    sort(result.begin(), result.end());

    assertDuoVector(expected, result);

    candidates.clear();
    expected.clear();
    result.clear();
}
