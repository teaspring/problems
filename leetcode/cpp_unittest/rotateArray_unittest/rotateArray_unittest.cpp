#include "rotateArray.cpp"
#include "gtest/gtest.h"

/*
 * method to facilitate verification
 * */
void assertList(vector<int>& expected, vector<int>& result){
    EXPECT_EQ(expected.size(), result.size());

    const int n = expected.size();
    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i], result[i]);
    }
}

/*
 * void rotate(vector<int>&, int k)
 * */
TEST(rotateArrayTest, Positive01){
    Solution s;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};

    const int n = sizeof(arr) / sizeof(int);
    vector<int> nums(arr, arr + n);
    int k = 3;
    s.rotateArray(nums, k);

    int tmp[] = {6, 7, 8, 1, 2, 3, 4, 5};
    vector<int> expected(tmp, tmp + n);

    assertList(expected, nums);
    nums.clear();
    expected.clear();
}

