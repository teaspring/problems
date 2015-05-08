#include "searchRange.cpp"
#include "gtest/gtest.h"

/*
 * vector<int> searchRange(A[], int n, int x)
 * */

void assertList(const vector<int>& expected, const vector<int>& result){
    EXPECT_EQ(expected.size(), result.size());

    const int n = expected.size();
    for(int i = 0; i < n; i++){
        EXPECT_EQ(expected[i], result[i]);
    }
}

/* --------------- test cases --------------- */
TEST(searchRangeTest, Positive01){
    Solution s;

    int arr[] = {1, 2, 2, 3, 4};

    const int n = sizeof(arr) / sizeof(int);

    int x = 2;

    vector<int> result = s.searchRange(arr, n, x);

    int exp[] = {1, 2};
    vector<int> expected(exp, exp + sizeof(exp)/sizeof(int));

    assertList(expected, result);

    expected.clear();
    result.clear();
}

TEST(searchRangeTest, Positive02){
    Solution s;

    int arr[] = {1, 1, 2, 2, 3, 4, 4, 4};

    const int n = sizeof(arr) / sizeof(int);

    int x = 4;

    vector<int> result = s.searchRange(arr, n, x);

    int exp[] = {5, 7};
    vector<int> expected(exp, exp + sizeof(exp)/sizeof(int));

    assertList(expected, result);

    expected.clear();
    result.clear();
}

TEST(searchRangeTest, Positive03){
    Solution s;

    int arr[] = {1, 1, 1, 2, 2, 3, 4};

    const int n = sizeof(arr) / sizeof(int);

    int x = 1;

    vector<int> result = s.searchRange(arr, n, x);

    int exp[] = {0, 2};
    vector<int> expected(exp, exp + sizeof(exp)/sizeof(int));

    assertList(expected, result);

    expected.clear();
    result.clear();
}

TEST(searchRangeTest, Negative01){
    Solution s;

    int arr[] = {1, 1, 1, 3, 3, 4};

    const int n = sizeof(arr) / sizeof(int);

    int x = 2;

    vector<int> result = s.searchRange(arr, n, x);

    int exp[] = {-1, -1};
    vector<int> expected(exp, exp + sizeof(exp)/sizeof(int));

    assertList(expected, result);

    expected.clear();
    result.clear();
}

TEST(searchRangeTest, Negative02){
    Solution s;

    int arr[] = {1, 1, 1, 3, 3, 4};

    const int n = sizeof(arr) / sizeof(int);

    int x = -1;

    vector<int> result = s.searchRange(arr, n, x);

    int exp[] = {-1, -1};
    vector<int> expected(exp, exp + sizeof(exp)/sizeof(int));

    assertList(expected, result);

    expected.clear();
    result.clear();
}

TEST(searchRangeTest, Negative3){
    Solution s;

    int arr[] = {1, 1, 1, 3, 3, 4};

    const int n = sizeof(arr) / sizeof(int);

    int x = 6;

    vector<int> result = s.searchRange(arr, n, x);

    int exp[] = {-1, -1};
    vector<int> expected(exp, exp + sizeof(exp)/sizeof(int));

    assertList(expected, result);

    expected.clear();
    result.clear();
}
