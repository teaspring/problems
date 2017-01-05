#include "twoSum.cpp"
#include "gtest/gtest.h"

void expectIntegers(const vector<int>& expected, const vector<int>& result) {
    const int n = expected.size();
    EXPECT_EQ(n, result.size());
    for(int i = 0; i < n; ++i) {
        EXPECT_EQ(expected[i], result[i]);
    }
}

/*
 * vector<int> twoSum(vector<int>&, int)
 * */
TEST(twoSumTest, Positive_01){
    Solution s;

    int arr[] = {2, 7, 11, 15};
    const int n = sizeof(arr) / sizeof(int);
    vector<int> nums(arr, arr + n);

    int target = 9;
    vector<int> expected;
    expected.push_back(1);
    expected.push_back(2);
    EXPECT_EQ(expected, s.twoSum(nums, target));
    expected.clear();

    target = 22;
    expected.push_back(2);
    expected.push_back(4);
    EXPECT_EQ(expected, s.twoSum(nums, target));
    expected.clear();

    target = 18;
    expected.push_back(2);
    expected.push_back(3);
    EXPECT_EQ(expected, s.twoSum(nums, target));
    expected.clear();

    nums.clear();
}

TEST(twoSumTest, Positive_02){
    Solution s;

    int arr[] = {2, 4, 5, 8, 12, 17, 24};
    const int n = sizeof(arr) / sizeof(int);
    vector<int> nums(arr, arr + n);

    int target = 9;
    vector<int> expected;
    expected.push_back(2);
    expected.push_back(3);
    EXPECT_EQ(expected, s.twoSum(nums, target));
    expected.clear();

    target = 12;
    expected.push_back(2);
    expected.push_back(4);
    EXPECT_EQ(expected, s.twoSum(nums, target));
    expected.clear();

    target = 17;
    expected.push_back(3);
    expected.push_back(5);
    EXPECT_EQ(expected, s.twoSum(nums, target));
    expected.clear();

    target = 19;
    expected.push_back(1);
    expected.push_back(6);
    EXPECT_EQ(expected, s.twoSum(nums, target));
    expected.clear();

    target = 14;
    expected.push_back(1);
    expected.push_back(5);
    EXPECT_EQ(expected, s.twoSum(nums, target));
    expected.clear();

    target = 26;
    expected.push_back(1);
    expected.push_back(7);
    EXPECT_EQ(expected, s.twoSum(nums, target));
    expected.clear();

    target = 21;
    expected.push_back(2);
    expected.push_back(6);
    EXPECT_EQ(expected, s.twoSum(nums, target));
    expected.clear();

    target = 32;
    expected.push_back(4);
    expected.push_back(7);
    EXPECT_EQ(expected, s.twoSum(nums, target));
    expected.clear();

    nums.clear();
}
